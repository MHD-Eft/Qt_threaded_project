#include "manager.h"
#include <memory>

Manager::Manager(QObject *parent) : QObject(parent)
{

}

Manager::~Manager()
{
    quit();
}

void Manager::process()
{
    QFuture<void> value = QtConcurrent::run(Manager::createWorker,this);
}

void Manager::quit()
{
    qInfo() << "Stopping Manager";
    emit stop();
}

void Manager::createWorker(Manager *manager)
{
    qInfo() << "Creating Worker";
//    Worker* worker = new Worker();  // it's raw pointer!
    QSharedPointer<Worker> worker = QSharedPointer<Worker>::create();
    connect(manager,&Manager::start,worker.data(),&Worker::start,Qt::QueuedConnection);
    connect(manager,&Manager::stop,worker.data(),&Worker::stop,Qt::QueuedConnection);
    worker->start();
}

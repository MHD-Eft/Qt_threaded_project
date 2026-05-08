#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QtConcurrent>
#include <QDebug>
#include <QSharedPointer>
#include "worker.h"


class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();

signals:
    void start();
    void stop();


public slots:
    void process();
    void quit();

private:
static void createWorker(Manager* manager);
};

#endif // MANAGER_H

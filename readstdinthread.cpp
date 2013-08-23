#include "readstdinthread.h"
#include <QDebug>

#define MAX_BUFFER_LENGTH 1024*10

ReadStdinThread::ReadStdinThread(QObject *parent) :
    QThread(parent)
{
//    qDebug() << "start Read Stdin Thread ready!";
}

ReadStdinThread::~ReadStdinThread()
{
}

void ReadStdinThread::run()
{
    char buf[ MAX_BUFFER_LENGTH ];
    int length = 0;

    while((length = read( 0, buf,  MAX_BUFFER_LENGTH )) > 0 ) {
//        buf[length] = '\0';
//        qDebug() <<length ;
        QByteArray btyeArray(buf, length);

        emit sendLogMSG(btyeArray);
//        qDebug() << "after" << btyeArray;
    }
}

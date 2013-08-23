#ifndef READSTDINTHREAD_H
#define READSTDINTHREAD_H

#include <QThread>

class ReadStdinThread : public QThread
{
    Q_OBJECT
public:
    explicit ReadStdinThread(QObject *parent = 0);
    ~ReadStdinThread();
signals:
    void sendLogMSG(const QByteArray &log);

protected:
    void run();
};

#endif // READSTDINTHREAD_H

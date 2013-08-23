#include <QCoreApplication>
#include <QTextStream>
#include <QByteArray>
#include "forwardserver.h"
#include <QHostAddress>
#include <QNetworkInterface>

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ForwardServer server;

    if (!server.listen(QHostAddress::Any, 12345)) {
        qDebug() << QString("Unable to start the server: %1").arg(server.errorString());
        return 1;
    }


    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    if (ipAddress.isEmpty()){
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }

    qDebug() << QString("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Fortune Client example now.")
                         .arg(ipAddress).arg(server.serverPort());

    return a.exec();
}

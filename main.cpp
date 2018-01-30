
#include <QApplication>
#include <QOAuthHttpServerReplyHandler>
#include <QtNetwork>
#include "qauth2test.h"
#include <QVideoProbe>
#include <QMediaPlaylist>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Qauth2Test t;

    return a.exec();
}

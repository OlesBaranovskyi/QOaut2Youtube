#ifndef QTYOTUBECLIENT_H
#define QTYOTUBECLIENT_H
#include <QtNetworkAuth>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QFileDialog>

class QtYotubeClient:public QObject
{
    Q_OBJECT

public:
    QNetworkReply* reply;



    QOAuth2AuthorizationCodeFlow* google;
    QOAuthHttpServerReplyHandler* replyHandler;

    QtYotubeClient(QObject* parent = nullptr);

public slots:
 void slot_grant();

 void slot_get_rep_str();
 void slot_upload_video(QString path);
 void slot_error();
signals:

 //void signal_autificate_is_done();



};

#endif // QTYOTUBECLIENT_H

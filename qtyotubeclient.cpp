#include "qtyotubeclient.h"



QtYotubeClient::QtYotubeClient(QObject *parent):QObject(parent)
{

    google = new QOAuth2AuthorizationCodeFlow(this);
    replyHandler = new QOAuthHttpServerReplyHandler(8080,this);
    replyHandler->setCallbackPath("/cb");
    google->setReplyHandler(replyHandler);
    google->setClientIdentifier("Your ClientIdentifier");
    google->setClientIdentifierSharedKey("Your secret key");
    google->setAuthorizationUrl(QUrl("https://accounts.google.com/o/oauth2/auth"));
    google->setAccessTokenUrl(QUrl("https://accounts.google.com/o/oauth2/token"));
    google->setScope("https://www.googleapis.com/auth/youtube.upload https://www.googleapis.com/auth/youtube");

    google->grant();
    google->connect(google,&QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,&QDesktopServices::openUrl);


    qDebug()<<"acess token  is"<<google->accessTokenUrl()<<endl;
    qDebug()<<"authorization url "<<google->authorizationUrl()<<endl;
    qDebug()<<"state is"<<google->state()<<endl;
    //qDebug()<<"status is"<<google->status();
    qDebug()<<"My token"<<google->token()<<endl;
}



void QtYotubeClient::slot_grant()
{
    google->grant();
}



void QtYotubeClient::slot_get_rep_str()
{   qDebug()<<"My token is"<<google->token();
    qDebug()<<"reply is"<<endl;
    qDebug()<<reply->readAll();
}

void QtYotubeClient::slot_upload_video(QString path)
{   qDebug()<<"My token"<<google->token();
    QNetworkRequest req(QUrl("https://www.googleapis.com/upload/youtube/v3/videos?part=snippet"));
    const QString bearer_format = QStringLiteral("Bearer %1");
    req.setRawHeader("Authorization", bearer_format.arg(google->token()).toUtf8());

    auto multi_part = new QHttpMultiPart{ QHttpMultiPart::MixedType };
    auto video_part = new QHttpPart{};

   // qDebug()<<file_path;

    auto video = new QFile{ path };
       if (!video->open(QIODevice::ReadOnly))
       {
           qDebug() << "Error openning file";

       }

    video_part->setHeader(QNetworkRequest::ContentTypeHeader, QVariant("video/*"));
    video_part->setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("bronz"));
    video_part->setBodyDevice(video);
    multi_part->append(*video_part);

    reply = google->networkAccessManager()->post(req, multi_part);

    connect(reply,SIGNAL(finished()),this,SLOT(slot_get_rep_str()));

}

void QtYotubeClient::slot_error()
{
   qDebug()<<"certain error";
}

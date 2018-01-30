#include "qauth2test.h"

Qauth2Test::Qauth2Test(QWidget *parent) : QWidget(parent),clnt(parent)
{
this->resize(280,200);
    lay = new QHBoxLayout;
    vlay = new QVBoxLayout;

    button_choose_video = new QPushButton("&Choise Video",this);
    button_upload_video = new QPushButton("&Upload video",this);
    player = new QMediaPlayer(this);
    videoout = new QVideoWidget(this);
    videoout->show();
    videoout->resize(275,198);
    player->setVideoOutput(videoout);

    button_upload_video->setEnabled(false);
    lay->addWidget(button_choose_video);
    lay->addWidget(button_upload_video);

    vlay->addWidget(videoout);
    vlay->addLayout(lay);
    this->setLayout(vlay);

    connect(button_choose_video,SIGNAL(pressed()),this,SLOT(slot_choose_video()));
    connect(button_upload_video,SIGNAL(pressed()),this,SLOT(slot_upload_video()));
    this->clnt.google->grant();
    connect(clnt.google,SIGNAL(granted()),this,SLOT(show()));

}

void Qauth2Test::slot_upload_video()
{

this->clnt.slot_upload_video(str_file_path);
}

void Qauth2Test::slot_choose_video()
{
    QString files("*.mov *.mpeg4 *.mp4 *.avi *.wmv *.mpegps *.flv *.3gpp *.webm *.MOV *.MPEG4 *.MP4 *.AVI *.WMV *.MPEGPS *.FLV *.3GPP *.WEBM");
    str_file_path=QFileDialog::getOpenFileName(0,"Open file","",files);

    if(str_file_path.size())
   { qDebug()<<str_file_path;
       button_upload_video->setEnabled(true);
       player->setMedia(QUrl::fromLocalFile(str_file_path));
       player->setVolume(10);
       player->play();
   }

}

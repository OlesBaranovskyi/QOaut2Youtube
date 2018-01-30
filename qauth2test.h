#ifndef QAUTH2TEST_H
#define QAUTH2TEST_H

#include <QWidget>
#include <QPushButton>
#include<qlayout.h>
#include"qtyotubeclient.h"
#include <QMediaPlayer>
#include <QVideoWidget>

class Qauth2Test : public QWidget
{
    Q_OBJECT
    QPushButton* button_choose_video;
    QPushButton* button_upload_video;
    QMediaPlayer* player;
    QVideoWidget* videoout;



    QString str_file_path;

    QHBoxLayout* lay;
    QVBoxLayout* vlay;

    QtYotubeClient clnt;

public:
    explicit Qauth2Test(QWidget *parent = nullptr);

signals:

public slots:
    void slot_upload_video();
    void slot_choose_video();

};

#endif // QAUTH2TEST_H

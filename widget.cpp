#include "widget.h"
#include "ui_widget.h"

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
    mVideoWidget = new QVideoWidget(this);
    mMediaPlayer->setVideoOutput(mVideoWidget);

    auto L = static_cast<QVBoxLayout *>(layout());
    L->insertWidget(0,mVideoWidget);

    connect(mMediaPlayer, &QMediaPlayer::positionChanged, [&](qint64 pos){
        ui->avanceProgressBar->setValue(pos);
    });
    connect(mMediaPlayer, &QMediaPlayer::durationChanged,[&](qint64 duracion){
        ui->avanceProgressBar->setMaximum(duracion);

    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_abrirPushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Abrir");
    if(fileName.isEmpty()){
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(fileName));
    mMediaPlayer->setVolume(ui->volumenHorizontalSlider->value());
    on_playPushButton_clicked();
}

void Widget::on_playPushButton_clicked()
{
    mMediaPlayer->play();
}

void Widget::on_pausePushButton_clicked()
{
    mMediaPlayer->pause();
}

void Widget::on_stopPushButton_clicked()
{
    mMediaPlayer->stop();
}

void Widget::on_mutePushButton_clicked()
{
    if(ui->mutePushButton->text() == "Mute"){
        mMediaPlayer->setMuted(true);
        ui->mutePushButton->setText("Unmute");
    }else{
        mMediaPlayer->setMuted(false);
        ui->mutePushButton->setText("Mute");
    }

}

void Widget::on_volumenHorizontalSlider_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}

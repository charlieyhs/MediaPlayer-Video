#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }

class QMediaPlayer;
class QVideoWidget;

QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_abrirPushButton_clicked();
    void on_playPushButton_clicked();
    void on_pausePushButton_clicked();
    void on_stopPushButton_clicked();
    void on_mutePushButton_clicked();
    void on_volumenHorizontalSlider_valueChanged(int value);

private:
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
    QVideoWidget *mVideoWidget;
};
#endif // WIDGET_H

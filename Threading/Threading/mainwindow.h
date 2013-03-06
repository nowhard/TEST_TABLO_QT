#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "com_thread.h"
#include <abstractserial.h>
#include <QDebug>
#include <QTimer>
#include "serial_io.h"
#include "proto_uso.h"

#include "dialog_com.h"
#include "ui_dialog_com.h"
#include "delegate.h"
#include <QTextCodec>
#include <QStringList>
#include <QCheckBox>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QIODevice>
#include <QSettings>
#include <QVector>
#include <QPointF>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:


private:

    Ui::MainWindow *ui;

    //---------------------
    AbstractSerial *port;
   // Serial_IO *srl_io;

    proto_uso *p_uso;
    //---------------------

    //---------------------
    QTimer *timer;


    //---------------------
    Dialog_com com_dlg;

    bool read_flag;

    QByteArray TabloFrame;//здесь формируем кадр табло
    quint8 num;//счетчик 0-9 текущего числа
    bool blink;//флаг-пора мигать
    QByteArray  indicator_list;
    unsigned char  hyst_counter,point_counter_3,point_counter_4,point_counter_5;
    bool hyst_napr;
    unsigned char  brightness;
    unsigned char  hyst_blink_counter;
    unsigned char  ust_form;

    quint8 INDICATORS;
    quint8 FRAME_LEN;//	134

quint8 UST_1;//	0x0
quint8	UST_2;//	0x1F

quint8 UST_FORM1;// 0
quint8 UST_FORM2;//; 1

quint8 HYST_MAX;// 32

quint8 BLINKING;//	12

private slots:

    void on_horizontalSlider_2_actionTriggered(int action);

    void on_pushButton_3_clicked();
    void on_action_COM_triggered();

    void on_pushButton_clicked();


    void Send_To_Tablo(void);


};




#endif // MAINWINDOW_H

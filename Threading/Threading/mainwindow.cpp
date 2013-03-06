#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    port=new AbstractSerial(this);
    port->setTotalReadConstantTimeout(0);

    timer=new QTimer();

    p_uso=new proto_uso(this,port);
     QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));

    const char  lst[20]={3,3,3,3,3,3,3,3,5,0,4,3,4,32,32,32,32,0,32,32};
    indicator_list.append(lst,20);
    num=0x30;
    INDICATORS=20;

    FRAME_LEN=	134;

    UST_1=0x0;
    UST_2=0x1F;

    UST_FORM1=0;
    UST_FORM2=1;

    HYST_MAX=32;

    BLINKING=12;

    hyst_counter=0;
    point_counter_3=1;
    point_counter_4=1;
    point_counter_5=1;
    hyst_napr=0;
    brightness=0xF;
    hyst_blink_counter=0;
    ust_form=0;

   connect(timer,SIGNAL(timeout()),this,SLOT(Send_To_Tablo()));



     read_flag=false;

}

MainWindow::~MainWindow()
{

    port->close();
    delete port;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   if(!port->isOpen())
    {
    port->setDeviceName(com_dlg.ui->comboBox->currentText());


    if ( !port->open(AbstractSerial::ReadWrite | AbstractSerial::Unbuffered) ) {
        qDebug() << "Serial device by default: " << port->deviceName() << " open fail.";
        ui->statusBar->showMessage("Port Open Fail");
        return;
    }
    if (!port->setBaudRate(AbstractSerial::BaudRate57600/*com_dlg.ui->comboBox_2->currentText()*/)) {
        qDebug() << "Set baud rate  error.";
        return;
    };

    if (!port->setDataBits(AbstractSerial::DataBits8)) {
        qDebug() << "Set data bits " <<  AbstractSerial::DataBits8 << " error.";
        return;
    }
    if (!port->setParity(AbstractSerial::ParityNone)) {
        qDebug() << "Set parity " <<  AbstractSerial::ParityNone << " error.";
        return;
    }

   if(com_dlg.ui->radioButton->isChecked())
    {
        if (!port->setStopBits(AbstractSerial::StopBits1)) {
            qDebug() << "Set stop bits " <<  AbstractSerial::StopBits1 << " error.";
            return;
        }
    }
   else
   {
       if (!port->setStopBits(AbstractSerial::StopBits2)) {
           qDebug() << "Set stop bits " <<  AbstractSerial::StopBits2 << " error.";
           return;
       }
   }

    if (!port->setFlowControl(AbstractSerial::FlowControlOff)) {
        qDebug() << "Set flow " <<  AbstractSerial::FlowControlOff << " error.";
        return;
    }

    if (port->openMode() & AbstractSerial::Unbuffered)
        port->setTotalReadConstantTimeout(10);

     //port->setCharIntervalTimeout(int((8*1000000/com_dlg.ui->comboBox_2->currentText().toInt())));

    ui->pushButton->setText(tr("Отключить"));

     timer->start(ui->horizontalSlider_2->value());

     qDebug() << "Serial device : " << port->deviceName() << " opened!!!.";
     qDebug() << "Serial device baudrate : " << port->baudRate() ;
     qDebug() << "Serial device databits : " << port->dataBits() ;
     qDebug() << "Serial device stopbits : " << port->stopBits() ;
     qDebug() << "Serial device flowcontrol : " << port->flowControl() ;


 }
else
   {
        port->close();
        ui->pushButton->setText(tr("Подключить"));
\
         timer->stop();
    }
}


void MainWindow::on_action_COM_triggered()
{
    com_dlg.show();
}

/*void MainWindow::MessageReadOK(bool mess)
{
    if(mess)
    {
       ui->statusBar->showMessage("Device Read OK");
       //Get_All_Data();
    }
    else
    {
       ui->statusBar->showMessage("Device Read Error");
    }
}*/





void MainWindow::on_pushButton_3_clicked()
{
   // p_uso->GET_DEV_INFO_REQ(ui->comboBox_5->currentText().toInt());
}



void MainWindow::Send_To_Tablo(void)
{
    quint8 i=0,j=0;
    TabloFrame.clear();
    TabloFrame.append(':');
     TabloFrame.append('X');//сюда вставим длину
    for(i=0;i<INDICATORS;i++)
    {
            switch(indicator_list[i])
            {
                    case 3:
                    {
                                    TabloFrame.append('[');
                                    TabloFrame.append(i);


                                    for(j=0;j<=indicator_list[i];j++)
                                    {
                                                    if(j==point_counter_3)
                                                    {
                                                            //buf[j]=0x2E;//'.'
                                                            TabloFrame.append(0x2E);
                                                    }
                                                    else
                                                    {
                                                            //buf[j]=num;
                                                            TabloFrame.append(num);
                                                    }

                                    }

                                    TabloFrame.append(']');
                    }
                    break;

                    case 4:
                    {
                                    TabloFrame.append('[');

                                    TabloFrame.append(i);

                                    for(j=0;j<=indicator_list[i];j++)
                                    {
                                                    if(j==point_counter_4)
                                                    {
                                                            //buf[j]=0x2E;//'.'
                                                            TabloFrame.append(0x2E);
                                                    }
                                                    else
                                                    {
                                                            //buf[j]=num;
                                                            TabloFrame.append(num);
                                                    }
                                    }

                                    TabloFrame.append(']');
                    }
                    break;

                    case 5:
                    {
                                    TabloFrame.append('[');

                                    TabloFrame.append(i);


                                    for(j=0;j<=indicator_list[i];j++)
                                    {
                                                    if(j==point_counter_5)
                                                    {
                                                            TabloFrame.append(0x2E);
                                                    }
                                                    else
                                                    {
                                                            TabloFrame.append(num);
                                                    }
                                    }

                                    TabloFrame.append(']');
                    }
                    break;

                    case 32:
                    {
                                    TabloFrame.append('[');


                                    if(i!=INDICATORS-1)
                                    {
                                            TabloFrame.append(i);

                                            TabloFrame.append(ust_form);

                                            TabloFrame.append(hyst_counter);

                                            TabloFrame.append(UST_1);


                                            TabloFrame.append(UST_2);

                                    }
                                    else
                                    {
                                            TabloFrame.append(i);

                                            TabloFrame.append(ust_form);

                                            TabloFrame.append(hyst_counter);

                                            TabloFrame.append(UST_1);

                                            TabloFrame.append(UST_2-1);
                                    }

                                    TabloFrame.append(']');
                    }
                    break;

                    default:
                    {
                    }
                    break;
            }
    }
//-------------------------------
//	 index+=sprintf(&buffer[index],"[*%c]",brightness);

    TabloFrame.append('[');


    TabloFrame.append('*');


    TabloFrame.append(/*brightness*/(quint8)ui->horizontalSlider->value());


    TabloFrame.append(']');

    TabloFrame[1]=TabloFrame.length()-2;




    if(ui->comboBox->currentIndex()==0)//выбор протокола
    {
        p_uso->WriteFrame(TabloFrame);
    }
    else
    {
         TabloFrame.append(0x1);//канал управления звуком
         TabloFrame.append(0x41);
         TabloFrame.append((char)0x0);
      //   TabloFrame[1]=TabloFrame.length()-2;
         p_uso->SEND_NEW_TABLO_FRAME(TabloFrame);
    }

//------------------------------
//    if(proto_type==0x1)
//    {
////		index+=sprintf(&buffer[index],"\x1\x41%c",beep_type);

//            TabloFrame.append(0x1);

//            TabloFrame.append(0x41);

//            TabloFrame.append(beep_type);


////------------------------------

////            buffer[8]=index-12;
////            buffer[5]=index-5;//
////            buffer[10]=index-14;
////            TabloFrame.append(CRC_Check(&buffer[1],index-1);
////            index++;
//    }
//    else
//    {
//            buffer[1]=index-2;	 //???
//    }

//         index_buf=index;

//             SBUF = buffer[0];


     point_counter_3++;
     point_counter_4++;
     point_counter_5++;

     if(point_counter_3>3)
                    point_counter_3=1;

     if(point_counter_4>4)
                    point_counter_4=1;

     if(point_counter_5>5)
                    point_counter_5=1;

     num++;
     if(num>0x39)//9->0
            num=0x30;


if(hyst_blink_counter==0)//
{
    if(!hyst_napr)
            hyst_counter++;
    else
            hyst_counter--;

    if(hyst_counter>=HYST_MAX)
    {
            hyst_napr=1;
            hyst_blink_counter=BLINKING;
    }
    if(hyst_counter==0)
    {
            hyst_napr=0;
    }
}
else
{
    hyst_blink_counter--;
    ust_form=~ust_form;//
}

    return;
}






void MainWindow::on_horizontalSlider_2_actionTriggered(int action)
{
    timer->setInterval(ui->horizontalSlider_2->value());
}

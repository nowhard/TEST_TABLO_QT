#include "proto_uso.h"

proto_uso::proto_uso(QObject *parent,AbstractSerial *port) :
    QObject(parent)
{
    this->port=port;

    in_thread=new Input_Thread(this,port);
    out_thread=new Output_Thread(this,port);

    in_thread->start();
    out_thread->start();

    connect(in_thread,SIGNAL(isRead(QByteArray)),this,SLOT(ResponseHandling(QByteArray)));
    connect(this,SIGNAL(WriteToOut_Thread(QByteArray)),out_thread,SLOT(Send(QByteArray)));


    timer=new QTimer(this);
    DEV=new DEVICE();
    connect(timer,SIGNAL(timeout()),this,SIGNAL(DEVICE_NOT_CONNECTED()));
}

proto_uso::~proto_uso()//����������
{
    //in_thread->quit();

    in_thread->exit();
    delete in_thread;

    //out_thread->quit();
    out_thread->exit();
    delete out_thread;
    delete timer;
}

void proto_uso::GET_DEV_INFO_REQ(qint8 dev_addr)//������ �� ��������� ���������� �� ����������
{
  //  QString debug;

    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//��������� �����
    request.append(dev_addr);
    request.append(GET_DEV_INFO_REQ_);
    request.append(0x1);
    CRC=CRC8(request,request.length());
    request.append(CRC);

    emit this->WriteToOut_Thread(request);

    return;
}

void proto_uso::GET_DEV_INFO_RESP(QByteArray response)//���������� ���������� ���������� �� ����������
{
    quint8 len;
float cal_high;
long cal;

union
{
    quint32 res;
    float result;
};

   if(response.length()<=5)
    {
       qDebug("NOT ACCEPTED!!!");
       return;//��������
    }

    len=response[5];//������� ����� ���������� �����

    qDebug()<< response.toHex();

    emit DEV_INFO_RESPONSED(response);
    qDebug("ACCEPTED!!! %i",DEV->channel_num );


    res=(((quint32)(response.data()[7]&0xff)<<16  |(response.data()[6]&0xff)<<24|(response.data()[9]&0xff) |(response.data()[8]&0xff)<<8 ));


   // qDebug()<<result;
    return;
}

void  proto_uso::CHANNEL_SET_PARAMETERS_REQ(QByteArray settings)//���������� ��������� �������
{
    quint8 CRC;
    CRC=CRC8(settings,settings.length());
    settings.append(CRC);
    emit this->WriteToOut_Thread(settings);
    qDebug()<<settings.toHex();
    return;
}

void proto_uso::CHANNEL_ALL_GET_DATA_REQ(qint8 dev_addr)//������ ���������� �� ���� �������
{
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//��������� �����
    request.append(dev_addr);
    request.append(CHANNEL_ALL_GET_DATA_REQ_);
    request.append(0x1);
    CRC=CRC8(request,request.length());
    request.append(CRC);

     emit this->WriteToOut_Thread(request);
     qDebug("DATA REQUESTED!!!");
    return;
}

void proto_uso::CHANNEL_ALL_GET_DATA_RESP(QByteArray response)//����� �� ������ ������ ���������� �� ���� �������
{

    return;
}

void   proto_uso::CHANNEL_SET_ADDRESS_DESC(quint8 dev_addr,quint8 new_addr,QString dev_name,QByteArray version, QString description)//���������� �����, ���, ��������, � �.�.
{

    return;
}

void proto_uso::REQUEST_ERROR(QByteArray response)//����� ���������� ������, ��������� ��� �������� ������, ������ � �.�.
{
    qDebug("ERROR !!!");
    return;
}

void proto_uso::ResponseHandling(QByteArray response)
{
    quint8 CRC,trueCRC;
    timer->stop();
    //------�������� ���
    trueCRC=CRC8(response,response.length()-1);
    CRC=response[response.length()-1];
qDebug("RESPONSED!!!");

    if(trueCRC!=CRC)
        return;//���������, ���� �������� ������ �������� ������
    //------------------
    switch(response[4])
    {
        case GET_DEV_INFO_RESP_:
        {
            GET_DEV_INFO_RESP(response);
            //qDebug()<< "OLOLO";
        }
        break;

        case CHANNEL_ALL_GET_DATA_RESP_:
        {
            CHANNEL_ALL_GET_DATA_RESP(response);
        }
        break;

        case REQUEST_ERROR_:
        {
            REQUEST_ERROR(response);
        }
        break;
    }

    return;
}

quint8 proto_uso::CRC8(QByteArray data,quint8 len)//CRC8 ��� ���������
{
    quint8   CRC = 0;
    quint8   data_pntr=0;
        while(len)
        {
            CRC = CRC ^ (data[data_pntr]);//Spool[i];
            data_pntr++;
            CRC = ((CRC & 0x01) ? (unsigned char)0x80: (unsigned char)0x00) | (unsigned char)(CRC >> 1);

        if (CRC & (unsigned char)0x80) CRC = CRC ^ (unsigned char)0x3C;
                len--;
        }
    return CRC;
}

void DEVICE::Init_Channels(quint8 num_chn)//������� ������ ��� �������
{
    for(quint8 i=0;i<num_chn;i++)
        channel_mas.append(new CHANNEL());

    return;
}

void proto_uso::CHANNEL_SET_CALIBRATE(quint8 dev_addr,quint8 channel, char point,unsigned long num)//������ �� ���������� ��������-���������
{

}

void proto_uso::CHANNEL_SET_CALIBRATE(quint8 dev_addr,quint8 channel, char mode,float K, float C)//������ �� ���������� ��������-���������
{

}

void proto_uso::WriteFrame(QByteArray frame)
{
     emit this->WriteToOut_Thread(frame);
}


void proto_uso::SEND_NEW_TABLO_FRAME(QByteArray frame)//������� ���� ������ ��������� �����
{
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//��������� �����
    request.append(/*dev_addr*/0xF);//����� ����� �� ���������
    request.append(CHANNEL_SET_PARAMETERS_REQ_);

    request.append('X');//���� ������� ����� ���������� �����

    request.append((char)0x0);
    request.append((char)0x8F);

    request.append(frame.length()-3);
    request.append(frame);
    request[5]=request.length()-5;


    CRC=CRC8(request,request.length());
    request.append(CRC);

     emit this->WriteToOut_Thread(request);
     qDebug("DATA REQUESTED!!!");
    return;
}

#include "game.h"
#include "ui_game.h"
#include <qdebug.h>
#include <ctime>
#include <QtGlobal>

#include "startwidget.h"
game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    this->setWindowTitle("game");
    number[0]=ui->pushButton;
    number[1]=ui->pushButton_2;
    number[2]=ui->pushButton_3;
    number[3]=ui->pushButton_4;
    number[4]=ui->pushButton_5;
    number[5]=ui->pushButton_6;
    number[6]=ui->pushButton_7;
    number[7]=ui->pushButton_8;
    number[8]=ui->pushButton_9;
    number[9]=ui->pushButton_10;
    number[10]=ui->pushButton_11;
    number[11]=ui->pushButton_12;
    number[12]=ui->pushButton_13;
    number[13]=ui->pushButton_14;

    txt[0]=ui->label;
    txt[1]=ui->label_2;
    txt[2]=ui->label_3;
    txt[3]=ui->label_4;
    txt[4]=ui->label_5;
    txt[5]=ui->label_6;
    txt[6]=ui->label_7;
    txt[7]=ui->label_8;
    txt[8]=ui->label_9;
    txt[9]=ui->label_10;
    txt[10]=ui->label_11;
    txt[11]=ui->label_12;
    txt[12]=ui->label_13;
    txt[13]=ui->label_14;


    connect(number[0],&QPushButton::released, this ,game::so1);
    connect(number[1],&QPushButton::released, this ,game::so2);
    connect(number[2],&QPushButton::released, this ,game::so3);
    connect(number[3],&QPushButton::released, this ,game::so4);
    connect(number[4],&QPushButton::released, this ,game::so5);
    connect(number[5],&QPushButton::released, this ,game::so6);
    connect(number[6],&QPushButton::released, this ,game::so7);
    connect(number[7],&QPushButton::released, this ,game::so8);
    connect(number[8],&QPushButton::released, this ,game::so9);
    connect(number[9],&QPushButton::released, this ,game::so10);
    connect(number[10],&QPushButton::released, this ,game::so11);
    connect(number[11],&QPushButton::released, this ,game::so12);
    connect(number[12],&QPushButton::released, this ,game::so13);
    connect(number[13],&QPushButton::released, this ,game::so14);

    ui->next1->setEnabled(false);
    ui->select->setEnabled(false);
    ui->tr->setEnabled(false);
    ui->over->setEnabled(false);
    star();     //确定人数n
    shenf();    //发身份，初始化idengtity（身份，红0，黑1）和 hp（是否存活，是1，否0）数组

    now=0;          //now：正在发言人位置
    selectspeak();//竞选村长，发言环节，从1-n顺序发言；int now为当前发言人位置




}
void game::getn(){          //获取spinbox的值，赋给n
    int j;
    n=ui->spinBox->value();


    for(j=14;j>n;j--){
        txt[j-1]->setText("无"); //将超出n的位置显示为“无”
    }
    ui->tr->setEnabled(true);
    ui->ok->setEnabled(false);



}
void game::star(){                      //确认游戏人数
    ui->tips->setText("选择人数");
    connect(ui->ok,&QPushButton::released, this,&game::getn);
    ui->tips->setText("发身份");

}

game::~game()
{
    delete ui;
}
void game::startid(){       //发身份 ,无论奇偶，黑=n/2
        int x,i,black=1;	//black计数
        for(i=0;i<n;i++){
            identity[i]=0;
            hp[i]=1;
        }
        qsrand(time(NULL));
        for(i=0;;i++){
            x=qrand()%n;
            if(identity[x]==0){
                identity[x]=1;
                black++;
            }
            if(black>n/2)break;
        }
        for(i=0;i<n;i++){
            hp[i]=1;
        }
        for(i=0;i<n;i++){	//检验：输出1-n的身份
            if(identity[i]==1)qDebug()<<i+1<<"black"<<"    ";
            else qDebug()<<i+1<<"red"<<"    ";
        }
        ui->tr->setEnabled(false);
        ui->next1->setEnabled(true);
}

void game::shenf(){         //发身份

    connect(ui->tr,&QPushButton::released,this ,&game::startid);
    ui->tips->setText("村长选举发言");
}

void game::selectspeak2(){
    if(now==1){
        txt[now-1]->setText("正在发言");
    }
    else{
        if(now==n+1){
            txt[now-2]->setText("发言完毕");
        }
        else{
            txt[now-2]->setText("发言完毕");
            txt[now-1]->setText("正在发言");
        }
    }
}
void game::selectspeak1(){
     now++;
     if(now<=n+1){
         selectspeak2();
     }
     else {
         ui->next1->setEnabled(false);
         ui->over->setEnabled(true);
         connect(ui->over,&QPushButton::released, this, game::selectleader);


     }
}

void game::selectspeak(){   //村长选举发言
        connect(ui->next1,&QPushButton::released, this, game::selectspeak1);
}

/*void game::so(int m,int ye){    //m被投票人，ye投票人
    if(ye!==leader){
        stk[i]++;
    }
    else{

    }
}*/
void game::so1(){
    stk[0]++;
}

void game::so2(){
    stk[1]++;
}
void game::so3(){
    stk[2]++;
}
void game::so4(){
    stk[3]++;
}
void game::so5(){
    stk[4]++;
}
void game::so6(){
    stk[5]++;
}
void game::so7(){
    stk[6]++;
}
void game::so8(){
    stk[7]++;
}
void game::so9(){
    stk[8]++;
}
void game::so10(){
    stk[9]++;
}
void game::so11(){
    stk[10]++;
}
void game::so12(){
    stk[11]++;
}
void game::so13(){
    stk[12]++;
}
void game::so14(){
    stk[13]++;
}
void game::eve(){

}

void game::pick(){
    int i;
    for(i=0;i<n;i++){
        if(hp[i]==1){
            number[i]->setEnabled(true);

        }
    }

        connect(number[0],&QPushButton::released, this ,game::so1);
        connect(number[1],&QPushButton::released, this ,game::so2);
        connect(number[2],&QPushButton::released, this ,game::so3);
        connect(number[3],&QPushButton::released, this ,game::so4);
        connect(number[4],&QPushButton::released, this ,game::so5);
        connect(number[5],&QPushButton::released, this ,game::so6);
        connect(number[6],&QPushButton::released, this ,game::so7);
        connect(number[7],&QPushButton::released, this ,game::so8);
        connect(number[8],&QPushButton::released, this ,game::so9);
        connect(number[9],&QPushButton::released, this ,game::so10);
        connect(number[10],&QPushButton::released, this ,game::so11);
        connect(number[11],&QPushButton::released, this ,game::so12);
        connect(number[12],&QPushButton::released, this ,game::so13);
        connect(number[13],&QPushButton::released, this ,game::so14);

    ui->select->setEnabled(true);
    for(i=0;i<n;i++){
        if(hp[i]==1){
            number[i]->setEnabled(false);

        }
    }
}

void game::selectleader2(){

    ui->select->setEnabled(false);
    qDebug()<<now;
    if(now==1){
        txt[now-1]->setText("正在投票");
        pick();
    }
    else{
        if(now==n+1){
            txt[now-2]->setText("投票完毕");
        }
        else{
            txt[now-2]->setText("投票完毕");
            txt[now-1]->setText("正在投票");
            pick();
        }
    }
}

void game::selectleader1(){
    now++;
    if(now<n+1){
        selectleader2();
    }
    else{
        ui->select->setEnabled(false);
        ui->over->setEnabled(true);
        connect(ui->over,&QPushButton::released, this, game::eve);
    }
}
void game::selectleader(){          //村长选举投票

    ui->tips->setText("村长选举投票");
    ui->over->setEnabled(false);
    ui->select->setEnabled(true);
    int i;
    for(i=0;i<n;i++){           //改变label的内容
        txt[i]->setText("等待");
        stk[i]=0;               //初始化stk票数数组
    }
    now=0;
    connect(ui->select,&QPushButton::released, this,game::selectleader1);

                            //记录投票




}
    /*int stk[20];	//每人投票

    for(i=0;i<n;i++){
        if(hp[i]==1){
            cout<<i+1<<"号玩家请投票:";
            cin>>stk[i];
        }
        else cout<<i+1<<"号玩家已出局。"<<endl;
    }
    leader=selectleader(stk,n);
    cout<<leader+1<<"号玩家被选为村长"<<endl;

    int sti[20];		//统计票数
    int i,j;
    for(i=0;i<n;i++){
        cin>>stk[i];
        for(j=0;j<n;j++){
            if(stk[i]==j)sti[j]++;
        }
    }
    int max=sti[0];
    leader=0;
    for(i=1;i<n;i++){
        if(sti[i]>max){
            leader=i;
        }
    }

}*/




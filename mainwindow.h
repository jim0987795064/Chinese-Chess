#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QPushButton>
#include<QPixmap>
#include<QObject>
#include<QPainter>
#include<QImage>
#include<QDebug>
#include <QtGlobal>
#include<QString>
#include<QThread>
class MainWindow : public QMainWindow
{
Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	void paintEvent(QPaintEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void SetValue(int,QString);
	void ComputerMove();
private:
	int x,y,j=0,k=0,number,number2,back,seed,seed2,seed3,rightone,x1[32],y1[32],value[32]={0},selected[32]={0},exist[32]={0},count[32]={0},count2=0,count3,count4=0;
	//int exist[32]={0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
	int noteat=(-1);//15
	QVector<int> set;
	qreal w1,z1;
	time_t t1,t2;
	QThread stop;
	bool ing,round=false,round2=false,eat=false,initial=false,readyeat=false,readymove=false,finish=true;
	QPainter painter,background;
   	QImage image2,image3,image4;
	QString self=" ",computer=" ",turn="initial";	
	QString value2[32]={" "};//,image[32]={"./black1.png","./red2.png","./black3.png"};
	QVector<QString> death[2];
	QVector<int> position[32],move[32];
	QString image5[32]={" "},image[32]={"./black1.png","./black2.png","./black2.png","./black3.png","./black3.png","./black4.png","./black4.png","./black5.png","./black5.png","./black6.png","./black6.png","./black7.png","./black7.png","./black7.png","./black7.png","./black7.png","./red1.png","./red2.png","./red2.png","./red3.png","./red3.png","./red4.png","./red4.png","./red5.png","./red5.png","./red6.png","./red6.png","./red7.png","./red7.png","./red7.png","./red7.png","./red7.png"};

};
#endif



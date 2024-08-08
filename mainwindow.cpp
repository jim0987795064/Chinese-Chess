#include "mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include<QImage>
#include<QPointF>
#include<QColor>
#include<QObject>
#include<QPushButton>
#include<QtMath>
#include<QTime>
#include<QVector>
#include<QLabel>
#include<ctime>
#include<unistd.h>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
setMouseTracking(true);
setFixedSize(800, 600);
ing=false;
for(int i=0;i<32;i++)
        {
                x1[i]=j;
                y1[i]=k;
                k+=50;
		if(k==200)
		{
			k=0;
			j+=50;
		}
        }
	qsrand(QTime::currentTime().msec());
	while(count2<32)
	{
		seed=qrand()%32;
		if(count[seed]==0)	
		{
			set.push_back(seed);
			count[seed]=1;
			count2++;
		}
	}
	for(int i=0;i<32;i++)
	{
		
	image5[i]=image[set.at(i)];
	SetValue(i,image5[i]);
	}
	death[0].push_back("black");
	death[1].push_back("red");
	
}





void MainWindow::mousePressEvent(QMouseEvent *event)
{
round=false;
count3=0;
//if(turn==computer)
//return;
if((exist[(((event->x())/50)*4)+((event->y())/50)]==2&&ing==false)||turn==computer||(event->x()>=400)||(event->y()>=200))
return;




if((event->x()<=400)&&(event->y()<=200))
{
//rightone=(((event->x())/50)*4)+((event->y())/50);
//if(value2[rightone]==computer&&exist[rightone]==1&&event->button()==Qt::RightButton)
	//return;
if(event->button()==Qt::LeftButton&&ing==false)
{

number=(((event->x())/50)*4)+((event->y())/50);
	//image4.load(image[set.front()]);
	//set.pop_front();
x=x1[number];
y=y1[number];
if(exist[number]==0)
{
	exist[number]++;
	//noteat++;
	turn=computer;
	round=true;
}

//update();
}


if(ing==true&&event->button()==Qt::LeftButton)
{

number=(((event->x())/50)*4)+((event->y())/50);
if(value[back]==2)
{
if(((((number/4)==(back/4))&&((number-back==1)||(number-back==(-1))))||((number-back==4)||(number-back==(-4))))&&exist[number]==2&&eat==false)	
{ing=false;
z1=event->x();
w1=event->y();
x=qFloor(z1);
y=qFloor(w1);
x/=50;
y/=50;
x*=50;
y*=50;
//image[number]=image[back];
//image[back]=" ";
image5[number]=image5[back];
image5[back]=" ";
value[number]=value[back];
value[back]=0;
value2[number]=value2[back];
value2[back]=" ";
exist[back]=2;
exist[number]=1;
selected[back]=0;
turn=computer;
t2=time(NULL);
round=true;
//noteat++;
qDebug()<<"3";
//image3.load(image[number]);
//update();
}
else if((value2[back]!=value2[number])&&(exist[number]==1))//&&(value[back]>=value[number]))//player firepow
{
if(((number-back)==3||(number-back)==2)&&((number/4)==(back/4)))
{
	for(int i=back+1;i<number;i++)
		if(exist[i]!=2)
			count3++;
}
if(((number-back)==(-2)||(number-back)==(-3))&&((number/4)==(back/4)))
{
        for(int i=back-1;i>number;i--)
                if(exist[i]!=2)
                        count3++;
}
if((number-back)>=8&&(number-back)%4==0)
{
        for(int i=back+4;i<number;i+=4)
                if(exist[i]!=2)
                        count3++;
}
if((number-back)<=(-8)&&(-(number-back))%4==0)
{
        for(int i=back-4;i>number;i-=4)
                if(exist[i]!=2)
                        count3++;
}
if(count3==1)
                {
                if(value2[number]=="black")	
			death[0].push_back(image5[number]);
		else
			death[1].push_back(image5[number]);
		//image[number]=image[back];
                //image[back]=" ";
                
		image5[number]=image5[back];
                image5[back]=" ";

                //image5[number]="  ";
		value[number]=value[back];
                value[back]=0;
                value2[number]=value2[back];
                value2[back]=" ";
                exist[back]=2;
                selected[back]=0;
                selected[number]=1;//new
		//ing=false;
		back=number;
		eat=true;
		//noteat=0;
		//turn=computer;
		}

}
}
else if((((number/4)==(back/4))&&((number-back==1)||(number-back==(-1))))||(number-back==4)||(number-back==(-4)))		
{
	//selected[back]=0;
	if(exist[number]==1&&value2[back]!=value2[number])
	{	
		if(value[back]>=value[number]&&(value[back]-value[number]!=6))
		{	
		if(value2[number]=="black")
			death[0].push_back(image5[number]);
		else
			death[1].push_back(image5[number]);
		//image[number]=image[back];
		//image[back]=" ";
		
		image5[number]=image5[back];
		image5[back]=" ";
		
		//image5[number]=" ";
		value[number]=value[back];
		value[back]=0;
		value2[number]=value2[back];
		value2[back]=" ";
		exist[back]=2;
		selected[back]=0;
		selected[number]=1;//new

		//ing=false;
		back=number;
		eat=true;
		//noteat=0;
		//turn=computer;
		
		}
		else if(value[back]==1&&value[number]==7)
		{
		 if(value2[number]=="black")
			 death[0].push_back(image5[number]);
                else
			death[1].push_back(image5[number]);
		//image[number]=image[back];
		//image[back]=" ";
		
		image5[number]=image5[back];
		image5[back]=" ";
		
		//image5[number]=" ";
		value[number]=value[back];
                value[back]=0;
                value2[number]=value2[back];
                value2[back]=" ";
		exist[back]=2;
		selected[back]=0;
		selected[number]=1;//new
		//ing=false;
		back=number;
		eat=true;
		//noteat=0;
		//turn=computer;
		}
	}
	if(exist[number]==2&&eat==false)
{
ing=false;
z1=event->x();
w1=event->y();
x=qFloor(z1);
y=qFloor(w1);
x/=50;
y/=50;
x*=50;
y*=50;
image5[number]=image5[back];
image5[back]=" ";
value[number]=value[back];
value[back]=0;
value2[number]=value2[back];
value2[back]=" ";
exist[back]=2;
exist[number]=1;
selected[back]=0;
turn=computer;
round=true;
t2=time(NULL);
//noteat++;

//image3.load(image[number]);
//update();

}
}
}
if(event->button()==Qt::RightButton&&ing==true&&exist[back]==1)
{
x=x1[back];
y=y1[back];
selected[back]=0;//
//selceted[number]=0;//if single click leftbutton
 //image5[number]=image5[back];
 //image5[back]=" ";
if(eat==true)
{
	turn=computer;
	t2=time(NULL);
}

eat=false;
ing=false;
//update();
}
}
update();
return;
}


void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
if(((event->x()<=400)&&(event->y()<=200))&&turn==self)
{
	if(ing==false)
		number=((event->x())/50)*4+(event->y())/50;
	if(event->button()==Qt::LeftButton&&ing==false&&exist[number]==1&&value2[number]==self)
	{
	t1=time(NULL);
	back=number;
	selected[number]=1;
	//image3.load(image[set.at(number)]);
	image3.load(image5[number]);
	ing=true;
	update();
	}
}
return;
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
if(ing==true)
{
x=event->x();
y=event->y();
update();
}
return;
}


void MainWindow::ComputerMove()
{

        number2=50,count3=0,count4=0,round2=false,readyeat=false,readymove=false,finish=true;//count3 is ok or not,ready put here is ok?
		//many position to set every member can eat enemy
		//if move or eat enemy,clear original position and reset new position	
		//must not to record the same data again.to do this we can judge by deatharray's size or previousmove or opennewone
        for(int i=0;i<32;i++)//ready to eat part
        {
        if(exist[i]==1&&value2[i]==computer)
                {
			if(exist[i+1]==2&&(i+1)<32&&((i+1)/4==(i/4)))
			{
				readymove=true;
				move[i].push_back(i+1);
			}
			if(exist[i-1]==2&&(i-1)>(-1)&&((i-1)/4==(i/4)))
			{
				readymove=true;
				move[i].push_back(i-1);
			}
			if(exist[i+4]==2&&(i+4)<32)
			{
				readymove=true;
				move[i].push_back(i+4);
			}
			if(exist[i-4]==2&&(i-4)>(-1))
			{
				readymove=true;
				move[i].push_back(i-4);
			}
                        qDebug()<<"bright i:"<<i<<endl;
                        count4++;
                        if(value[i]!=2)//eat enemy except firepow
			{
                                if((exist[i-4]==1)&&(value[i-4]<=value[i]||((value[i]==1)&&value[i-4]==7))&&(value2[i-4]!=value2[i])&&(((value[i]-value[i-4])!=6))&&((i-4)>(-1))
)
				{
				readyeat=true;
				position[i].push_back(i-4);
				}
				if((exist[i+4]==1)&&(value[i+4]<=value[i]||((value[i]==1)&&value[i+4]==7))&&(value2[i+4]!=value2[i])&&(((value[i]-value[i+4])!=6))&&((i+4)<32)
)
				{
				readyeat=true;
				position[i].push_back(i+4);
				}
				if((exist[i-1]==1)&&(value[i-1]<=value[i]||((value[i]==1)&&value[i-1]==7))&&(value2[i-1]!=value2[i])&&((i-1)/4)==(i/4)&&(((value[i]-value[i-1])!=6))&&((i-1)>(-1)))
				{
				readyeat=true;
				position[i].push_back(i-1);
				}
				if((exist[i+1]==1)&&(value[i+1]<=value[i]||((value[i]==1)&&value[i+1]==7))&&(value2[i+1]!=value2[i])&&((i+1)/4)==(i/4)&&(((value[i]-value[i+1])!=6))&&((i+1)<32))
                        	{
                                readyeat=true;
                                position[i].push_back(i+1);
                        	}
                        }
                        else//fire pow to decide can eat ori cannot eat
                        {
                                if((value2[i-2]!=value2[i])&&((i/4)==((i-2)/4))&&((i-2)>(-1))&&(exist[i-2]==1))
                                        {
						readyeat=true;
                                		position[i].push_back(i-2);
					}
				if((value2[i+2]!=value2[i])&&((i/4)==((i+2)/4))&&((i+2)<32)&&(exist[i+2]==1))
					{
						readyeat=true;
                                		position[i].push_back(i+2);
					}
                                if((value2[i-3]!=value2[i])&&((i/4)==((i-3)/4))&&((i-3)>(-1))&&(exist[i-3]==1))
					{
						readyeat=true;
                                		position[i].push_back(i-3);
					}
                                if((value2[i+3]!=value2[i])&&((i/4)==((i+3)/4))&&((i+3)<32)&&(exist[i+3]==1))
                                	{
						readyeat=true;
                                		position[i].push_back(i+3);
					}
				for(int j=i-8;j>=0;j-=4)//j - to negative is ok?
					if((exist[j]==1)&&(value2[j]!=value2[i]))//value[j]==1 means j is red7 or black7,to join blackeat set exist[j]==1||exist[j]==0
					{
						for(int k=i-4;k>j;k-=4)
						if((exist[k]==1)||(exist[k]==0))
								count3++;
						if(count3==1&&j>(-1))
						{
							readyeat=true;
							position[i].push_back(j);
							break;//ok? or j=0;
						}
						count3=0;
					}
				for(int j=i+8;j<=31;j+=4)//j - to negative is ok?
                                        if((exist[j]==1)&&(value2[j]!=value2[i]))//to join blackeat set exist[j]==1||exist[j]==0
                                        {
                                        	for(int k=i+4;k<j;k+=4)
                                                	if((exist[k]==1)||exist[k]==0)
                                                        	count3++;
                                                if(count3==1&&j<32)                
						{
							readyeat=true;
							position[i].push_back(j);
							break;
						}
						count3=0;
                                        }
				}
					
                        

                }

        }

	for(int i=0;i<32;i++)
        if((position[i].size()!=0||move[i].size()!=0)&&value2[i]==computer)
        {
                qDebug()<<i<<"  eat: "<<"  move:";
                for(int j=0;j<position[i].size();j++)
                        qDebug()<<"     "<<position[i].at(j);
                for(int k=0;k<move[i].size();k++)
                        qDebug()<<"             "<<move[i].at(k);
                        qDebug()<<endl;
        }



	
	while(finish)
	{
		seed2=qrand()%5;
		if(seed2==0&&(count4==0||(readymove==false&&readyeat==false)))//open new one
	{
		do{
			seed=qrand()%32;
			//qDebug()<<seed2;
		}while(exist[seed]!=0);
	{
		qDebug()<<"new one :"<<seed;
		exist[seed]=1;
	}
		//noteat++;
		finish=false;
		round2=true;
	}
	//else//eat or move for all
	//{
		//while(finish)
		//{
		//seed2=qrand()%2;
		if((seed2==1||seed2==2)&&readyeat==true)
		{
			do
			{
				seed=qrand()%32;
			}while(exist[seed]!=1||value2[seed]!=computer||position[seed].size()==0);
			qDebug()<<"ready to eat:"<<seed;
			seed3=qrand()%position[seed].size();
		  	number2=position[seed].at(seed3);//select can eat member from positon
			qDebug()<<"eaten:"<<number2;
			if(value2[number2]=="black")
				death[0].push_back(image5[number2]);
			else
				death[1].push_back(image5[number2]);
			value[number2]=value[seed];
			value2[number2]=value2[seed];
			value[seed]=0;
			value2[seed]=" ";
			exist[seed]=2;
			image5[number2]=image5[seed];
			image5[seed]=" ";
			//noteat=0;
			qDebug()<<"  ate:"<<number2;
			finish=false;

		}
		if((seed2==3||seed2==4)&&readymove==true)
		{
			do
			{
				seed=qrand()%32;
			}while(exist[seed]!=1||value2[seed]!=computer||move[seed].size()==0);
			qDebug()<<"ready to move:"<<seed;
			seed3=qrand()%move[seed].size();
			number2=move[seed].at(seed3);
			qDebug()<<"moven:"<<number2;
			value[number2]=value[seed];
			value2[number2]=value2[seed];
			value[seed]=0;
			value2[seed]=" ";
			exist[number2]=1;
			exist[seed]=2;
			image5[number2]=image5[seed];
			image5[seed]=" ";
			//noteat++;
			qDebug()<<"  moved:"<<number2;
			finish=false;
			round2=true;
		}
		//}
	//}
	}
	 //qDebug()<<"computerturn:"<<computer<<endl<<endl;

	/*for(int i=0;i<32;i++)
	if((position[i].size()!=0||move[i].size()!=0)&&value2[i]==computer)
	{	
		qDebug()<<i<<"  eat: "<<"  move:";
		for(int j=0;j<position[i].size();j++)
			qDebug()<<"     "<<position[i].at(j);
		for(int k=0;k<move[i].size();k++)
			qDebug()<<"             "<<move[i].at(k);
			qDebug()<<endl;
	}*/
	for(int i=0;i<32;i++)
	{
		position[i].clear();
		move[i].clear();
	}
	qDebug()<<"count4:"<<count4<<"     readyeat:"<<readyeat<<"    readymove:"<<readymove;
       	turn=self;
	update();	
	return;
}






void MainWindow::paintEvent(QPaintEvent *event) {
QPainter painter(this);
QPainter background(this);
const QPointF points2[20]={QPointF(50,0),QPointF(50,200),QPointF(100,0),QPointF(100,200),QPointF(150,1),QPointF(150,200),QPointF(200,1),QPointF(200,200),QPointF(250,1),QPointF(250,200)
			   ,QPointF(300,1),QPointF(300,200),QPointF(350,1),QPointF(350,200),QPointF(1,50),QPointF(400,50),QPointF(1,100),QPointF(400,100),QPointF(1,150),QPointF(400,150)};

QPen pen(Qt::black,3);
background.setPen(pen);
background.setBrush(QColor(255,153,18,90));
background.drawRect(1,1,400,200);
//background.drawLine(50, 50, 100,100);
background.drawLines(points2,10);

for(int i=0;i<32;i++)
{
if(exist[i]==0)
{
	image2.load("./back.png");
	painter.drawImage(x1[i],y1[i],image2);
}
}
for(int i=0;i<32;i++)
{
if(exist[i]==1&&selected[i]==0)
{
	//image4.load(image[set.at(i)]);
        //set.pop_front();
	//image4.load(image[i]);
	image2.load(image5[i]);
	painter.drawImage(x1[i],y1[i],image2);
	if(initial==false)
	{
        self=value2[number];
	if(self=="black")
		computer="red";
	else
		computer="black";
        initial=true;
	turn=computer;
	qDebug()<<"123:"<<turn<<"  "<<computer;
	}
	//SetValue(i,image[set.at(i)]);
	//set.pop_front();
}
}
if(ing==true)
painter.drawImage(x,y,image3);



/*if(death[0].size()==17)
{
turn=self;
if(death[0].at(16)==self)
painter.drawText(500,500,"Computer wins.");
else
painter.drawText(500,500,"Player wins");
}
else if(death[1].size()==17)
{
turn=self;
if(death[1].at(16)==self)
painter.drawText(500,500,"Computer wins.");
else
painter.drawText(500,500,"Player wins");
}
else if(turn==computer)
{
	stop.sleep(2);
	ComputerMove();
}*/


if(ing==false)//cout information
{
	for(int i=0;i<32;i++)
		qDebug()<<i<<"  "<<exist[i]<<" "<<selected[i]<<" "<<image5[i]<<" "<<value[i]<<" "<<value2[i];
}
if(ing==false)	
qDebug()<<"number:"<<number<<" back:"<<back<<" eat:"<<eat<<" self:"<<self<<" computer:"<<computer<<" turn:"<<turn;//<<" not eat count"<<noteat;



j=500,k=0;//to deal with deathmember
for(int i=0;i<(death[0].size());i++)//-1 or not
	{
		image2.load(death[0].at(i));
		painter.drawImage(j,k,image2);
		k+=50;
		if(k==400)
		{
		j+=50;
		k=0;
		}
	}
j=600,k=0;
for(int i=0;i<(death[1].size());i++)
	{
		image2.load(death[1].at(i));
		painter.drawImage(j,k,image2);
		k+=50;
		if(k==400)
		{
		j+=50;
		k=0;
		}
	}

//update();
if(death[0].size()==17)
{
turn=self;
if(death[0].at(16)==self)
painter.drawText(500,500,"Computer wins.");
else
painter.drawText(500,500,"Player wins");
}
else if(death[1].size()==17)
{
turn=self;
if(death[1].at(16)==self)
painter.drawText(300,500,"Computer wins.");
else
painter.drawText(300,500,"Player wins");
}
else if(turn==computer)
       ComputerMove();
if(round==true&&round2==true)
	noteat++;
else
	noteat=0;

qDebug()<<"noteat"<<noteat/2<<"   round2"<<round2<<"   round"<<round<<"  time:"<<t2-t1;
if((t2-t1)>=15)
{
	turn="  ";
	painter.drawText(300,500,"You lose");
}
return;
}









void MainWindow::SetValue(int i,QString str)
{

if(str=="./black1.png")
	{
		value[i]=7;
		value2[i]="black";
	}

if(str=="./black2.png")
        {
                value[i]=6;
                value2[i]="black";
        }
if(str=="./black3.png")
        {
                value[i]=5;
                value2[i]="black";
        }
if(str=="./black4.png")
        {
                value[i]=4;
                value2[i]="black";
        }
if(str=="./black5.png")
        {
                value[i]=3;
                value2[i]="black";
        }
if(str=="./black6.png")
        {
                value[i]=2;
                value2[i]="black";
        }
if(str=="./black7.png")
        {
                value[i]=1;
                value2[i]="black";
        }
if(str=="./red1.png")
        {
                value[i]=7;
                value2[i]="red";
        }
if(str=="./red2.png")
        {
                value[i]=6;
                value2[i]="red";
        }
if(str=="./red3.png")
        {
                value[i]=5;
                value2[i]="red";
        }
if(str=="./red4.png")
        {
                value[i]=4;
                value2[i]="red";
        }
if(str=="./red5.png")
        {
                value[i]=3;
                value2[i]="red";
        }
if(str=="./red6.png")
        {
                value[i]=2;
                value2[i]="red";
        }
if(str=="./red7.png")
        {
                value[i]=1;
                value2[i]="red";
        }
return;
}





//item->setFlag(QGraphicsItem::ItemIsSelectable);
//item->setFlag(QGraphicsItem::ItemIsMovable);
//pixmap.load("./black1.png");
//item->setPixmap(pixmap);
//item->setPos(10,10);
//this->addItem(item);
//view.show();


/*this->scene=new QGraphicsScene();
item=new QGraphicsPixmapItem();
scene->setSceneRect(0,0,500,500);
view.setScene(scene);
pixmap.load("./back.png");
item->setPixmap(pixmap);
item->setPos(0,0);
scene->addItem(item);
//QObject::connect(button,SIGNAL(clicked()),this,SLOT(change()));
view.show();
*/


/*void a::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
if(event->button()==Qt::LeftButton)
{
item->setPos(20,20);
}
}*/


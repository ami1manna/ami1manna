
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
  int scoreply,scorecmp,counter=400;
class rps{
int you ,p[20],c[20];
int randomnum;
public:

void changeimg(){
int m=5;
while(m!=0){
  readimagefile("rock1.jpeg",3,3,247,247);
  delay(100);
  readimagefile("scissor1.jpeg",3,3,247,247);
  delay(50);

  readimagefile("paper1.jpeg",3,3,247,247);
delay(100);
m--;
}}
    void Yourenterednumber(int y){
        you=y;}
          void compnumber(){
        srand(time(0));
      for(;;){
      randomnum=rand()%10;
      if((randomnum<4)&&(randomnum>0)){

       break;
        }

      }

    }
    void obj(){


      if(randomnum==1){
            cout<<"Rock"<<endl;

 readimagefile("rock1.jpeg",3,3,247,247);

	  }
	  else if(randomnum==2){
            cout<<"paper"<<endl;
 //readimagefile("paper1.jpeg",3,3,247,247);}
    }
      else{
            cout<<"Scissor"<<endl;
  readimagefile("scissor1.jpeg",3,3,247,247);
 }
}
    void scoreboard(){
        settextstyle(8, 0, 5);
        setfillstyle(8,RED);
    char s[50];
    int x=getmaxx(),y=getmaxy();

    sprintf(s,"SCORES:\nYOUR SCORE=%d||\nCOMPUTER SCORE=%d||",scoreply,scorecmp);

    outtextxy(50,400,s);
    if(scoreply>scorecmp){
        outtextxy(500,600,"you winned");
        readimagefile("victory.jpeg",300,400,600,700);
    }
    else if(scoreply==scorecmp){
        outtextxy(500,600,"DRAW");
    }
    else{outtextxy(500,600,"you lose");
   readimagefile("defeat.jpeg",300,400,600,700);
    settextstyle(3,0,3);
    outtextxy(750,700,"GAME OVER");
    }
    }


void score(){
       settextstyle(8, 0, 2);
    counter+=40;
   if((you==1)&&(randomnum==2)||(you==2)&&(randomnum==3)||(you==3)&&(randomnum==1)){

outtextxy(0,counter,"computer=1");outtextxy(150,counter,"player=0");
scorecmp++;
}
   else if((randomnum==1)&&(you==2)||(randomnum==2)&&(you==3)||(randomnum==3)&&(you==1)){
scoreply++;
outtextxy(0,counter,"computer=0");outtextxy(150,counter,"player=1");
}
      else{
outtextxy(0,counter,"computer=0");outtextxy(150,counter,"player=0");
	  }
               }
};

int main()
{
int gd=DETECT,gm,color;
initgraph(&gd,&gd,"");
DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
initwindow(screenWidth-300,screenHeight,"");
int mx,my,n=10;
rps r1;
POINT cursorPosition;
readimagefile("background.jpeg",0,0,getmaxx(),getmaxy());
bar(0,0,250,250);
setfillstyle(1,8);
bar(0,280,270,900);

setfillstyle(1,11);
    bar(0,300,250,900);
    settextstyle(8,0,6);
    setbkcolor(BLUE);
    outtextxy(10,330,"SCORES=");
while(n!=0){
while(1){


GetCursorPos(&cursorPosition);

 if(GetAsyncKeyState(VK_LBUTTON )){
        int mx,my;
 mx=cursorPosition.x;
my=cursorPosition.y;

 if(mx>getmaxx()/2+50&&mx<getmaxx()&&my<getmaxy()&&my>getmaxy()-400){

cout<<"paper|vs|";
r1.Yourenterednumber(2);
r1.changeimg();
r1.compnumber();
r1.obj();
break;

}
else if(mx>519&&mx<662&&my>=0&&my<=440){
cout<<"Scissor|vs|";
r1.Yourenterednumber(3);

r1.changeimg();
r1.compnumber();
r1.obj();

break;
}
else if(mx>0&&mx<getmaxx()/2-50&&my<getmaxy()&&my>getmaxy()-400){
cout<<"ROCK|vs|";
r1.Yourenterednumber(1);
r1.changeimg();
r1.compnumber();
r1.obj();
break;
}
}
}
r1.score();
n--;

}
cleardevice();


r1.scoreboard();

getch();
closegraph();
return 0;
}

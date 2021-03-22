#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#undef abs;

union REGS i, o;
int initmouse();        // to intialize mouse
void showmouseptr();    // to show mouseptr
void hidemouseptr();    // to hide mouseptr
void getmousepos(int *button, int *x, int *y);  // to get current position of mouse
void restrictmouseptr(int x1, int y1, int x2, int y2); //to restrict mouse
void loading(); // for loading
int start();    // after loading program start till field
void field();
void players();
void bowler();
int bowling();
int legstroke(int cx);
int offstroke(int cx);
int miss(int cx);
int round(float x); // for round of integer
int score(); // for shing of run
int main()
{
   /* request auto detection */
   int gd = DETECT, gm,midx,midy,button,x,y,cx,i,overs,ball,w=0;
   int run=0,r=0;
   int points[]={0,464,639,464,639,479,0,479,0,464};
   char array[50];
   float p;
  fflush(stdin);
  /* initialize graphics and local variables */
  initgraph(&gd, &gm, "C:\\\\tc\\\\bgi");

  loading();
   overs=start();
   ball=overs*6;
   loading();
   for(i=0;i<ball;i++)
  {
     outtextxy(0,0,"PRESS ANY KEY TO EXIT");
restrictmouseptr(296,172,340,219);
 showmouseptr();
  cleardevice();
  field();
  score();
  settextstyle(0,0,0);
   sprintf(array,"%d - %d",run,w);
  outtextxy(20,466,array);
// printf("%d",r);// ball run
// printf("%d",run);// ball run
  players();
   cx=bowling();
    if(cx==321 || cx==322 || cx==323 || cx==325 || cx==319 || cx==26 || cx == 27 || cx== 28)
    r=legstroke(cx);
    if(cx==304 || cx==317 || cx==306 || cx==307 || cx==308 || cx==309 || cx==311 || cx==312 || cx==313 || cx==315 || cx==318 || cx==305 || cx==310)
    r=offstroke(cx);
    if(cx==316 || cx==320 || cx==303 || cx==302 || cx==314 || cx==324)
    r=miss(cx);
    if(cx>325)
      r=1;
    if(r==1)
    run=run+r;
    if(r==2 || r== 3)
        run=run+r;
    if(r==10)
        w=w+1;
         sprintf(array,"%d - %d",run,w);
  outtextxy(20,466,array);
  }
    // wide declare at cx>325 and cx<302   */
/*    showmouseptr();
    getmousepos(&button,&x,&y);
   while(!kbhit())
{
getmousepos(&button,&x,&y);
if( button == 1 )
{
button = -1;
cleardevice();
    field();
    players();
    bowler();
  //  ball();
     line(296,219,340,219);
     restrictmouseptr(0,0,639,479);
sprintf(array,"Left Button clicked x = %d y = %d",x,y);
outtextxy(0,30,array);
}
 else if( button == 2)
{
button = -1;
cleardevice();
   field();
   players();
   bowler();
 sprintf(array,"Right Button clicked x = %d y = %d",x,y);
outtextxy(midx/3,midy/2,array);
}
}*/
getch();
clearviewport();
closegraph();
return 0;
}

int start()
{
  int pointng[]={250,170,390,170,385,195,245,195,250,170};
  int pointh[]={250,220,390,220,385,245,245,245,250,220};
  int points[]={250,270,390,270,385,295,245,295,250,270};
  int pointe[]={250,320,390,320,385,345,245,345,250,320};
  int pointov[]={250,220,390,220,385,245,245,245,250,220};
   int point5[]={250,270,295,270,295,295,250,295,250,270};
   int point10[]={345,270,390,270,390,295,345,295,345,270};
   int overs,button,x,y;
  settextstyle(4,0,2);
  setfillstyle(1,4);
  fillpoly(5,pointng);
  outtextxy(265,170,"New Game");
   fillpoly(5,pointh);
  outtextxy(270,220,"Statistics");
  fillpoly(5,points);
  outtextxy(290,270,"Help");
  fillpoly(5,pointe);
  outtextxy(295,320,"Exit");

   showmouseptr();
    getmousepos(&button,&x,&y);
    button=0;
   while(!kbhit())
{
getmousepos(&button,&x,&y);
if(x>250 && x<390 && y>170 && y<195 && button==1) // new game
{
  button = -1;
  cleardevice();
  fillpoly(5,pointov);
  line(340,220,340,245);
  outtextxy(270,220,"Overs");
  fillpoly(5,point5);
  outtextxy(267,270,"5");
  fillpoly(5,point10);
  outtextxy(355,270,"10");
  showmouseptr();
    getmousepos(&button,&x,&y);
    button=0;
   while(!kbhit())
{
getmousepos(&button,&x,&y);
  if(x>250 && x<295 && y>270 & y<295 && button==1)
  {
    overs=5;
    outtextxy(350,220,"5");
	delay(1000);
    cleardevice();
    return overs;
  }
  if(x>345 && x<390 && y>270 & y<295 && button==1)
  {
    overs=10;
    outtextxy(350,220,"10");
    delay(1000);
    cleardevice();
    return overs;
  }
}
}
if(x>250 && x<390 && y>320 && y<345  && button==1) //exit
{
    exit(0);
    return 0;
}
}

}


int score()
{
    int i,j,pointsbr[]={0,464,639,464,639,479,0,479,0,464};
    int pointspn[]={0,464,14,465,14,479,0,479,0,464};
    int pointsrw[]={14,464,70,464,70,479,14,479,14,464};
   // float
   setfillstyle(1,8);
   rectangle(0,464,639,479);
   fillpoly(5, pointsbr);
    fillpoly(5, pointspn);
     fillpoly(5, pointsrw);
   //  setcolor(2);
     outtextxy(2,468,"C");
}

int miss(int cx)
{
  int  i,j,wx,wy,bx,by,q,r;
  float  p,s,dx,dy;
  cleardevice();
   field();
   players();
   bowler();
  bx=cx;
  by=160;
  wx=318;  wy=153;
  p=160-153;
  dx=318-cx;
  for(i=0;i<p;i++)
  {
   if(bx-wx>0 || bx-wx<0)
   wx=wx-1;
   by=by-1;
    // ball moveent
    setfillstyle(9,2);
  circle(bx,by,3);
  floodfill(bx,by,GREEN);

  // wktkpr movement
 setfillstyle(9,2);
  circle(wx,wy,3);
  floodfill(wx,wy,GREEN);
   delay(50);
  }
  r=0;
  return(r);
}

int bowling()
{
int j,i,userpat,x,y,button,dx,dy,cx,cy,tempx,tempy;
float n,q,r,p,t;
button = 3;
  while(!kbhit())       // getting position to be clicked
   {
   getmousepos(&button,&x,&y);
  if (button == 1)
  {
    hidemouseptr();
    tempx =x;
    tempy =y;
    button = -1;
   setfillstyle(1,4);
    circle(tempx,tempy,2);
   floodfill(tempx,tempy,WHITE);

    //bowler movement
  userpat = 1;
   setlinestyle(0, userpat,2);
      for (i=0;i<30;i++)           // movement of bowler
      {
       setfillstyle(9,2);
      circle(306,(322-i),3);
   floodfill(306,(322-i),2);
  delay(80);
   }
   // ball movement from bowler 2 point
   cleardevice();
   field();
   players();
   bowler();
    setfillstyle(1,4);
    circle(tempx,tempy,2);  // to draw point
   floodfill(tempx,tempy,WHITE);
   dx = (tempx-309);
   q = dx;
   dy = (276-tempy);
   if(dy>92)
    dy = 92;
   r = dy;
   if(dx>0) // ball to move right
   {
    t = q/r;
    setlinestyle(0, userpat,2);
   j=0;
   n = 0;
   while(j<dy)
    {
    p = 313+n-1;
   cx = round(p);
   cy = 275-j;
  setfillstyle(9,14);
  circle(cx,cy,3);
  floodfill(cx,cy,YELLOW);
  n = n+t;
     j++;
   delay(20);
     }
    }
     if(dx<0)     // ball to move left
   {
    t = -(q/r);
    setlinestyle(0, userpat,2);
   j=0;
   n = 0;
   while(j<dy)
    {
    p = 313-n-1;
   cx = round(p);
   cy = 275-j;
  setfillstyle(9,14);
    circle(cx,cy,3);
  floodfill(cx,cy,YELLOW);
  n = n+t;
     j++;
     delay(20);
     }
   }
     cleardevice();
   field();
   players();
   bowler();          // move the ball after dot
    j = 0;
    dy = tempy-184;
     randomize();
    i=random(4);
    i = i+2;
    while(j<dy)
    {
     cx=tempx+i;
     cy=tempy-j;

       setfillstyle(9,14);
    circle(cx,cy,2);
   floodfill(cx,cy,YELLOW);
   delay(20);
   j++ ;
    }
     return cx;
       break ;
   }
   }
   return 0;
  }

   void field()
   {
   int i,midx,midy,userpat;
    midx = getmaxx();
   midy = getmaxy();
   // field
     setlinestyle(0, userpat,2);
    setfillstyle(9,2);
      circle(midx/2,midy/2,205);
      floodfill(midx/2,midy/2,WHITE);

    setlinestyle(0, userpat,3);
    setfillstyle(9,2);
      circle(midx/2,midy/2,220);
   floodfill(106,219,WHITE);

    setlinestyle(0, userpat,2);
  // pitch
   setfillstyle(9,14);
  rectangle(296,172,341,291);
  floodfill(300,196,WHITE);

  // ellipse for power play

    ellipse(midx/2,midy/2,0,360,114,150);

  // wickets up
  userpat = 1;
   setlinestyle(0, userpat,2);

  line(314,173,314,165);
   line(318,173,318,165);
    line(322,173,322,165);
    // wickets down
      line(314,291,314,283);
   line(318,291,318,283);
    line(322,291,322,283);
     // stump
    line(314,165,322,165);
    // stump
   line(314,283,322,283);

   // margin

   line(300,172,300,181);
    line(300,181,337,181);
     line(337,181,337,172);
     line(300,280,337,280);
    line(300,280,300,289);
    line(337,280,337,289);
    }
void players()
{
int userpat,i;
   // player

       userpat = 1;
   setlinestyle(0, userpat,1);
    // empire
       setlinestyle(0, userpat,1);
      setfillstyle(1,15);
      circle(319,297,3);
   floodfill(319,297,WHITE);
    // runner
       setlinestyle(0, userpat,1);
      setfillstyle(1,8);
      circle(330,286,3);
   floodfill(330,286,WHITE);

	//wktkpr
      setfillstyle(1,1);
      circle(318,153,3);
   floodfill(318,153,WHITE);

   // batsman
       setlinestyle(0, userpat,1);
      setfillstyle(1,8);
      circle(319,176,3);
   floodfill(319,176,WHITE);
      // players
      // third posistion
	setfillstyle(1,1);
   circle(379,62,3);
    floodfill(379,62,WHITE);
    setfillstyle(1,1);
    // leg
    circle(500,231,3);
       floodfill(500,231,WHITE);
	setfillstyle(1,1);
      //	staight leg
     circle(447,363,3);
	floodfill(447,363,WHITE);
	setfillstyle(1,1);
	// straight off
      circle(220,383,3);
	 floodfill(220,383,WHITE);
	setfillstyle(1,1);
	// off
       circle(132,225,3);
	  floodfill(132,225,WHITE);
      setfillstyle(1,1);
      // front off 1
    circle(236,190,3);
       floodfill(236,190,WHITE);
		setfillstyle(1,1);
		// front off 2
    circle(242,287,3);
      floodfill(242,287,WHITE);
	setfillstyle(1,1);
	// leg off 2
     circle(379,271,3);
      floodfill(379,271,WHITE);
		setfillstyle(1,1);
		// leg off 1
      circle(389,190,3);
       floodfill(389,190,WHITE);
       }

  int offstroke(int cx)
 {

  int  by,p,i,q,a,bx,t,userpat=1,do1x,do1y,do2x,do2y,dox,doy,my;
  int o1x,o1y,o2x,o2y,ox,oy,osx,osy,dosx,dosy,io1,io2,io,ios;
  int io1x,io1y,io2x,io2y,iox,ioy,iosx,iosy,k;
  float o1,o2,o,os,min,r,n,m,l;
   int dx,dy,j,qx,cy,d,run=0,ru=0,r2=0;
   int bax=319,bay=187,rx=330,ry=272;
   int pointng[]={250,170,390,170,385,195,245,195,250,170};
    float v,z,x,w;
  o1=0; io1x=236; io1y=190;
  o2=0; io2x=242; io2y=287;
  o=0;  iox=132;  ioy=225;
  os=0; iosx=220; iosy=383;
    setlinestyle(0, userpat,2);
	 by = 185;
	 bx=cx;
   if(cx>303 && cx<319)     // moving ball from batsman
   {
     randomize();
    r =random(180);// random angle
    if(r>90 && r<110 || r>70 && r<90)
    r=160;
    p = random(100)+50; // coordinate random
     if(r>50 && r<70)
        p=random(20)+20;
    t = cx-p;
   n = (3.14/180)*r;   // convert angle to radian
   m = tan(n);       // slope of line
   q = round(cx*m);
  for(i=0;i<p+300;i++)
  {
       l = m*bx;
   by= round(l) - q + 185 ;
   do1x=bx-io1x; do1y=io1y-by;
   do2x=bx-io2x, do2y=io2y-by;
   dox=bx-iox;   doy=ioy-by;
   dosx=bx-iosx; dosy=iosy-by;
   o1 = sqrt(abs(pow(do1x,2)+pow(do1y,2)));
   o2 = sqrt(abs(pow(do2x,2)+pow(do2y,2)));
   o = sqrt(abs(pow(dox,2)+pow(doy,2)));
   os = sqrt(abs(pow(dosx,2)+pow(dosy,2)));
   min = min(min(o1,o2),min(o,os));
    if(bx>t)
  {
   if(pow((bx-319),2)+pow((by-239),2)<pow(210,2))
   {
   bx=cx-i;
   }
   }
   if(pow((bx-319),2)+pow((by-239),2)<pow(202,2) && pow((bx-319),2)+pow((by-239),2)>pow(90,2) || r>20&&r<70)
   {
     if(bay<276)                       //run
     {
     bax=319; bay=bay+1;
     setfillstyle(9,14);
    circle(bax,bay,3);
   floodfill(bax,bay,YELLOW);
  // printf("%d,%d",bay,ry);
   }
   if(ry>185)
   {
    rx=330; ry=ry-1;
     setfillstyle(9,14);
    circle(330,ry,3);
   floodfill(330,ry,YELLOW);
   }
    if(bay==276 && run==0 || bay==276 && run==1)
   {
       run=run+1;

       if(min>15)
       {
	   r2=2;
           bax=319,bay=187,rx=330,ry=272;
           cleardevice();
           field();
           players();
           bowler();
       }
   }

    }
if(pow((bx-319),2)+pow((by-239),2)>pow(202,2))
{
    ru=random(1);
    if(ru=0)
        run=4;
    if(ru=1)
        run=6;
        break;
}
   if(i%2==0)
   {
     if(min==o1)
     {
       min = o2;
      if(do1x==0 && do1y>0)
      {
       io1x = io1x;  io1y= io1y-1;
	setfillstyle(9,2);
	 circle(io1x,io1y,3);
	 floodfill(io1x,io1y,2);
      }
      if(do1x==0 && do1y<0)
      {
       io1x = io1x;  io1y= io1y+1;
	setfillstyle(9,2);
	 circle(io1x,io1y,3);
	 floodfill(io1x,io1y,2);
      }
      if(do1x>0 && do1y==0)
      {
       io1x = io1x+1;  io1y= io1y;
	setfillstyle(9,2);
	 circle(io1x,io1y,3);
	 floodfill(io1x,io1y,2);
      }
      if(do1x<0 && do1y==0)
      {
       io1x = io1x-1;  io1y= io1y;
	setfillstyle(9,2);
	 circle(io1x,io1y,3);
	 floodfill(io1x,io1y,2);
      }
      if(do1x>0 && do1y>0)
      {
       io1x = io1x+1;  io1y= io1y-1;
	setfillstyle(9,2);
	 circle(io1x,io1y,3);
	 floodfill(io1x,io1y,2);
      }
       if(do1x>0 && do1y<0)
       {
	io1x = io1x+1;  io1y= io1y+1;
	setfillstyle(9,2);
	 circle(io1x,io1y,3);
	 floodfill(io1x,io1y,2);
      }

      if(do1x<0 && do1y>0)
      {
       io1x = io1x-1;  io1y= io1y-1;
	setfillstyle(9,2);
	 circle(io1x,io1y,3);
	 floodfill(io1x,io1y,2);
      }
       if(do1x<0 && do1y<0)
       {
	io1x = io1x-1;  io1y= io1y+1;
	setfillstyle(9,2);
	 circle(io1x,io1y,3);
	 floodfill(io1x,io1y,2);
      }
   }

    if(min==o2 /*&& bx>319 && bx<434 && by>198 && by<367*/)
     {
     if(bx>350 || by>183 || by<358)
	min = o;
     if(bx>320 || by>200)
	min = os;
      if(do2x==0 && do2y>0)
      {
       io2x = io2x;  io2y= io2y-1;
       setfillstyle(9,2);
	 circle(io2x,io2y,3);
	 floodfill(io2x,io2y,2);
      }
      if(do2x==0 && do2y<0)
      {
       io2x = io2x;  io2y= io2y+1;
       setfillstyle(9,2);
	 circle(io2x,io2y,3);
	 floodfill(io2x,io2y,2);
      }
      if(do2x>0 && do2y==0)
      {
       io2x = io2x+1;  io2y= io2y;
       setfillstyle(9,2);
	 circle(io2x,io2y,3);
	 floodfill(io2x,io2y,2);
      }
      if(do2x<0 && do2y==0)
      {
       io2x = io2x-1;  io2y= io2y;
       setfillstyle(9,2);
	 circle(io2x,io2y,3);
	 floodfill(io2x,io2y,2);
      }if(do2x>0 && do2y>0)
      {
       io2x = io2x+1;  io2y= io2y-1;
       setfillstyle(9,2);
	 circle(io2x,io2y,3);
	 floodfill(io2x,io2y,2);
      }
       if(do2x>0 && do2y<0)
       {
       io2x = io2x+1;  io2y= io2y+1;
	setfillstyle(9,2);
	 circle(io2x,io2y,3);
	 floodfill(io2x,io2y,2);
      }
      if(do2x<0 && do2y>0)
      {
      io2x = io2x-1;  io2y= io2y-1;
       setfillstyle(9,2);
	 circle(io2x,io2y,3);
	 floodfill(io2x,io2y,2);
      }
       if(do2x<0 && do2y<0)
       {
       io2x = io2x-1;  io2y= io2y+1;
	setfillstyle(9,2);
	 circle(io2x,io2y,3);
	 floodfill(io2x,io2y,2);
      }
     }


    if(min==o/* && bx>350 && by>183 && by<358*/)
     {
      if(dox==0 && doy>0)
      {
      iox = iox;  ioy = ioy-1;
       setfillstyle(9,2);
	 circle(iox,ioy,3);
	 floodfill(iox,ioy,2);
      }
      if(dox==0 && doy<0)
      {
      iox = iox;  ioy = ioy+1;
       setfillstyle(9,2);
	 circle(iox,ioy,3);
	 floodfill(iox,ioy,2);
      }
      if(dox<0 && doy==0)
      {
      iox = iox-1;  ioy = ioy;
       setfillstyle(9,2);
	 circle(iox,ioy,3);
	 floodfill(iox,ioy,2);
      }
      if(dox>0 && doy==0)
      {
      iox = iox+1;  ioy = ioy;
       setfillstyle(9,2);
	 circle(iox,ioy,3);
	 floodfill(iox,ioy,2);
      }
      if(dox>0 && doy>0)
      {
      iox = iox+1;  ioy = ioy-1;
       setfillstyle(9,2);
	 circle(iox,ioy,3);
	 floodfill(iox,ioy,2);
      }
       if(dox>0 && doy<0)
       {
       iox = iox+1;  ioy = ioy+1;
	setfillstyle(9,2);
	 circle(iox,ioy,3);
	 floodfill(iox,ioy,2);
      }
      if(dox<0 && doy>0)
      {
       iox = iox-1;  ioy = ioy-1;
       setfillstyle(9,2);
	 circle(iox,ioy,3);
	 floodfill(iox,ioy,2);
      }
       if(dox<0 && doy<0)
       {
	iox = iox-1;  ioy = ioy+1;
	setfillstyle(9,2);
	 circle(iox,ioy,3);
	 floodfill(iox,ioy,2);
      }
   }
       if(min==os)
     {
    //  if(m>60)
     //{
      if(dosx==0 && dosy>0)
       {
	iosx = iosx;  iosy = iosy-1;
	setfillstyle(9,2);
	 circle(iosx,iosy,3);
	 floodfill(iosx,iosy,2);
      }
       if(dosx==0 && dosy<0)
       {
	iosx = iosx;  iosy = iosy+1;
	setfillstyle(9,2);
	 circle(iosx,iosy,3);
	 floodfill(iosx,iosy,2);
      }
       if(dosx>0 && dosy==0)
       {
	iosx = iosx+1;  iosy = iosy;
	setfillstyle(9,2);
	 circle(iosx,iosy,3);
	 floodfill(iosx,iosy,2);
      }
       if(dosx<0 && dosy==0)
       {
	iosx = iosx-1;  iosy = iosy;
	setfillstyle(9,2);
	 circle(iosx,iosy,3);
	 floodfill(iosx,iosy,2);
      }
       if(dosx>0 && dosy>0)
       {
	iosx = iosx+1;  iosy = iosy-1;
	setfillstyle(9,2);
	 circle(iosx,iosy,3);
	 floodfill(iosx,iosy,2);
      }
       if(dosx>0 && dosy<0)
       {
	iosx = iosx+1;  iosy = iosy+1;
	setfillstyle(9,2);
	 circle(iosx,iosy,3);
	 floodfill(iosx,iosy,2);
      }
       //	 if(m>35 && m<62)
	// {
      if(dosx<0 && dosy>0)
      {
	iosx = iosx-1;  iosy = iosy-1;
	setfillstyle(9,2);
	 circle(iosx,iosy,3);
	 floodfill(iosx,iosy,2);
      }
     // }
       if(dosx<0 && dosy<0)
       {
	iosx = iosx-1;  iosy = iosy+1;
	setfillstyle(9,2);
	 circle(iosx,iosy,3);
	 floodfill(iosx,iosy,2);
      }
     }
     }
       if(bx>302 && by>185)
       {
	 setfillstyle(9,14);
	 circle(bx,by,3);
	 floodfill(bx,by,14);

       }
       if(bx == 301)
       {
	  cleardevice();
	  field();
	  players();
	  bowler();
       }
      /**	if(px>334 && px<347)
       {
       setfillstyle(9,14);
     circle(335,cy,3);
  floodfill(335,cy,YELLOW);

      } **/
	if(bx<290)
       {
	 setfillstyle(9,2);
      circle(bx,by,3);
   floodfill(bx,by,2);
	 ellipse(319,239,0,360,114,150);
      circle(319,239,205);
      // printf("%d,%d,",px,cy);

     }

    // if(cy<185 && cy>168 && px>320 && px<340)
    // {
     //	  circle(166,330,3);
      //	  }
   //  if(cy<168)
    if(abs(bx-io1x)<4 && abs(by-io1y)<4)
     {
      break;
      }
     if(abs(bx-io2x)<4 && abs(by-io2y)<4)
     {
      break;
     }
      if(abs(bx-iox)<4 && abs(by-ioy)<4)
      {
      break;
      }
      if(abs(bx-iosx)<4 && abs(by-iosy)<4)
      {
      break;
      }
      setbkcolor(BLACK);
      delay(50);
        score();
     }
  }
  if(run!=4 || run!=6)
  {
   if(by<292 && bx<298)
      {
   dx = (319-bx);   //upper portion
   x = dx;
   dy = (277-by);
   r = dy;
    w = x/r;
    setlinestyle(0, userpat,2);
   j=0;
   v = 0;

   while(j<dy)
    {
    z = bx-v;
   qx = round(z);
   cy = by+j;
   if(qx>305)
   {
  setfillstyle(9,14);
  circle(qx,cy,3);
  floodfill(qx,cy,YELLOW);
   }
   if(qx<290)
    {
  setfillstyle(9,2);
  circle(qx,cy,3);
  floodfill(qx,cy,GREEN);
   }
  v = v-w;
     j++;
     if(bay<276)                       //run
     {
     bax=319; bay=bay+1;
     setfillstyle(9,14);
    circle(bax,bay,3);
   floodfill(bax,bay,YELLOW);
   }
   if(ry>185)
   {
    rx=330; ry=ry-1;
     setfillstyle(9,14);
    circle(330,ry,3);
   floodfill(330,ry,YELLOW);
   }
    if(bay==276 && run==0 || bay==276 && run==1)
   {
       run=run+1;
       if(run==1)
       r2=2;
   }

   delay(50);
     }
   }
     if(by>292 && bx<298)
     {
   dx = (309-bx);
   x = dx;
   dy = (by-297);
   r = dy;
    w = x/r;
    setlinestyle(0, userpat,2);
   j=0;
   v = 0;

   while(j<dy)
    {
    z = bx-v;
   qx = round(z);
   cy = by-j;
  setfillstyle(9,2);
  circle(qx,cy,3);
  floodfill(qx,cy,GREEN);
   v = v-w;
     j++;
    if(bay<276)                       //run
     {
     bax=319; bay=bay+1;
     setfillstyle(9,14);
    circle(bax,bay,3);
   floodfill(bax,bay,YELLOW);
   }
   if(ry>185)
   {
    rx=330; ry=ry-1;
     setfillstyle(9,14);
    circle(330,ry,3);
   floodfill(330,ry,YELLOW);
   }
   if(bay==276 && run==0 || bay==276 && run==1)
   {
       run=run+1;
   }

   delay(50);
     }
     }

     if(by<292 && bx>298)

     {
         j=0;
         dy=277-d;
         while(j<dy)
         {
       if(by>169)
       {
  setfillstyle(9,2);
  circle(qx,cy,3);
  floodfill(qx,cy,GREEN);
         }
      if(by<185)
          {
   setfillstyle(9,14);
  circle(qx,cy,3);
  floodfill(qx,cy,YELLOW);

     }
     if(bay<276)                       //run
     {
     bax=319; bay=bay+1;
     setfillstyle(9,14);
    circle(bax,bay,3);
   floodfill(bax,bay,YELLOW);
     }
   if(ry>185)
   {
    rx=330; ry=ry-1;
     setfillstyle(9,14);
    circle(330,ry,3);
   floodfill(330,ry,YELLOW);
   }
    if(bay==276 && run==0 || bay==276 && run==1)
   {
       run=run+1;
   }

     }
     }
    // printf("%d,%d,",ry,bay);
    // printf("%d,%d,",qx,cy);
     printf("%d,",run);
      if(qx==308 && cy==298 ||/* qx==319 && cy==276 || qx==318 && cy==275 || qx==318 && cy==276 || qx==317 && cy==276*/cy==276 || cy==275)
   {
       if(bay-276<0 && run==0 || bay-276<0 && run==1 && r2==2)
       {
	settextstyle(4,0,2);
	setfillstyle(1,4);
	fillpoly(5,pointng);
	outtextxy(265,170,"Run out");
	   run=10;
       }
       }
  }


   return run;
 }



 int legstroke(int cx)
 {

  int  by,p,i,q,a,bx,t,userpat=1,dl1x,dl1y,dl2x,dl2y,dlx,dly,my;
  int l1x,l1y,l2x,l2y,lx,ly,lsx,lsy,dlsx,dlsy,il1,il2,il,ils;
  int il1x,il1y,il2x,il2y,ilx,ily,ilsx,ilsy;
  int l3,l3x,l3y,il3x,il3y,dl3x,dl3y;
  float l1,l2,l,ls,min,r,n,m,o;
   int dx,dy,j,qx,cy;
    int bax=319,bay=187,rx=330,ry=272,run=0,r2=0,ru=0;
    int pointng[]={250,170,390,170,385,195,245,195,250,170};
    float v,z,x,w;
  l1=0; il1x=389; il1y=190;
  l2=0; il2x=379; il2y=271;
  l=0;  ilx=500;  ily=231;
  ls=0; ilsx=447; ilsy=363;
  l3=0; il3x=379; il3y=62;
    setlinestyle(0, userpat,2);
	 by = 185;
   if(cx>320 && cx<325)     // moving ball from batsman
   {
     randomize();
    r = random(80)+15; // random angle
    p = random(150)+50;    // coordinate random
   t = p+cx;
   n = (3.14/180)*r;   // convert angle to radian
   m = tan(n);         // slope of line
   q = round(cx*m);
   // printf("      %f,%d,%d,%d,",m,p,q,cx);
     my=round(m*(cx+p+1))-round(cx*m)+185;
     bx=cx;
   for(i=0;i<p+500;i++)
  {
   o = m*bx;
   by= round(o) - q + 185 ;
 //  printf("%d,%d,",bx,by);
   dl1x=bx-il1x; dl1y=il1y-by;
   dl2x=bx-il2x, dl2y=il2y-by;
   dlx=bx-ilx;   dly=ily-by;
   dlsx=bx-ilsx; dlsy=ilsy-by;
   dl3x=bx-il3x; dl3y=il3y-by;
   l1 = sqrt(abs(pow(dl1x,2)+pow(dl1y,2)));
   l2 = sqrt(abs(pow(dl2x,2)+pow(dl2y,2)));
   l = sqrt(abs(pow(dlx,2)+pow(dly,2)));
   ls = sqrt(abs(pow(dlsx,2)+pow(dlsy,2)));
   l3 = sqrt(abs(pow(dl3x,2)+pow(dl3y,2)));
   min = min(min(min(l1,l2),min(l,ls)),l3);
       if(bx<t)
  {
   if(pow((bx-319),2)+pow((by-239),2)<pow(210,2))
   {
   bx=cx+i;
   }
   }
   if(pow((bx-319),2)+pow((by-239),2)<pow(202,2) && pow((bx-319),2)+pow((by-239),2)>pow(100,2) || r>20&&r<70)
   {
     if(bay<276)                       //run
     {
     bax=319; bay=bay+1;
     setfillstyle(9,14);
    circle(bax,bay,3);
   floodfill(bax,bay,YELLOW);
  // printf("%d,%d",bay,ry);
   }
   if(ry>185)
   {
    rx=330; ry=ry-1;
     setfillstyle(9,14);
    circle(330,ry,3);
   floodfill(330,ry,YELLOW);
   }
    if(bay==276 && run==0 || bay==276 && run==1)
   {
       run=run+1;

       if(min>15)
       {
	   r2=2;
           bax=319,bay=187,rx=330,ry=272;
           cleardevice();
           field();
           players();
           bowler();
       }
   }
}
if(pow((bx-319),2)+pow((by-239),2)>pow(202,2))
{
    ru=random(1);
    if(ru=0)
        run=4;
    if(ru=1)
        run=6;
        break;
}
   if(i%3==0)
   {
     if(min==l1)
     {
       min = l2;
      if(dl1x==0 && dl1y>0)
      {
       il1x = il1x;  il1y= il1y-1;
	setfillstyle(9,2);
	 circle(il1x,il1y,3);
	 floodfill(il1x,il1y,2);
      }
      if(dl1x==0 && dl1y<0)
      {
       il1x = il1x;  il1y= il1y+1;
	setfillstyle(9,2);
	 circle(il1x,il1y,3);
	 floodfill(il1x,il1y,2);
      }
      if(dl1x>0 && dl1y==0)
      {
       il1x = il1x+1;  il1y= il1y;
	setfillstyle(9,2);
	 circle(il1x,il1y,3);
	 floodfill(il1x,il1y,2);
      }
      if(dl1x<0 && dl1y==0)
      {
       il1x = il1x-1;  il1y= il1y;
	setfillstyle(9,2);
	 circle(il1x,il1y,3);
	 floodfill(il1x,il1y,2);
      }
      if(dl1x>0 && dl1y>0)
      {
       il1x = il1x+1;  il1y= il1y-1;
	setfillstyle(9,2);
	 circle(il1x,il1y,3);
	 floodfill(il1x,il1y,2);
      }
       if(dl1x>0 && dl1y<0)
       {
	il1x = il1x+1;  il1y= il1y+1;
	setfillstyle(9,2);
	 circle(il1x,il1y,3);
	 floodfill(il1x,il1y,2);
      }

      if(dl1x<0 && dl1y>0)
      {
       il1x = il1x-1;  il1y= il1y-1;
	setfillstyle(9,2);
	 circle(il1x,il1y,3);
	 floodfill(il1x,il1y,2);
      }
       if(dl1x<0 && dl1y<0)
       {
	il1x = il1x-1;  il1y= il1y+1;
	setfillstyle(9,2);
	 circle(il1x,il1y,3);
	 floodfill(il1x,il1y,2);
      }
   }

    if(min==l2 /*&& bx>319 && bx<434 && by>198 && by<367*/)
     {
     if(bx>350 || by>183 || by<358)
	min = l;
     if(bx>320 || by>200)
	min = ls;
      if(dl2x==0 && dl2y>0)
      {
       il2x = il2x;  il2y= il2y-1;
       setfillstyle(9,2);
	 circle(il2x,il2y,3);
	 floodfill(il2x,il2y,2);
      }
      if(dl2x==0 && dl2y<0)
      {
       il2x = il2x;  il2y= il2y+1;
       setfillstyle(9,2);
	 circle(il2x,il2y,3);
	 floodfill(il2x,il2y,2);
      }
      if(dl2x>0 && dl2y==0)
      {
       il2x = il2x+1;  il2y= il2y;
       setfillstyle(9,2);
	 circle(il2x,il2y,3);
	 floodfill(il2x,il2y,2);
      }
      if(dl2x<0 && dl2y==0)
      {
       il2x = il2x-1;  il2y= il2y;
       setfillstyle(9,2);
	 circle(il2x,il2y,3);
	 floodfill(il2x,il2y,2);
      }if(dl2x>0 && dl2y>0)
      {
       il2x = il2x+1;  il2y= il2y-1;
       setfillstyle(9,2);
	 circle(il2x,il2y,3);
	 floodfill(il2x,il2y,2);
      }
       if(dl2x>0 && dl2y<0)
       {
       il2x = il2x+1;  il2y= il2y+1;
	setfillstyle(9,2);
	 circle(il2x,il2y,3);
	 floodfill(il2x,il2y,2);
      }
      if(dl2x<0 && dl2y>0)
      {
      il2x = il2x-1;  il2y= il2y-1;
       setfillstyle(9,2);
	 circle(il2x,il2y,3);
	 floodfill(il2x,il2y,2);
      }
       if(dl2x<0 && dl2y<0)
       {
       il2x = il2x-1;  il2y= il2y+1;
	setfillstyle(9,2);
	 circle(il2x,il2y,3);
	 floodfill(il2x,il2y,2);
      }
     }

     if(min==l3)
     {
       min = l2;
      if(dl3x==0 && dl3y>0)
      {
       il3x = il3x;  il3y= il3y-1;
	setfillstyle(9,2);
	 circle(il3x,il3y,3);
	 floodfill(il3x,il3y,2);
      }
      if(dl3x==0 && dl3y<0)
      {
       il3x = il3x;  il3y= il3y+1;
	setfillstyle(9,2);
	 circle(il3x,il3y,3);
	 floodfill(il3x,il3y,2);
      }
      if(dl3x>0 && dl3y==0)
      {
       il3x = il3x+1;  il3y= il3y;
	setfillstyle(9,2);
	 circle(il3x,il3y,3);
	 floodfill(il3x,il3y,2);
      }
      if(dl3x<0 && dl3y==0)
      {
       il3x = il3x-1;  il3y= il3y;
	setfillstyle(9,2);
	 circle(il3x,il3y,3);
	 floodfill(il3x,il3y,2);
      }
      if(dl3x>0 && dl3y>0)
      {
       il3x = il3x+1;  il3y= il3y-1;
	setfillstyle(9,2);
	 circle(il3x,il3y,3);
	 floodfill(il3x,il3y,2);
      }
       if(dl3x>0 && dl3y<0)
       {
	il3x = il3x+1;  il3y= il3y+1;
	setfillstyle(9,2);
	 circle(il3x,il3y,3);
	 floodfill(il3x,il3y,2);
      }

      if(dl3x<0 && dl3y>0)
      {
       il3x = il3x-1;  il3y= il3y-1;
	setfillstyle(9,2);
	 circle(il3x,il3y,3);
	 floodfill(il3x,il3y,2);
      }
       if(dl3x<0 && dl3y<0)
       {
	il3x = il3x-1;  il3y= il3y+1;
	setfillstyle(9,2);
	 circle(il3x,il3y,3);
	 floodfill(il3x,il3y,2);
      }
   }


    if(min==l/* && bx>350 && by>183 && by<358*/)
     {
      if(dlx==0 && dly>0)
      {
      ilx = ilx;  ily = ily-1;
       setfillstyle(9,2);
	 circle(ilx,ily,3);
	 floodfill(ilx,ily,2);
      }
      if(dlx==0 && dly<0)
      {
      ilx = ilx;  ily = ily+1;
       setfillstyle(9,2);
	 circle(ilx,ily,3);
	 floodfill(ilx,ily,2);
      }
      if(dlx<0 && dly==0)
      {
      ilx = ilx-1;  ily = ily;
       setfillstyle(9,2);
	 circle(ilx,ily,3);
	 floodfill(ilx,ily,2);
      }
      if(dlx>0 && dly==0)
      {
      ilx = ilx+1;  ily = ily;
       setfillstyle(9,2);
	 circle(ilx,ily,3);
	 floodfill(ilx,ily,2);
      }
      if(dlx>0 && dly>0)
      {
      ilx = ilx+1;  ily = ily-1;
       setfillstyle(9,2);
	 circle(ilx,ily,3);
	 floodfill(ilx,ily,2);
      }
       if(dlx>0 && dly<0)
       {
       ilx = ilx+1;  ily = ily+1;
	setfillstyle(9,2);
	 circle(ilx,ily,3);
	 floodfill(ilx,ily,2);
      }
      if(dlx<0 && dly>0)
      {
       ilx = ilx-1;  ily = ily-1;
       setfillstyle(9,2);
	 circle(ilx,ily,3);
	 floodfill(ilx,ily,2);
      }
       if(dlx<0 && dly<0)
       {
	ilx = ilx-1;  ily = ily+1;
	setfillstyle(9,2);
	 circle(ilx,ily,3);
	 floodfill(ilx,ily,2);
      }
   }
       if(min==ls)
     {
    //  if(m>60)
     //{
      if(dlsx==0 && dlsy>0)
       {
	ilsx = ilsx;  ilsy = ilsy-1;
	setfillstyle(9,2);
	 circle(ilsx,ilsy,3);
	 floodfill(ilsx,ilsy,2);
      }
       if(dlsx==0 && dlsy<0)
       {
	ilsx = ilsx;  ilsy = ilsy+1;
	setfillstyle(9,2);
	 circle(ilsx,ilsy,3);
	 floodfill(ilsx,ilsy,2);
      }
       if(dlsx>0 && dlsy==0)
       {
	ilsx = ilsx+1;  ilsy = ilsy;
	setfillstyle(9,2);
	 circle(ilsx,ilsy,3);
	 floodfill(ilsx,ilsy,2);
      }
       if(dlsx<0 && dlsy==0)
       {
	ilsx = ilsx-1;  ilsy = ilsy;
	setfillstyle(9,2);
	 circle(ilsx,ilsy,3);
	 floodfill(ilsx,ilsy,2);
      }
       if(dlsx>0 && dlsy>0)
       {
	ilsx = ilsx+1;  ilsy = ilsy-1;
	setfillstyle(9,2);
	 circle(ilsx,ilsy,3);
	 floodfill(ilsx,ilsy,2);
      }
       if(dlsx>0 && dlsy<0)
       {
	ilsx = ilsx+1;  ilsy = ilsy+1;
	setfillstyle(9,2);
	 circle(ilsx,ilsy,3);
	 floodfill(ilsx,ilsy,2);
      }
       //	 if(m>35 && m<62)
	// {
      if(dlsx<0 && dlsy>0)
      {
	ilsx = ilsx-1;  ilsy = ilsy-1;
	setfillstyle(9,2);
	 circle(ilsx,ilsy,3);
	 floodfill(ilsx,ilsy,2);
      }
     // }
       if(dlsx<0 && dlsy<0)
       {
	ilsx = ilsx-1;  ilsy = ilsy+1;
	setfillstyle(9,2);
	 circle(ilsx,ilsy,3);
	 floodfill(ilsx,ilsy,2);
      }
     }
   }

    if(bx<337 && by>185)
       {
       if(bx<336)
       {   //      getch();
	 setfillstyle(9,14);
	 circle(bx,by,3);
	 floodfill(bx,by,14);

       }
       if(bx == 336)
       {  // getch();
	  cleardevice();
	  field();
	  players();
	  bowler();
       }
      /**	if(px>334 && px<347)
       {
       setfillstyle(9,14);
     circle(335,cy,3);
  floodfill(335,cy,YELLOW);

      } **/
       }
	if(bx>347)
       {
	 setfillstyle(9,2);
      circle(bx,by,3);
   floodfill(bx,by,2);
	 ellipse(319,239,0,360,114,150);
      circle(319,239,205);
      // printf("%d,%d,",px,cy);

     }

    /* if(cy<185 && cy>168 && px>320 && px<340)
     {
     	  circle(166,330,3);
      	  }
     if(cy<168)*/
    // printf("500");
     if(abs(bx-il1x)<4 && abs(by-il1y)<4)
     {
     printf("l1");
      break;
      }
     if(abs(bx-il2x)<4 && abs(by-il2y)<4)
     {
      printf("l2");
      break;
     }
      if(abs(bx-ilx)<4 && abs(by-ily)<4)
      {
       printf("l");
      break;
      }
      if(abs(bx-ilsx)<4 && abs(by-ilsy)<4)
      {
       printf("ls");
      break;
      }
    setbkcolor(BLACK);
    delay(30);
    }
    }

     if(run==1 || run==2 || run==3)
     {
      if(by<299)
   dx = (bx-319);
   x = dx;
   dy = (277-by);
   r = dy;
    w = x/r;
    setlinestyle(0, userpat,2);
   j=0;
   v = 0;

   while(j<dy)
    {
    z = bx-v;
   qx = round(z);
   cy = by+j;
   if(qx>347)
   {
  setfillstyle(9,2);
  circle(qx,cy,3);
  floodfill(qx,cy,GREEN);
   }
   if(qx<336)
    {
  setfillstyle(9,14);
  circle(qx,cy,3);
  floodfill(qx,cy,YELLOW);

   }
  v = v+w;
     j++;
      if(bay<276)                       //run
     {
     bax=319; bay=bay+1;
     setfillstyle(9,14);
    circle(bax,bay,3);
   floodfill(bax,bay,YELLOW);
   }
   if(ry>185)
   {
    rx=330; ry=ry-1;
     setfillstyle(9,14);
    circle(330,ry,3);
   floodfill(330,ry,YELLOW);
   }
    if(bay==276 && run==0 || bay==276 && run==1)
   {
       run=run+1;
       if(run==1)
       r2=2;
   }
   delay(50);
     }

     if(by>299)
     {
   dx = (bx-328);
   x = dx;
   dy = (by-299);
   r = dy;
    w = x/r;
    setlinestyle(0, userpat,2);
   j=0;
   v = 0;

   while(j<dy)
    {
    z = bx-v;
   qx = round(z);
   cy = by-j;
  setfillstyle(9,2);
  circle(qx,cy,3);
  floodfill(qx,cy,GREEN);
  v = v+w;
     j++;
      if(bay<276)                       //run
     {
     bax=319; bay=bay+1;
     setfillstyle(9,14);
    circle(bax,bay,3);
   floodfill(bax,bay,YELLOW);
   }
   if(ry>185)
   {
    rx=330; ry=ry-1;
     setfillstyle(9,14);
    circle(330,ry,3);
   floodfill(330,ry,YELLOW);
   }
    if(bay==276 && run==0 || bay==276 && run==1)
   {
       run=run+1;
       if(run==1)
       r2=2;
   }
   delay(50);
     }
     }
     }
      // printf("%d,%d,",ry,bay);
    //printf("%d,%d,",qx,cy);
    // printf("%d,",run);
      if(qx==308 && cy==298 ||/* qx==319 && cy==276 || qx==318 && cy==275 || qx==318 && cy==276 || qx==317 && cy==276*/cy==276 || cy==275)
   {
       if(bay-276<0 && run==0 || bay-276<0 && run==1 && r2==2)
       {
	settextstyle(4,0,2);
	setfillstyle(1,4);
	fillpoly(5,pointng);
	outtextxy(265,170,"Run out");
	   run=10;
       }
       }
   getch();
  return run;
  }

void bowler()
 {
  int lx,j;
  //bowler
  setfillstyle(1,1);
   circle(306,287,3);
   floodfill(306,287,WHITE);

 }

 int round(float x)
 {
    int i,j,a,b,c,d;
    i=0;
    c=abs(x*10);
     while(j>0)
    {
      if(i>abs(x))
    {
	a=i*10;
	b=(i-1)*10;
	   if((b+3)>c)
       {
	   d = (b/10);
	    if(x>0)
       return d;
	if(x<0)
            return(-d);
	 j = -1 ;
       }
       else
       {
	if(x>0)
        return i;
	if(x<0)
            return(-i);
	j = -1;

	}
	}
	 i = i+1;
	}
	}

int initmouse()
{
i.x.ax = 0;
int86(0X33,&i,&o);
return ( o.x.ax );
}
void showmouseptr()
{
i.x.ax = 1;
int86(0X33,&i,&o);
}
void hidemouseptr()
{
i.x.ax = 2; // to hide mouse
int86(0X33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
i.x.ax = 3;
int86(0X33,&i,&o);
*button = o.x.bx;
*x = o.x.cx;
*y = o.x.dx;
}
void restrictmouseptr(int x1, int y1, int x2, int y2)
{
i.x.ax = 7;
i.x.cx = x1;
i.x.dx = x2;
int86(0X33,&i,&o);
i.x.ax = 8;
i.x.cx = y1;
i.x.dx = y2;
int86(0X33,&i,&o);
}

void loading()
{
 int i;
  for(i=0;i<=360;++i)
{
circle(300,200,80);
pieslice(300,200,0,i,80);
outtextxy(260,320,"Loading...");
delay(5);
}
cleardevice();
}




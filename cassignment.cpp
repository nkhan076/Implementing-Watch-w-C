/*
	author: Naima Khan (0705076)
	last modified: September 15, 2008
*/
#include "iGraphics.h"
# include <math.h>

int x1,x2,h1,h2,m1,m2,s1,s2;
int rgb_1[3]={0,0,0},rgb_2[3]={128,128,128};

float a,b,c;
void iSecond();
void iMinute();
void iHour();
void color_1();
void color_2();
void color_3();

/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	
	iClear();

	iSetColor(255,255,255);
	iFilledRectangle(0,0,600,600);
	
	iSetColor(rgb_1[0],rgb_1[1],rgb_1[2]);
	iFilledEllipse(300,300,154,254,100);

	//iSetColor(rgb_2[0],rgb_2[1],rgb_2[2]);
	//iFilledEllipse(300,300,134,234);

	iSetColor(255,255,255);
	iText(300,487,"XII",GLUT_BITMAP_HELVETICA_18);
	iText(404,300,"III",GLUT_BITMAP_HELVETICA_18);
	iText(178,300,"IX",GLUT_BITMAP_HELVETICA_18);
	iText(290,100,"VI",GLUT_BITMAP_HELVETICA_18);
	iText(372,435,"I",GLUT_BITMAP_HELVETICA_18);
	iText(400,223,"IV",GLUT_BITMAP_HELVETICA_18);
	iText(400,378,"II",GLUT_BITMAP_HELVETICA_18);
	iText(380,150,"V",GLUT_BITMAP_HELVETICA_18);
	iText(200,150,"VII",GLUT_BITMAP_HELVETICA_18);
	iText(178,223,"VIII",GLUT_BITMAP_HELVETICA_18);
	iText(194,378,"X",GLUT_BITMAP_HELVETICA_18);
	iText(229,441,"XI",GLUT_BITMAP_HELVETICA_18);
	iText(260,380,"CSE 106",GLUT_BITMAP_HELVETICA_18);
	iText(280,340,"ASSIGNMENT",GLUT_BITMAP_HELVETICA_18);
	iLine(x1,x2,h1,h2);
	iFilledCircle(300,300,5);
	iSetColor(100,100,100);
	iLine(x1,x2,m1,m2);
	iSetColor(140,140,140);
	iLine(x1,x2,s1,s2);

	
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	printf("%d %d\n",mx,my);
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here
	
	x1=300,x2=300,h1=300,h2=350,m1=300,m2=375,s1=300,s2=400;
	a=3.1416/30,b=3.1416/30,c=3.1416/60;
	//iSetTimer(10*1000,colorchange);
	
	//iSetTimer(1000*60,ColorChange_2);

	iSetTimer(10*1000,color_1);
	iSetTimer(10*1000,color_2);
	iSetTimer(10*1000,color_3);
	
	iSetTimer(1000,iSecond);
	iSetTimer(1000*60,iMinute);
	iSetTimer(1000*60*6,iHour);
	
	iInitialize(600,600,"Clock");
	return 0;
}	
void iSecond()
{
	iClear();
	s1=x1+140*sin(a);
	s2=x2+140*cos(a);
	a+=3.1416/30;
}
void iMinute()
{
	iClear();
	m1=x1+120*sin(b);
	m2=x2+120*cos(b);
	b+=3.1416/30;
}
void iHour()
{
	iClear();
	h1=x1+100*sin(b);
	h2=x2+100*cos(b);
	c+=3.1416/60;
}
void color_1()
{
	if((rgb_1[0]==0)&&(rgb_1[1]==0))
		rgb_1[0]=rgb_1[0]+128;
	else if((rgb_1[0]==128)&&(rgb_1[1]==0))
		rgb_1[0]=rgb_1[0]-64;
	else if(rgb_1[0]==64)
		rgb_1[0]-=64;

	else if((rgb_1[0]==0)&&(rgb_1[1]==64))
			rgb_1[0]=rgb_1[0]+128;
	else if((rgb_1[0]==128)&&(rgb_1[1]==255))
		rgb_1[0]-=128;
}
void color_2()
{


	
	if((rgb_1[0]==64)&&(rgb_1[1]==0))
		rgb_1[1]+=64;
	else if ((rgb_1[0]==0)&&(rgb_1[1]==64)&&(rgb_1[2]==255))
		rgb_1[1]+=191;
	else if(rgb_1[1]==255)
		rgb_1[1]-=255;
	else if((rgb_1[0]==128))
		rgb_1[1]=0;
}
	
void color_3()		
{		
	if((rgb_1[0]==0)&&(rgb_1[1]==0)&&(rgb_1[2]==0))
		rgb_1[2]+=64;
	else if((rgb_1[0]==0)&&(rgb_1[1]==64))
		rgb_1[2]+=64;
	else if((rgb_1[0]==128)&&(rgb_1[1]==255))
		rgb_1[2]=255;
	else if(rgb_1[2]==255)
		rgb_1[2]=0;
		
}
/*void color_2()
{
	if(rgb_2[0]==150)
		rgb_2[0]-=22;
	else if(rgb_2[0]==128)
		;
	if((rgb_2[0]==128)&&(rgb_2[1]==255))
		rgb_2[0]-=128;
	else if(rgb_2[0]==0)
		rgb_2[0]+=128;
	else if(rgb_2[0]==128)
		rgb_2[0]-=128;

	if(rgb_2[1]==150)
		rgb_2[1]=0;
	else if(rgb_2[1]==0)
		rgb_2[1]=255;
	else if(rgb_2[1]==255)
		rgb_2[1]=128;
	else if((rgb_2[1]==128)&&(rgb_2[0]==0))
		rgb_2[1]+=0;
	else if(rgb_2[1]==128)
		rgb_2[1]-=64;

	if(rgb_2[2]==150)
		rgb_2[2]-=86;
	else if(rgb_2[2]==64)
		rgb_2[2]-=191;
	else if(rgb_2[2]==255)
		rgb_2[2]=192;
	else if(rgb_2[2]==192)
		rgb_2[2]=255;
	else 
		rgb_2[2]=128;
}
*/
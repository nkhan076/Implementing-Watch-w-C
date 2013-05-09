/*
	 Naima Khan
	last modified: September 28, 2008
	each guti r co ordinate determine  korar jonno duita kore variable dhorte  hobe
	array kore tar moddha each square ar co ordinate rakhar chashta korte hobe
*/
# include "iGraphics.h"

int dice();
float cx(int x1,int x2);
float cy(int y1,int y2);
int c,turn_no=0,players,c_1,c_2,six_1,cir_no_1,d;
float  center_x,center_y,pla_1_sqr[56][3],r_x=cx(202,30),r_y=cy(50,30),r_x2=cx(202,30),r_y2=cy(50,30);
char str_1[20],str_2[20],str_3[20],str_4[20],str_5[20];
char str[100], str2[100];
int len;
int choice;
int mode;

struct data
{
	struct dice

	{
		float r_x;
		float r_y;
		int six;
		int chal;
		//int flag_g;
	}guti_1,guti_2;
	int d;
	

}player_1,player_2;


/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	int a1,b1,i;
	
	//place your drawing codes here	
	iClear();
	iSetColor(64,128,128);//First square//
	iFilledRectangle(0,0,500,500);
	iSetColor(255,255,255);//second square//
	iFilledRectangle(20,20,460,460);
	iSetColor(0,128,192);//center square//
	iFilledRectangle(204,204,92,92);
	iSetColor(0,0,255);//Right bottom square(blue)//
	iFilledRectangle(300,20,178,178);
	iSetColor(255,255,0);//Right top square(yellow)//
	iFilledRectangle(300,300,178,178);
	iSetColor(0,64,0);//Left Top square(green)//
	iFilledRectangle(20,300,178,178);
	iSetColor(0,0,0);//Left bottom square(128,0,0)(red)//
	iFilledRectangle(20,20,178,178);

	//square for movement of the dice//

	for(a1=301,b1=204;a1<480;a1+=30)//Blue//
	{
		if(a1==421)
		{
			iSetColor(128,0,255);
			iFilledRectangle(a1,b1,27,27);
			iFilledRectangle(a1,b1+33,27,27);
			iSetColor(0,0,128);
			iFilledRectangle(a1,b1+66,27,27);
		}
		else if(a1==451)
		{
			iSetColor(0,0,128);
			iFilledRectangle(a1,b1,27,27);
			iFilledRectangle(a1,b1+33,27,27);
			iFilledRectangle(a1,b1+66,27,27);

		}
		else
		{
			iSetColor(0,0,128);//entire//
			iFilledRectangle(a1,b1,27,27);

			iSetColor(128,0,255);//middle//
			iFilledRectangle(a1,b1+33,27,27);

			iSetColor(0,0,128);//entire//
			iFilledRectangle(a1,b1+66,27,27);
		}
	
	}

	for(a1=202,i=1;((a1<300)&&(i<=3));a1+=33,i++)//Red//
	{
			if((i==1)||(i==3))
				iSetColor(255,0,128);
			else if(i==2)
				iSetColor(255,128,192);
			for(b1=20;b1<200;b1+=30)
			{
				if((b1==50)&&(i==1))
					iSetColor(255,128,192);
				else if((b1>50)&&(i==1))
					iSetColor(255,0,128);
				else if((b1==20)&&(i==2))
					iSetColor(255,0,128);
				else if((b1==50)&&(i==2))
					iSetColor(255,128,192);

				iFilledRectangle(a1,b1,27,27);
			}
	
	}

	for(a1=22,b1=204;a1<200;a1+=30)//green//
	{
		if(a1==52)
		{
			iSetColor(0,128,128);
			iFilledRectangle(a1,b1,27,27);
			iSetColor(0,255,255);
			iFilledRectangle(a1,b1+33,27,27);
			iFilledRectangle(a1,b1+66,27,27);
		}
		else if(a1==22)
		{
			iSetColor(0,128,128);
			iFilledRectangle(a1,b1,27,27);
			iFilledRectangle(a1,b1+33,27,27);
			iFilledRectangle(a1,b1+66,27,27);

		}
		
		else
		{
			iSetColor(0,128,128);
			iFilledRectangle(a1,b1,27,27);

			iSetColor(0,255,255);
			iFilledRectangle(a1,b1+33,27,27);

			iSetColor(0,128,128);
			iFilledRectangle(a1,b1+66,27,27);
		}
	
	}

	for(a1=203,i=1;((a1<300)&&(i<=3));a1+=33,i++)//Yellow//
	{
		if((i==1)||(i==3))
			iSetColor(255,128,0);
		else if(i==2)
			iSetColor(255,128,128);
		for(b1=300;b1<480;b1+=30)
		{
			if((b1==450)&&((i==2)||(i==3)))
					iSetColor(255,128,0);
			else if((b1==420)&&(i==3))
					iSetColor(255,128,128);
			iFilledRectangle(a1,b1,27,27);
		}
	}
//whose turn//
	if(players==2)
	{
		iSetColor(255,0,128);
		if((turn_no%2)==0)
		{
			iText(510,480,"This is 1st player's turn.",GLUT_BITMAP_9_BY_15);
			iSetColor(128,0,0);
			//if(choice==1)
			//{
				if(d==6&&six_1==0)
					iFilledCircle(r_x,r_y,10);
				else if(six_1!=0) 
					iFilledCircle(r_x,r_y,10);
			//}
			//else if(choice==2)
			/*{
				if(d==6&&cir_no_1<=2)
				{
					iFilledCircle(r_x2,r_y2,10);
				}
				else 
					iFilledCircle(r_x2,r_y2,10);
			}*/
			
			
		}
		else
		{
			iText(510,480,"This is 2nd player's turn.",GLUT_BITMAP_9_BY_15);
			
		}

	}
	

	else if(players==3)
	{
		iSetColor(255,0,128);
		if((turn_no%3)==1)
			iText(60,60,"This is 1st player's turn.");
		else if((turn_no==2)||((turn_no%2)==1))
			iText(250,60,"This is 2nd player's turn.");
		else if(turn_no%3==0)
			iText(60,400,"This is 3rd player's turn.");

	}
	else if(players==4)
	{
		iSetColor(255,0,128);
		if(turn_no%4==1)
			iText(60,60,"This is 1st player's turn.");
		else if(turn_no%4==2)
			iText(250,60,"This is 2nd player's turn.");
		else if(turn_no%4==3)
			iText(60,400,"This is 3rd player's turn.");
		else if(turn_no%4==0)
			iText(400,400,"This is 4th player's turn.");

	}

//dice show//	
	
	if(c==1)
		iShowBMP(210,210,"dice1.bmp");
	else if(c==2)
		iShowBMP(210,210,"dice2.bmp");
	else if(c==3)
		iShowBMP(210,210,"dice3.bmp");
	else if(c==4)
		iShowBMP(210,210,"dice4.bmp");
	else if(c==5)
		iShowBMP(210,210,"dice5.bmp");
	else if(c==6)
		iShowBMP(210,210,"dice6.bmp");

	//drawing dice of different color//

	iSetColor(128,0,0);//red//
	iFilledCircle(550,440,10);
	iText(550,440,"1",GLUT_BITMAP_9_BY_15);
	iFilledCircle(550,410,10);
	iFilledCircle(550,380,10);
	iFilledCircle(550,350,10);

	iSetColor(0,64,128);//blue//
	iFilledCircle(600,440,10);
	iFilledCircle(600,410,10);
	iFilledCircle(600,380,10);
	iFilledCircle(600,350,10);

	iSetColor(0,128,128);//green//
	iFilledCircle(650,440,10);
	iFilledCircle(650,410,10);
	iFilledCircle(650,380,10);
	iFilledCircle(650,350,10);

	iSetColor(255,128,0);//yellow//
	iFilledCircle(700,440,10);
	iFilledCircle(700,410,10);
	iFilledCircle(700,380,10);
	iFilledCircle(700,350,10);
	
	

	iSetColor(64,0,64);
	//iText(10,10,"press p for pause,r for resume.");
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	//printf("\n%d  %d\n",mx,my);
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
}//void imouse

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	int flag=0,flag1=0,flag_six=0,totalchal=0;
	if(turn_no%2!=0)//**********First Player*********//
	{
		totalchal=0;
		
		if(key == 'p')
		{
			player_1.d=dice();
				
			if(player_1.d!=6 && flag_six==0)
			{
				turn_no++;
				printf("\nTurn no=%d",turn_no);
			}
			else if(player_1.d==6 && flag_six==0)
			{
				flag_six++;
				totalchal+=player_1.d;
			}
			else if(flag_six>=1)
			{
				if(player_1.d==6)
				{
					flag_six++;
					if(flag_six%3==0)
					{
						flag=1;
						printf("\nTRIPLE SIX for player 1 \n");
						turn_no++;
						printf("Turn_no=%d",turn_no);
					}
					else if(flag_six%3!=0)
					{
						totalchal+=player_1.d;	
					}

				}
				else if(player_1.d!=6)
				{
					totalchal+=player_1.d;
					turn_no++;
					printf("\nTurn no=%d",turn_no);
				}
			}//last else if
		}//key=='p'
			
		else if(key!='p')
		{
			flag1=1;
			turn_no++;
		}
	}//turn_no%2!=0
			
		
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
int dice()
{
	c=(rand()%6)+1;
	//printf("%d",c);
	return c;
}

int main()
{
	//place your own initialization codes here.
	
	int i,j,k=0;
	for(i=0;i<56;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j==0)
			{
				pla_1_sqr[i][j]=i+1;
				//printf("\n[%d][%d]=%d\n",i,j,pla_1_sqr[i][j]);
			}
			else if(j==1)
			{
				if(i+1>=1&&i+1<=5)
				{
					pla_1_sqr[i][j]=cx(202,30);
				}
				else if(i+1>=6&&i+1<=13)
				{
					if(i+1==6)
					{pla_1_sqr[i][j]=cx(172,30);k=1;}
					else if(i+1>6&&i+1<=13)
					{
						
						pla_1_sqr[i][j]=cx(172,30)-k*30;
						if(i+1<11)
							k++;
						
					}
				}
				else if(i+1>13&&i+1<=18)
				{
					if(i+1==14)
						k=1;
					pla_1_sqr[i][j]=cx(22,30)+k*30;
					k++;
					
				}
				else if(i+1>=19&&i+1<=24)
				{
					
					pla_1_sqr[i][j]=cx(202,30);
					k=1;
				}
				else if(i+1>24&&i+1<=31)
				{
					
					if(i+1>24&&i+1<26)
					{
						pla_1_sqr[i][j]=cx(202,30)+k*30;
						k++;	
					}
					else if(i+1>=26&&i+1<=31)
					{
						pla_1_sqr[i][j]=cx(268,30);
					}


				}
				else if(i+1>=32&&i+1<=39)
				{
					if(i+1==32)
					{
						pla_1_sqr[i][j]=cx(302,30);
						k=1;
					}
					else if(i+1>32&&i+1<=37)
					{
						pla_1_sqr[i][j]=cx(302,30)+k*30;
						k++;

					}
					else if(i+1>37&&i+1<=39)
					{
						pla_1_sqr[i][j]=cx(452,30);
						k=1;
					}
					
				}
				else if(i+1>39&&i+1<=44)
				{
					pla_1_sqr[i][j]=cx(452,30)-k*30;
					k++;
				}
				else if(i+1>=45&&i+1<=56)
				{
					if(i+1>=45&&i+1<=50)
						pla_1_sqr[i][j]=cx(262,30);
					else if(i+1>=51&&i+1<=56)
						pla_1_sqr[i][j]=cx(232,30);
				}
				//printf("\n[%d][%d]=%d\n",i,j,pla_1_sqr[i][j]);

			}
			else if(j==2)
			{
				
				if(i+1>=1&&i+1<=5)
				{
					
					pla_1_sqr[i][j]=cy(50,30)+k*30;
					k++;
				}
				else if(i+1>=6&&i+1<=11)
				{
					pla_1_sqr[i][j]=cy(200,30);
					k=1;
				}
				else if(i+1>11&&i+1<=18)
				{
					
					
					if(i+1<13)
					{
						pla_1_sqr[i][j]=cy(200,30)+k*30;
						k++;
					}
					else
					{
						pla_1_sqr[i][j]=cy(271,30);
						k=0;
					}
					
				}
				else if(i+1>=19&&i+1<=26)
				{
					
					if(i+1>=19&&i+1<24)
					{
						
						//pla_1_sqr[i][j]=305+k*30;
						//k++;
						pla_1_sqr[18][2]=cy(271,30);
						pla_1_sqr[19][2]=cy(271,30)+30;
						pla_1_sqr[20][2]=cy(271,30)+2*30;
						pla_1_sqr[21][2]=cy(271,30)+3*30;
						pla_1_sqr[22][2]=cy(271,30)+4*30;
						pla_1_sqr[23][2]=cy(271,30)+5*30;

					
					}
					else 
					{
						pla_1_sqr[i][j]=cy(441,30);
						k=1;
					}

				}
				else if(i+1>26&&i+1<=31)
				{
					pla_1_sqr[i][j]=cy(441,30)-k*30;
					k++;
				}
				else if(i+1>=32&&i+1<=44)
				{
					if(i+1>=32&&i+1<=37)
					{
						pla_1_sqr[i][j]=cy(271,30);
						k=1;
					}
					else if(i+1>37&&i+1<39)
					{
						pla_1_sqr[i][j]=cy(271,30)-k*30;
						k++;
					}
					else if(i+1>=39&&i+1<=44)
					{
						pla_1_sqr[i][j]=cy(200,30);
						k=1;
					}
				}
				else if(i+1>=45&&i+1<=56)
				{
					if(i+1==45)
					{
						pla_1_sqr[i][j]=cy(172,30);
						k=1;
					}
					else if(i+1>45&&i+1<=50)
					{
						pla_1_sqr[i][j]=cy(172,30)-k*30;
						k++;
					}
					else if(i+1==51)
					{
						pla_1_sqr[i][j]=cy(20,30);
						k=1;
					}
					else if(i+1>51&&i+1<=56)
					{
						pla_1_sqr[i][j]=cy(20,30)+k*30;
						k++;
					}
				}
				//printf("\n[%d][%d]=%d\n",i,j,pla_1_sqr[i][j]);
			}
		}//second for loop shesh
		
	}//first for loop shesh(first player ar gutir chal)
	
	printf("Players could not be more than four.\nEnter a number between 2 and 4. \n");
	scanf("%d",&players);
	//printf("\nEnter players name:\n");
	/*if(players==2)
	{
		gets(str_1);
		gets(str_2);
		gets(str_3);
		
		
	}
	else if(players==3)
	{
		gets(str_1);
		gets(str_2);
		gets(str_3);
		gets(str_4);
	}
	else if(players==4)
	{
		gets(str_1);
		gets(str_2);
		gets(str_3);
		gets(str_4);
		gets(str_5);*/
		/*puts(str_1);
		puts(str_2);
		puts(str_3);
		puts(str_4);
		puts(str_5);
	}*/
	
	iInitialize(800, 500, "LUDU");
	return 0;
}	
float cx(int x1,int x2)//x1=co ordinate of left bottom point;x2=incresement of x1;//
{
	x2=x1+x2;
	center_x=(x1+x2)/2;
	//printf("\ncenter x=%f",center_x);
	return center_x;
}
float cy(int y1,int y2)
{
	y2=y1+y2;
	center_y=(y1+y2)/2;
	//printf("\ncenter y=%f",center_y);
	return center_y;
}

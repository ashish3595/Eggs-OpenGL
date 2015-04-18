#include "cg_project.h"
#include<stdio.h>
extern GLdouble width,height,ycord_first,ycord_second,ycord_third,xcord_first,xcord_second,xcord_third,deltax_first,deltax_second,deltax_third,velocity;
extern GLdouble eggcentrex,eggcentrey,egginbasketnumber,g,ellipsecordx,ellipsecordy,eggcentrexnext,eggcentreynext,delta;
extern float Pi,y_dist;
extern bool flag,slideFlag,gameoverflag,animateFlag;
extern int basketBelow,basketAbove,life,points,animateCount,ellipseSize;

void Draw() 
{	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);   

  if(gameoverflag==true)
      GameOver();
  else
  { 
    
    Background();
	
	if(xcord_first+0.06>=1.0 || xcord_first<=0.0)
		deltax_first=-deltax_first;
	xcord_first+=deltax_first;
	if(xcord_second+0.06>=1.0 || xcord_second<=0.0)
		deltax_second=-deltax_second;
	xcord_second+=deltax_second;
	if(xcord_third+0.06>=1.0 || xcord_third<=0.0)
		deltax_third=-deltax_third;
	xcord_third+=deltax_third;
	
	if(slideFlag==true)
	  decrement();
	
    DrawBucket(xcord_first,ycord_first);
	DrawBucket(xcord_second,ycord_second);
	DrawBucket(xcord_third,ycord_third);
	
	if(egginbasketnumber==1)
	{
		eggcentrex=xcord_first+0.03;
		if(flag==true)
		{
         eggcentrey+=velocity;
         velocity-=g;
        }
	}
	else if(egginbasketnumber==2) 
	{
		eggcentrex=xcord_second+0.03;
		if(flag==true)
		{
         eggcentrey+=velocity;
         velocity-=g;
        }
	}
	else
	{
		eggcentrex=xcord_third+0.03;
 	    if(flag==true)
        {
         eggcentrey+=velocity;
         velocity-=g;
        }
	}               
                     	
	if(flag==true)
	{
    if(velocity<0 && eggcentrex >=(xcord_first) && eggcentrex<=(xcord_first+0.06) && eggcentrey>=(ycord_first+0.06) && eggcentrey<=(ycord_first+0.08))
    {
       if(egginbasketnumber==1)
       life--;
       else
       points++;           
       egginbasketnumber=1;
       eggcentrex=xcord_first+0.03;
       eggcentrey=ycord_first+0.045;
       velocity=VEL;
       flag=false;
       animateFlag=true;
    }
    if(velocity<0 && eggcentrex >=(xcord_second)&& eggcentrex<=(xcord_second+0.06) && eggcentrey>=(ycord_second+0.06) && eggcentrey<=(ycord_second+0.08))
    {
        if(egginbasketnumber==2)
       life--;          
       else
       points++;
       egginbasketnumber=2;
       eggcentrex=xcord_second+0.03;
       eggcentrey=ycord_second+0.045;
       velocity=VEL;
       flag=false;
       animateFlag=true;
    }
    if(velocity<0 && eggcentrex >=(xcord_third) && eggcentrex<=(xcord_third+0.06) && eggcentrey>=(ycord_third+0.06) && eggcentrey<=(ycord_third+0.08))
    {
       if(egginbasketnumber==3)
       life--;
       else
       points++;
       egginbasketnumber=3;
       eggcentrex=xcord_third+0.03;
       eggcentrey=ycord_third+0.045;
       velocity=VEL;
       flag=false;
       animateFlag=true;
    }
    if(eggcentrey<0.05)
    {
      addToBasket(basketBelow);
      velocity=VEL;
      flag=false;
    }
    }
       
    ellipse(eggcentrex, eggcentrey, 0.015, 0.025);
    
    DrawNum(life,0.025,0.95);
    DrawNum(points,0.87,0.95);
    
    if(life<=0)
    { 
      life=3;
      gameoverflag=true;
    }
    if(egginbasketnumber==basketAbove)
      slideFlag=true;
    
    if(animateFlag==true)
    { 
     if(egginbasketnumber==1)
     {
      if(animateCount<=20)
        y_dist=(animateCount/1200.0);
      else
        y_dist=y_dist-(1/1300.0);
     
     ellipseSize=1;
     ellipse(xcord_first+0.03+(animateCount/500.0),ycord_first+0.03+y_dist,0.005,0.002);
     ellipse(xcord_first+0.03-(animateCount/500.0),ycord_first+0.03+y_dist,0.005,0.002);
     
     ellipse(xcord_first+0.03+(animateCount/700.0),ycord_first+0.03+y_dist,0.005,0.002);
     ellipse(xcord_first+0.03-(animateCount/700.0),ycord_first+0.03+y_dist,0.005,0.002);
     
     ellipse(xcord_first+0.03+(animateCount/600.0),ycord_first+0.03+y_dist+0.008,0.005,0.002);
     ellipse(xcord_first+0.03-(animateCount/600.0),ycord_first+0.03+y_dist+0.008,0.005,0.002);
     ellipseSize=2;
     }
     
     if(egginbasketnumber==2)
     {
      if(animateCount<=20)
        y_dist=(animateCount/1200.0);
      else
        y_dist=y_dist-(1/1300.0);
     
     ellipseSize=1;
     ellipse(xcord_second+0.03+(animateCount/500.0),ycord_second+0.03+y_dist,0.005,0.002);
     ellipse(xcord_second+0.03-(animateCount/500.0),ycord_second+0.03+y_dist,0.005,0.002);
     
     ellipse(xcord_second+0.03+(animateCount/700.0),ycord_second+0.03+y_dist,0.005,0.002);
     ellipse(xcord_second+0.03-(animateCount/700.0),ycord_second+0.03+y_dist,0.005,0.002);
     
     ellipse(xcord_second+0.03+(animateCount/600.0),ycord_second+0.03+y_dist+0.008,0.005,0.002);
     ellipse(xcord_second+0.03-(animateCount/600.0),ycord_second+0.03+y_dist+0.008,0.005,0.002);
     ellipseSize=2;
     }
     
     if(egginbasketnumber==3)
     {
      if(animateCount<=20)
        y_dist=(animateCount/1200.0);
      else
        y_dist=y_dist-(1/1300.0);
     
     ellipseSize=1;
     ellipse(xcord_third+0.03+(animateCount/500.0),ycord_third+0.03+y_dist,0.005,0.002);
     ellipse(xcord_third+0.03-(animateCount/500.0),ycord_third+0.03+y_dist,0.005,0.002);
     
     ellipse(xcord_third+0.03+(animateCount/700.0),ycord_third+0.03+y_dist,0.005,0.002);
     ellipse(xcord_third+0.03-(animateCount/700.0),ycord_third+0.03+y_dist,0.005,0.002);
         
     ellipse(xcord_third+0.03+(animateCount/600.0),ycord_third+0.03+y_dist+0.008,0.005,0.002);
     ellipse(xcord_third+0.03-(animateCount/600.0),ycord_third+0.03+y_dist+0.008,0.005,0.002);
     ellipseSize=2;
     }
     
     animateCount++;
     if(animateCount>30){
         animateCount=0;
         animateFlag=false;
     }
    }
    glutSwapBuffers();
	glutPostRedisplay();
  }
}
 

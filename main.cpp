#include <iostream>
using namespace std;

#include <GL/gl.h>

#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>
void display();
void reshape(int w,int h);
void timer(int);

float i=0,p,cx=0,cy=0,cz=0,vx=0,vy=0,vz=0,mx,mz;

float step=0;
//----------------------keyboard--------------------------
void keyboard(unsigned char Key,int x,int y)
    {
   if(Key=='w'){cx-=100;} if(Key=='s'){cx+=100;}//forward and back   moving
    if(Key=='d'){cz-=100;} if(Key=='a'){cz+=100;}//left and right    moving
     if(Key=='W'){cx-=100;} if(Key=='S'){cx+=100;}//forward and back   moving
    if(Key=='D'){cz-=100;} if(Key=='A'){cz+=100;}//left and right    moving
    if(Key=='8'){vz-=10;} if(Key=='2'){vz+=10;}//forward and back // angle
    if(Key=='4'){vx-=10;} if(Key=='6'){vx+=10;}//left and right   // angle
    if(Key=='i'){mz-=50;} if(Key=='k'){mz+=50;}//forward and back // test position of things
    if(Key=='j'){mx-=50;} if(Key=='l'){mx+=50;}//left and right  // test position of things
    if(Key=='-'){p-=0.1;} if(Key=='+'){p+=0.1;}//zooming
    glutPostRedisplay();
    }


float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;

//---------------------mouse-------------
void onMouseClick(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    {

        cx-=100;
    }
}

//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
//----------------------------------------------------
void init(){
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1000,1000,-1000,1000,-1000,1000);
    glMatrixMode(GL_MODELVIEW);

}
//---------------------------------------car----------------------------------

void front()
{
    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(-450+cx,-250,0+cz);
    glScalef(1.01,0.3,0.85);
    glutSolidCube(600);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-370+cx,-70,0+cz);
    glRotatef(-45,0,0,1);
    glScalef(0.01,0.4,0.85);
    glutWireCube(600);
    glPopMatrix();
}
void back()
{
    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(450+cx,-250,0+cz);
    glScalef(1.01,0.3,0.85);
    glutSolidCube(600);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(380+cx,-80,0+cz);
    glRotatef(38,0,0,1);
    glScalef(0.01,0.35,0.85);
    glutSolidCube(600);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();
}
void top()
{
    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(15+cx,20,0+cz);
    glScalef(1,0.01,0.85);
    glutSolidCube(600);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();
}
void bottom()
{
     glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(0+cx,-340,0+cz);
    glScalef(2.5,0.01,0.85);
    glutSolidCube(600);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();
}
void left()
{
    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(0+cx,-250,250+cz);
    glScalef(2.5,0.3,0.01);
    glutSolidCube(600);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();
}
void right()
{
    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(0+cx,-250,-250+cz);
    glScalef(2.5,0.3,0.01);
    glutSolidCube(600);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();
}
void wheel(int x , int y , int z)
{
    float th;
    glColor3f(0.4,0.4,0.4);
    int j;
    for(j=0;j<50;j+=10)
    {

        glBegin(GL_POLYGON);
        for(int i=0;i<360;i++)
        {
            th=i*3.142/180;
            glVertex3f(x+140*cos(th),y+140*sin(th),z+j);
        }
    glEnd();
}
}
void boarder()
{
    glPushMatrix();
    glTranslatef(-50+cx,-160,250+cz);
    glScalef(0.01,0.6,0.01);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50+cx,-160,-250+cz);
    glScalef(0.01,0.6,0.01);
    glColor3f(1,1,1);
    glutWireCube(600);
    glPopMatrix();
}
void car()
{

    front();
    back();
    top();
    bottom();
    left();
    right();
    wheel(-300+cx,-400,200+cz);
    wheel(300+cx,-400,200+cz);
    wheel(-300+cx,-400,-200+cz);
    wheel(300+cx,-400,-200+cz);
    boarder();
}
void street()
{
    //----rseef---------------------
    glPushMatrix();
    glColor3f(0,0.5,0);
    glTranslatef(0,-500,-1300);
    glScalef(2000.5,0.8,0.8);
    glutSolidCube(600);

    glPopMatrix();
    //bridge
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(90,0,1,0);
    glTranslatef(0,-50,4500);
    glScalef(150.5,100.8,150.8);
    glutSolidTorus(1,10,80,80);
    glColor3f(1,1,1);
    glutWireTorus(1,10,5,80);
    glPopMatrix();
    //end bridge
    //cones
     //
    glPushMatrix();
    glColor3f(0.8,0.4,0);
    glRotatef(-90,1,0,0);
    glTranslatef(-7000,-1000,-500);
    glScalef(1.5,0.8,0.3);
    glutSolidCone(100,1000,5200,2000);

    glPopMatrix();
    //
    //
    glPushMatrix();
    glColor3f(0.8,0.4,0);
    glRotatef(-90,1,0,0);
    glTranslatef(-7000,1000,-500);
    glScalef(1.5,0.8,0.3);
    glutSolidCone(100,1000,5200,2000);

    glPopMatrix();
    //
    //
    glPushMatrix();
    glColor3f(0.8,0.4,0);
    glRotatef(-90,1,0,0);
    glTranslatef(-7000,-50,-500);
    glScalef(1.5,0.8,0.3);
    glutSolidCone(100,1000,5200,2000);

    glPopMatrix();
    //
     //
    glPushMatrix();
    glColor3f(0.8,0.4,0);
    glRotatef(-90,1,0,0);
    glTranslatef(7000,-1000,-500);
    glScalef(1.5,0.8,0.3);
    glutSolidCone(100,1000,5200,2000);

    glPopMatrix();
    //
    //
    glPushMatrix();
    glColor3f(0.8,0.4,0);
    glRotatef(-90,1,0,0);
    glTranslatef(7000,1000,-500);
    glScalef(1.5,0.8,0.3);
    glutSolidCone(100,1000,5200,2000);

    glPopMatrix();
    //
    //
    glPushMatrix();
    glColor3f(0.8,0.4,0);
    glRotatef(-90,1,0,0);
    glTranslatef(7000,-50,-500);
    glScalef(1.5,0.8,0.3);
    glutSolidCone(100,1000,5200,2000);

    glPopMatrix();
    //
    //end cones
    glPushMatrix();
    glColor3f(0,0.5,0);
    glTranslatef(0,-500,1300);
    glScalef(2000.5,0.8,0.8);
    glutSolidCube(600);


    glPopMatrix();
    //-------------------------------------
    //-------------------------------street----------------------------------------
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0,-570,-0);
    glScalef(2000.5,0.3,5.01);
    glutSolidCube(600);


    glPopMatrix();

    //--------------------------------------------------------------------------------------

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(8000,-470,0);
    glVertex3f(8000,-470,150);
    glVertex3f(7000,-470,150);
    glVertex3f(7000,-470,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(6000,-470,0);
    glVertex3f(6000,-470,150);
    glVertex3f(5000,-470,150);
    glVertex3f(5000,-470,0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(2000,-470,0);
    glVertex3f(2000,-470,150);
    glVertex3f(1000,-470,150);
    glVertex3f(1000,-470,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-4000,-470,0);
    glVertex3f(-4000,-470,150);
    glVertex3f(-3000,-470,150);
    glVertex3f(-3000,-470,0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-8000,-470,0);
    glVertex3f(-8000,-470,150);
    glVertex3f(-7000,-470,150);
    glVertex3f(-7000,-470,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-6000,-470,0);
    glVertex3f(-6000,-470,150);
    glVertex3f(-5000,-470,150);
    glVertex3f(-5000,-470,0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-2000,-470,0);
    glVertex3f(-2000,-470,150);
    glVertex3f(-1000,-470,150);
    glVertex3f(-1000,-470,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(4000,-470,0);
    glVertex3f(4000,-470,150);
    glVertex3f(3000,-470,150);
    glVertex3f(3000,-470,0);

    glEnd();




}
void buildr()
{
   glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-450,350,-1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(600,150,-1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-1450,350,-1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-2450,150,-1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();
    //-----------------
     glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-3450,350,-1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(1600,150,-1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-4450,350,-1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-5450,150,-1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-450,350,-1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(600,150,-1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-1450,350,-1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-2450,150,-1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();
    //-----------------
     glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(3600,350,-1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(2600,150,-1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(5650,350,-1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(6650,150,-1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();
}
void buildl()
{



   glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-450,350,1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(600,150,1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-1450,350,1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

 glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-2450,150,1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();
    //-----------------
     glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-3450,350,1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

 glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(1600,150,1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-4450,350,1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

 glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-5450,150,1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
    glColor3f(1,1,1);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-450,350,1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(600,150,1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(-1450,350,1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-2450,150,1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();
    //-----------------
     glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(3600,350,1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(2600,150,1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(5650,350,1500);
    glScalef(1.5,3.3,0.5);
    glutSolidCube(600);
    glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(6650,150,1500);
    glScalef(1.5,2.3,0.5);
    glutSolidCube(600);
     glColor3f(0,0,0);
    glutWireCube(600);
    glPopMatrix();
}
void treer()
 {
     glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100, -100.0f, 100-1200);

      glVertex3f(150, -100.0f, 100-1200);
      // Right

      glVertex3f(0.0f, 500.0f, 0.0f-1200);

      glVertex3f(100, -100.0f, 100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100, -100.0f, -100-1200);

            // back

      glVertex3f( 0.0f, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100, -100.0f, -100-1200);

      glVertex3f(100, -100.0f, -100-1200);

      // Right

      glVertex3f(0, 500.0f, 0-1200);

      glVertex3f(-100, -100.0f, -100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100, -100.0f, 100-1200);


   glEnd();
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f+2650, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+2650, -100.0f, 100-1200);

      glVertex3f(150+2650, -100.0f, 100-1200);
      // Right

      glVertex3f(0.0f+2650, 500.0f, 0.0f-1200);

      glVertex3f(100+2650, -100.0f, 100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100+2650, -100.0f, -100-1200);

            // back

      glVertex3f( 0.0f+2650, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+2650, -100.0f, -100-1200);

      glVertex3f(100+2650, -100.0f, -100-1200);

      // Right

      glVertex3f(0+2650, 500.0f, 0-1200);

      glVertex3f(-100+2650, -100.0f, -100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+2650, -100.0f, 100-1200);


   glEnd();
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f+5300, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+5300, -100.0f, 100-1200);

      glVertex3f(150+5300, -100.0f, 100-1200);
      // Right

      glVertex3f(0.0f+5300, 500.0f, 0.0f-1200);

      glVertex3f(100+5300, -100.0f, 100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100+5300, -100.0f, -100-1200);

            // back

      glVertex3f( 0.0f+5300, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+5300, -100.0f, -100-1200);

      glVertex3f(100+5300, -100.0f, -100-1200);

      // Right

      glVertex3f(0+5300, 500.0f, 0-1200);

      glVertex3f(-100+5300, -100.0f, -100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+5300, -100.0f, 100-1200);


   glEnd();
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f+2650, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+2650, -100.0f, 100-1200);

      glVertex3f(150+2650, -100.0f, 100-1200);
      // Right

      glVertex3f(0.0f-2650, 500.0f, 0.0f-1200);

      glVertex3f(100-2650, -100.0f, 100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100-2650, -100.0f, -100-1200);

            // back

      glVertex3f( 0.0f-2650, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-2650, -100.0f, -100-1200);

      glVertex3f(100-2650, -100.0f, -100-1200);

      // Right

      glVertex3f(0-2650, 500.0f, 0-1200);

      glVertex3f(-100-2650, -100.0f, -100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-2650, -100.0f, 100-1200);


   glEnd();
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f-5300, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-5300, -100.0f, 100-1200);

      glVertex3f(150-5300, -100.0f, 100-1200);
      // Right

      glVertex3f(0.0f-5300, 500.0f, 0.0f-1200);

      glVertex3f(100-5300, -100.0f, 100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100-5300, -100.0f, -100-1200);

            // back

      glVertex3f( 0.0f-5300, 500.0f, 0.0f-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-5300, -100.0f, -100-1200);

      glVertex3f(100-5300, -100.0f, -100-1200);

      // Right

      glVertex3f(0-5300, 500.0f, 0-1200);

      glVertex3f(-100-5300, -100.0f, -100-1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-5300, -100.0f, 100-1200);


   glEnd();
 }
void treel()
 {
     glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100, -100.0f, 100+1200);

      glVertex3f(150, -100.0f, 100+1200);
      // Right

      glVertex3f(0.0f, 500.0f, 0.0f+1200);

      glVertex3f(100, -100.0f, 100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100, -100.0f, -100+1200);

            // back

      glVertex3f( 0.0f, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100, -100.0f, -100+1200);

      glVertex3f(100, -100.0f, -100+1200);

      // Right

      glVertex3f(0, 500.0f, 0+1200);

      glVertex3f(-100, -100.0f, -100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100, -100.0f, 100+1200);


   glEnd();
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f+2650, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+2650, -100.0f, 100+1200);

      glVertex3f(150+2650, -100.0f, 100+1200);
      // Right

      glVertex3f(0.0f+2650, 500.0f, 0.0f+1200);

      glVertex3f(100+2650, -100.0f, 100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100+2650, -100.0f, -100+1200);

            // back

      glVertex3f( 0.0f+2650, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+2650, -100.0f, -100+1200);

      glVertex3f(100+2650, -100.0f, -100+1200);

      // Right

      glVertex3f(0+2650, 500.0f, 0+1200);

      glVertex3f(-100+2650, -100.0f, -100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+2650, -100.0f, 100+1200);


   glEnd();
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f+5300, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+5300, -100.0f, 100+1200);

      glVertex3f(150+5300, -100.0f, 100+1200);
      // Right

      glVertex3f(0.0f+5300, 500.0f, 0.0f+1200);

      glVertex3f(100+5300, -100.0f, 100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100+5300, -100.0f, -100+1200);

      // back

      glVertex3f( 0.0f+5300, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+5300, -100.0f, -100+1200);

      glVertex3f(100+5300, -100.0f, -100+1200);

      // Right

      glVertex3f(0+5300, 500.0f, 0+1200);

      glVertex3f(-100+5300, -100.0f, -100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+5300, -100.0f, 100+1200);


   glEnd();
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f+2650, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100+2650, -100.0f, 100+1200);

      glVertex3f(150+2650, -100.0f, 100+1200);
      // Right

      glVertex3f(0.0f-2650, 500.0f, 0.0f+1200);

      glVertex3f(100-2650, -100.0f, 100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100-2650, -100.0f, -100+1200);

            // back

      glVertex3f( 0.0f-2650, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-2650, -100.0f, -100+1200);

      glVertex3f(100-2650, -100.0f, -100+1200);

      // Right

      glVertex3f(0-2650, 500.0f, 0+1200);

      glVertex3f(-100-2650, -100.0f, -100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-2650, -100.0f, 100+1200);


   glEnd();
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front

      glVertex3f( 0.0f-5300, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-5300, -100.0f, 100+1200);

      glVertex3f(150-5300, -100.0f, 100+1200);
      // Right

      glVertex3f(0.0f-5300, 500.0f, 0.0f+1200);

      glVertex3f(100-5300, -100.0f, 100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(100-5300, -100.0f, -100+1200);

            // back

      glVertex3f( 0.0f-5300, 500.0f, 0.0f+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-5300, -100.0f, -100+1200);

      glVertex3f(100-5300, -100.0f, -100+1200);

      // Right

      glVertex3f(0-5300, 500.0f, 0+1200);

      glVertex3f(-100-5300, -100.0f, -100+1200);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-100-5300, -100.0f, 100+1200);


   glEnd();
 }
void treelegl()
{
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+5300,100.0,-100.0+1270);
    glVertex3f(-50.0+50+5300,-500.0,-100.0+1270);
    glVertex3f(0.0+50+5300,-500.0,-100.0+1270);
    glVertex3f(0.0+50+5300,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+5300,100.0,-50.0+1270);
    glVertex3f(-50.0+50+5300,-500.0,-50.0+1270);
    glVertex3f (0.0+50+5300,-500.0,-50.0+1270);
    glVertex3f(0.0+50+5300,100.0,-50+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50+5300,100.0,-50.0+1270);
    glVertex3f(0.0+50+5300,-500.0,-50.0+1270);
    glVertex3f(0.0+50+5300,-500.0,-100.0+1270);
    glVertex3f(0.0+50+5300,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+5300,100.0,-50.0+1270);
    glVertex3f(-50.0+50+5300,-500.0,-50.0+1270);
    glVertex3f(-50.0+50+5300,-500.0,-100.0+1270);
    glVertex3f(-50.0+50+5300,100.0,-100.0+1270);


    glEnd();

    //-------------------------------------
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50,100.0,-100.0+1270);
    glVertex3f(-50.0+50,-500.0,-100.0+1270);
    glVertex3f(0.0+50,-500.0,-100.0+1270);
    glVertex3f(0.0+50,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50,100.0,-50.0+1270);
    glVertex3f(-50.0+50,-500.0,-50.0+1270);
    glVertex3f (0.0+50,-500.0,-50.0+1270);
    glVertex3f(0.0+50,100.0,-50+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50,100.0,-50.0+1270);
    glVertex3f(0.0+50,-500.0,-50.0+1270);
    glVertex3f(0.0+50,-500.0,-100.0+1270);
    glVertex3f(0.0+50,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50,100.0,-50.0+1270);
    glVertex3f(-50.0+50,-500.0,-50.0+1270);
    glVertex3f(-50.0+50,-500.0,-100.0+1270);
    glVertex3f(-50.0+50,100.0,-100.0+1270);


    glEnd();

    //-------------------------------------
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-5300,100.0,-100.0+1270);
    glVertex3f(-50.0+50-5300,-500.0,-100.0+1270);
    glVertex3f(0.0+50-5300,-500.0,-100.0+1270);
    glVertex3f(0.0+50-5300,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-5300,100.0,-50.0+1270);
    glVertex3f(-50.0+50-5300,-500.0,-50.0+1270);
    glVertex3f (0.0+50-5300,-500.0,-50.0+1270);
    glVertex3f(0.0+50-5300,100.0,-50+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50-5300,100.0,-50.0+1270);
    glVertex3f(0.0+50-5300,-500.0,-50.0+1270);
    glVertex3f(0.0+50-5300,-500.0,-100.0+1270);
    glVertex3f(0.0+50-5300,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-5300,100.0,-50.0+1270);
    glVertex3f(-50.0+50-5300,-500.0,-50.0+1270);
    glVertex3f(-50.0+50-5300,-500.0,-100.0+1270);
    glVertex3f(-50.0+50-5300,100.0,-100.0+1270);


    glEnd();

    //-------------------------------------
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+2650,100.0,-100.0+1270);
    glVertex3f(-50.0+50+2650,-500.0,-100.0+1270);
    glVertex3f(0.0+50+2650,-500.0,-100.0+1270);
    glVertex3f(0.0+50+2650,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+2650,100.0,-50.0+1270);
    glVertex3f(-50.0+50+2650,-500.0,-50.0+1270);
    glVertex3f (0.0+50+2650,-500.0,-50.0+1270);
    glVertex3f(0.0+50+2650,100.0,-50+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50+2650,100.0,-50.0+1270);
    glVertex3f(0.0+50+2650,-500.0,-50.0+1270);
    glVertex3f(0.0+50+2650,-500.0,-100.0+1270);
    glVertex3f(0.0+50+2650,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+2650,100.0,-50.0+1270);
    glVertex3f(-50.0+50+2650,-500.0,-50.0+1270);
    glVertex3f(-50.0+50+2650,-500.0,-100.0+1270);
    glVertex3f(-50.0+50+2650,100.0,-100.0+1270);


    glEnd();

    //-------------------------------------
    //-------------------------------------
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-2650,100.0,-100.0+1270);
    glVertex3f(-50.0+50-2650,-500.0,-100.0+1270);
    glVertex3f(0.0+50-2650,-500.0,-100.0+1270);
    glVertex3f(0.0+50-2650,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-2650,100.0,-50.0+1270);
    glVertex3f(-50.0+50-2650,-500.0,-50.0+1270);
    glVertex3f (0.0+50-2650,-500.0,-50.0+1270);
    glVertex3f(0.0+50-2650,100.0,-50+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50-2650,100.0,-50.0+1270);
    glVertex3f(0.0+50-2650,-500.0,-50.0+1270);
    glVertex3f(0.0+50-2650,-500.0,-100.0+1270);
    glVertex3f(0.0+50-2650,100.0,-100.0+1270);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-2650,100.0,-50.0+1270);
    glVertex3f(-50.0+50-2650,-500.0,-50.0+1270);
    glVertex3f(-50.0+50-2650,-500.0,-100.0+1270);
    glVertex3f(-50.0+50-2650,100.0,-100.0+1270);


    glEnd();

    //-------------------------------------
}
void treelegr()
{
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+5300,100.0,-100.0-1150);
    glVertex3f(-50.0+50+5300,-500.0,-100.0-1150);
    glVertex3f(0.0+50+5300,-500.0,-100.0-1150);
    glVertex3f(0.0+50+5300,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+5300,100.0,-50.0-1150);
    glVertex3f(-50.0+50+5300,-500.0,-50.0-1150);
    glVertex3f (0.0+50+5300,-500.0,-50.0-1150);
    glVertex3f(0.0+50+5300,100.0,-50-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50+5300,100.0,-50.0-1150);
    glVertex3f(0.0+50+5300,-500.0,-50.0-1150);
    glVertex3f(0.0+50+5300,-500.0,-100.0-1150);
    glVertex3f(0.0+50+5300,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+5300,100.0,-50.0-1150);
    glVertex3f(-50.0+50+5300,-500.0,-50.0-1150);
    glVertex3f(-50.0+50+5300,-500.0,-100.0-1150);
    glVertex3f(-50.0+50+5300,100.0,-100.0-1150);


    glEnd();

    //-------------------------------------
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50,100.0,-100.0-1150);
    glVertex3f(-50.0+50,-500.0,-100.0-1150);
    glVertex3f(0.0+50,-500.0,-100.0-1150);
    glVertex3f(0.0+50,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50,100.0,-50.0-1150);
    glVertex3f(-50.0+50,-500.0,-50.0-1150);
    glVertex3f (0.0+50,-500.0,-50.0-1150);
    glVertex3f(0.0+50,100.0,-50-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50,100.0,-50.0-1150);
    glVertex3f(0.0+50,-500.0,-50.0-1150);
    glVertex3f(0.0+50,-500.0,-100.0-1150);
    glVertex3f(0.0+50,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50,100.0,-50.0-1150);
    glVertex3f(-50.0+50,-500.0,-50.0-1150);
    glVertex3f(-50.0+50,-500.0,-100.0-1150);
    glVertex3f(-50.0+50,100.0,-100.0-1150);


    glEnd();

    //-------------------------------------
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-5300,100.0,-100.0-1150);
    glVertex3f(-50.0+50-5300,-500.0,-100.0-1150);
    glVertex3f(0.0+50-5300,-500.0,-100.0-1150);
    glVertex3f(0.0+50-5300,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-5300,100.0,-50.0-1150);
    glVertex3f(-50.0+50-5300,-500.0,-50.0-1150);
    glVertex3f (0.0+50-5300,-500.0,-50.0-1150);
    glVertex3f(0.0+50-5300,100.0,-50-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50-5300,100.0,-50.0-1150);
    glVertex3f(0.0+50-5300,-500.0,-50.0-1150);
    glVertex3f(0.0+50-5300,-500.0,-100.0-1150);
    glVertex3f(0.0+50-5300,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-5300,100.0,-50.0-1150);
    glVertex3f(-50.0+50-5300,-500.0,-50.0-1150);
    glVertex3f(-50.0+50-5300,-500.0,-100.0-1150);
    glVertex3f(-50.0+50-5300,100.0,-100.0-1150);


    glEnd();

    //-------------------------------------
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+2650,100.0,-100.0-1150);
    glVertex3f(-50.0+50+2650,-500.0,-100.0-1150);
    glVertex3f(0.0+50+2650,-500.0,-100.0-1150);
    glVertex3f(0.0+50+2650,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+2650,100.0,-50.0-1150);
    glVertex3f(-50.0+50+2650,-500.0,-50.0-1150);
    glVertex3f (0.0+50+2650,-500.0,-50.0-1150);
    glVertex3f(0.0+50+2650,100.0,-50-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50+2650,100.0,-50.0-1150);
    glVertex3f(0.0+50+2650,-500.0,-50.0-1150);
    glVertex3f(0.0+50+2650,-500.0,-100.0-1150);
    glVertex3f(0.0+50+2650,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50+2650,100.0,-50.0-1150);
    glVertex3f(-50.0+50+2650,-500.0,-50.0-1150);
    glVertex3f(-50.0+50+2650,-500.0,-100.0-1150);
    glVertex3f(-50.0+50+2650,100.0,-100.0-1150);


    glEnd();

    //-------------------------------------
    //-------------------------------------
    glBegin (GL_QUADS) ;

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-2650,100.0,-100.0-1150);
    glVertex3f(-50.0+50-2650,-500.0,-100.0-1150);
    glVertex3f(0.0+50-2650,-500.0,-100.0-1150);
    glVertex3f(0.0+50-2650,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-2650,100.0,-50.0-1150);
    glVertex3f(-50.0+50-2650,-500.0,-50.0-1150);
    glVertex3f (0.0+50-2650,-500.0,-50.0-1150);
    glVertex3f(0.0+50-2650,100.0,-50-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(0.0+50-2650,100.0,-50.0-1150);
    glVertex3f(0.0+50-2650,-500.0,-50.0-1150);
    glVertex3f(0.0+50-2650,-500.0,-100.0-1150);
    glVertex3f(0.0+50-2650,100.0,-100.0-1150);

    glColor3f(0.2,0.0,0.0);
    glVertex3f(-50.0+50-2650,100.0,-50.0-1150);
    glVertex3f(-50.0+50-2650,-500.0,-50.0-1150);
    glVertex3f(-50.0+50-2650,-500.0,-100.0-1150);
    glVertex3f(-50.0+50-2650,100.0,-100.0-1150);


    glEnd();

    //-------------------------------------
}
void clouds()
{
    //CLOUD
     /////////////////////////////////////
    glColor3f(1,1,1);
    glPushMatrix ();
       glTranslatef    (150+step, 3500, -800.0);
       glRotatef       (60.0, 1,0,0);
      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(300,1000, 500);
    glPopMatrix ();
//////////////////////////////////////////////////
       glPushMatrix ();
       glTranslatef    (-100+step, 3500, -800.0);
       glRotatef       (60.0, 1,0,0);
      //glRotatef       (zRotated, 0,0,1);
       glutSolidSphere(300,1000, 500);
    glPopMatrix ();
    /////////////////////////
     glPushMatrix ();
       glTranslatef    (-400+step, 3500, -800.0);
       glRotatef       (60.0, 1,0,0);
      //glRotatef       (zRotated, 0,0,1);
       glutSolidSphere(300,1000, 500);
    glPopMatrix ();
    //END CLOUD
    glColor3f(1,1,1);
    glPushMatrix ();
       glTranslatef    (150-step, 2500, 800.0);
       glRotatef       (60.0, 1,0,0);
      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(300,1000, 500);
    glPopMatrix ();
//////////////////////////////////////////////////
       glPushMatrix ();
       glTranslatef    (-100-step, 2500, 800.0);
       glRotatef       (60.0, 1,0,0);
      //glRotatef       (zRotated, 0,0,1);
       glutSolidSphere(300,1000, 500);
    glPopMatrix ();
    /////////////////////////
     glPushMatrix ();
       glTranslatef    (-400-step, 2500, 800.0);
       glRotatef       (60.0, 1,0,0);
      //glRotatef       (zRotated, 0,0,1);
       glutSolidSphere(300,1000, 500);
    glPopMatrix ();
    //glutSwapBuffers();
    glutPostRedisplay();
}
//------------------------------  display   -------------------------------
float theta;
void display (void)
{
    theta+=0.1;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(vz,1,0,0);//rotate it up down
    glRotatef(vx,0,1,0);//rotate it right left
    glScalef(0.1+p,0.1+p,0.1+p);
    street();
    car();
    treel();
    treer();
    treelegl();
    treelegr();
    buildr();
    buildl();
    clouds();

    //car2();




	//Your code is written here



    glutSwapBuffers();
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

//----------------------------------  main  ------------------------------------
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    if(step<4000 ){
	step+=1 ;


	}

}




int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); // buffer mode
    glutInitWindowPosition (0,0);
    glutInitWindowSize(1080,1020);
    glutCreateWindow("20101589");
    init();
    glutKeyboardFunc(keyboard);
    glutMouseFunc(onMouseClick);
    //sndPlaySound("background.way",SND_ASYNC|SND_LOOP);   //sound while running
    glutDisplayFunc (display);
    glEnable(GL_DEPTH_TEST);
     glutTimerFunc(0,timer,0);
    glutMainLoop();

    texture();

}

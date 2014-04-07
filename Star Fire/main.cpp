//
//  main.cpp
//  Star Fire
//
//  Created by La Li Lu Le Lo on 2014-04-01.
//  Copyright (c) 2014 Eric Boisvert. All rights reserved.
//

#include <iostream>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "glm.h"

#include "airWing.h"
#include "enemy.h"
//#include "models.h"


using namespace std;

//Global Variables
float width = 1024;
float height = 768;

int is_depth; /* depth testing flag */
int counterTerrainRepeat = 0;

airWing player = *new airWing(100,0,1,3);
enemy yannis = *new enemy(200,500,2,1); // parameters = hp,shield,atkPow,bombs


GLMmodel* playerArwing;


GLuint model;
float modelCoord;
int fps=0, displayList=0;





void printData()
{
    cout << "X-Coord: " << player.getAirWingXpos() << ", Y-Coord: " << player.getAirWingYpos() << ", Z-Coord: " << player.getAirWingZpos()<< endl;
    
}



 
void Timer(int iUnused)
{
    printData();
    counterTerrainRepeat += 5;
    
    if (counterTerrainRepeat >= 500) {
        glTranslatef(0.0f, 0.0f, -500.f);
        player.resetZcoord();
        counterTerrainRepeat = 0;
    }
    
    player.setZcoord(-5.0f);
    glTranslatef(0.0f, 0.0f, 5.0f);
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}



void resize(int width, int height)
{
	if (height == 0) height = 1;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    
	/* note we divide our width by our height to get the aspect ratio */
	gluPerspective(45.0, width / height, 1.0, 400.0);
    
	/* set initial position */
	glTranslatef(0.0, -5.0, -150.0);
    
	glMatrixMode(GL_MODELVIEW);
}

void drawLevel()
{

	 /*draw the floor clockwise upleft down left down right upright*/
	glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-50.0, -1.0, -1000.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-50.0, -1.0, 1000.0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(50.0, -1.0, 1000.0);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(50.0, -1.0, -1000.0);
	glEnd();

}


void drawAirwing()
{
    
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glLoadIdentity();
	/*gluLookAt(15.0, 30.0,	15.0,
			  0.0,	5.0,	0.0,
		      0.0f,	1.0f,	0.0f);
	*/
	//glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
    //glColor3f(0, 1, 0);
    glScaled(0.1, 0.1, 0.1);
    glTranslatef(0.0f, 0.0f, -130.0f);
    glRotated(180, 0, 1, 0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glTranslatef(0,0,120);
	//(graus, 1.0, 0.0, 0.0);

	glCallList(displayList);
	//glutSwapBuffers();

    

}

void drawLaser()
{
    // White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
    
    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();
    
    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();
    
    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    //glFlush();
    
    //glutSwapBuffers();

    
}

void draw()
{
    
	if (is_depth)
    {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
	else
    {
		glClear(GL_COLOR_BUFFER_BIT);
    }
    
    glPushMatrix();
    drawLevel();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(player.getAirWingXpos(),player.getAirWingYpos(),player.getAirWingZpos()); // player airwing position
    glScalef(0.1, 0.1, 0.1);
    drawAirwing();
    glPopMatrix();
    
    //glutPostRedisplay();
    glutSwapBuffers();

    
}


void airwingControl(unsigned char key, int x, int y){
    
    /* This time the controls are:
     
     "a": move left
     "d": move right
     "w": move forward
     "s": move back
     "t": toggle depth-testing
     
     */
	switch (key)
	{
        case ' ':
            glPushMatrix();
            glTranslatef(0, 2, 0);
            glScalef(1, 1, 1);
            drawLaser();
            glPopMatrix();
            break;
            
        case 'a':
        case 'A':
            //glTranslatef(5.0, 0.0, 0.0);
                player.setXcoord(-1.0f);
            break;
        case 'd':
        case 'D':
            player.setXcoord(1.0f);
            break;
        case 'w':
        case 'W':
            //glTranslatef(0.0, 0.0, 5.0);
            player.setYcoord(1.0f);
            break;
        case 's':
        case 'S':
            //glTranslatef(0.0, 0.0, -5.0);
            player.setYcoord(-1.0f);
            break;
        case 't':
        case 'T':
            if (is_depth)
            {
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
	}
    glutPostRedisplay();

	draw();
    
    
    
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
}






/* initialize GLUT settings, register callbacks, enter main loop */
int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Star Fire");
    // register glut call backs
    glutDisplayFunc(draw);
    //glutIdleFunc(draw);
    glutKeyboardFunc(airwingControl);
    Timer(0);
    init();
    glutReshapeFunc(resize);
    playerArwing = (GLMmodel*)malloc(sizeof(GLMmodel));
	playerArwing = glmReadOBJ("/Users/eboisvert/Documents/C++/Star Fire/Star Fire/Arwing.obj");
	
	displayList=glGenLists(1);
	glNewList(displayList,GL_COMPILE);
    //glmList(playerArwing, GLM_SMOOTH);
    glmDraw(playerArwing, GLM_SMOOTH);
	glEndList();
    
    glutMainLoop();
    return 0;
}
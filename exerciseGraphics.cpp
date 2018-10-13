// exerciseGraphics.cpp : Defines the entry point for the console application.
//
#include "pch.h" //default precompiled headers
//#include "stdafx.h"//default precompiled headers
//you should include only one of the previous libraries, it depends on the version of Visual Srudio, for me pch.h works well with VS 2017
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
//VARIABLES
//Screen size
int screenx = 500;
int screeny = 500;

float step = 0.1f;
float angle = 30.f;
float scale = 1.0f;
float x = 0.;
float y = 0.;
/********************************************************************************************/
//prototype
void initRendering();
void handleResize(int w, int h);
void handleKeypress(unsigned char key, int x, int y);
void processSpecialKeys(int key, int mx, int my);
void drawTriangle();
void drawScene();
/*****************************************************************************************************/



int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screenx, screeny);
	glutInitWindowPosition(0, 0);
	//Create the window
	glutCreateWindow(" Transformations ");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	//glutTimerFunc(25, update, 0); //Add a timer
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h); //set the viewport
	glMatrixMode(GL_PROJECTION);//Switch to the Camera perspective
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
		break;

	}
}
//handling special keys
void processSpecialKeys(int key, int mx, int my) {
	switch (key) {
	case GLUT_KEY_LEFT: //move left
		x -= step;
		glutPostRedisplay(); // use to display changes on screen
		break;
	case GLUT_KEY_RIGHT: //move right
		x += step;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP: //move up
		y += step;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN: // move down
		y -= step;
		glutPostRedisplay();
		break;
	case GLUT_KEY_HOME: // to rotate clockwise
		angle += 2.0f;
		if (angle > 360)
			angle -= 360;
		glutPostRedisplay();
		break;
	case GLUT_KEY_END: // to rotate anti clockwise
		angle -= 2.0f;
		if (angle < 360)
			angle += 360;
		glutPostRedisplay();
		break;
		if (scale <= 2) {
	case GLUT_KEY_PAGE_UP:  //expand
		scale += 0.2;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN: //shrink
		scale -= 0.2;
		glutPostRedisplay();
		break;
		}
	default:
		break;
	}
}
//drawing the triangle
void drawTriangle() {
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, -1.f, -5.0f);
	glVertex3f(.5f, 1.f, -5.0f);
	glVertex3f(-1.f, -1.f, -5.0f);
	glEnd();
}
//drawing the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	/*******************************************************************************/

	glPushMatrix(); //push the current matrix stack
	glColor3f(1, 0, 0); //set a color, can be called before or inside drawTriangle()
	glTranslatef(x, y, -5.);// move to new coordinates, specified by the values of x,y
	glRotatef(angle, 0., 0., 1.);//rotate the shape by angle around z axis
	glScalef(scale, scale, scale);//scale the shape in all the three coordinates by value of scale
	drawTriangle(); //calling the drawTriangle function
	glPopMatrix();//pop the current matrix stack

	/********************************************************************************/
	glutSwapBuffers(); //promotes the contents of the back buffer of the layer in use of the current window to become the contents of the front buffer.
	glFlush(); //force execution of GL commands in finite time

}
#include "pch.h" //default precompiled headers
//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
//VARIABLES
//Screen size
int screenx = 500;
int screeny = 500;

float step = 0.1f;
float angle = 30.f;
float scale = 1.0f;
float x = 0.;
float y = 0.;
/********************************************************************************************/
//prototype
void initRendering();
void handleResize(int w, int h);
void handleKeypress(unsigned char key, int x, int y);
void processSpecialKeys(int key, int mx, int my);
void drawTriangle();
void drawScene();
/*****************************************************************************************************/



int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screenx, screeny);
	glutInitWindowPosition(0, 0);
	//Create the window
	glutCreateWindow(" Transformations ");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	//glutTimerFunc(25, update, 0); //Add a timer
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h); //set the viewport
	glMatrixMode(GL_PROJECTION);//Switch to the Camera perspective
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
		break;

	}
}
//handling special keys
void processSpecialKeys(int key, int mx, int my) {
	switch (key) {
	case GLUT_KEY_LEFT: //move left
		x -= step;
		glutPostRedisplay(); // use to display changes on screen
		break;
	case GLUT_KEY_RIGHT: //move right
		x += step;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP: //move up
		y += step;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN: // move down
		y -= step;
		glutPostRedisplay();
		break;
	case GLUT_KEY_HOME: // to rotate clockwise
		angle += 2.0f;
		if (angle > 360)
			angle -= 360;
		glutPostRedisplay();
		break;
	case GLUT_KEY_END: // to rotate anti clockwise
		angle -= 2.0f;
		if (angle < 360)
			angle += 360;
		glutPostRedisplay();
		break;
		if (scale <= 2) {
	case GLUT_KEY_PAGE_UP:  //expand
		scale += 0.2;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN: //shrink
		scale -= 0.2;
		glutPostRedisplay();
		break;
		}
	default:
		break;
	}
}
//drawing the triangle
void drawTriangle() {
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, -1.f, -5.0f);
	glVertex3f(.5f, 1.f, -5.0f);
	glVertex3f(-1.f, -1.f, -5.0f);
	glEnd();
}
//drawing the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	/*******************************************************************************/

	glPushMatrix(); //push the current matrix stack
	glColor3f(1, 0, 0); //set a color, can be called before or inside drawTriangle()
	glTranslatef(x, y, -5.);// move to new coordinates, specified by the values of x,y
	glRotatef(angle, 0., 0., 1.);//rotate the shape by angle around z axis
	glScalef(scale, scale, scale);//scale the shape in all the three coordinates by value of scale
	drawTriangle(); //calling the drawTriangle function
	glPopMatrix();//pop the current matrix stack

	/********************************************************************************/
	glutSwapBuffers(); //promotes the contents of the back buffer of the layer in use of the current window to become the contents of the front buffer.
	glFlush(); //force execution of GL commands in finite time

}

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

void init(void);
void display(void);

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 750);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Glenn Steven - 672018322");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;
    //ini titik pertama
    glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);

    //ini titik berikutnya
    for(k=0; k<n; k++){
        angle+=angleInc;
        glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
    }
}
void display(void)
{
    int i;
	glClear(GL_COLOR_BUFFER_BIT);
	for(i = 50; i>=0; i--){
	    glColor3f(1-(i*0.0177) , 1-(i*0.0177) , i*0.017);
	    //glColor3f(1-(i*0.0) , 1-(i*0.055) , 1-(i*0.075));
        glBegin(GL_LINE_STRIP);
        ngon(6, 10, 0, i, 170-i);
	}
    glEnd();
	glutSwapBuffers();
}

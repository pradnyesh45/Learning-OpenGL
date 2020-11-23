#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float x_position = -10.0;
int state = 1;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_POLYGON);
    glVertex2f(x_position, 1.0);
    glVertex2f(x_position, -1.0);
    glVertex2f(x_position + 2.0, -1.0);
    glVertex2f(x_position + 2.0, 1.0);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);

    switch (state)
    {
    case 1:
        if (x_position < 0)
        {
            x_position += 0.15;
        }
        else
        {
            state = -1;
        }
        break;
    case -1:
        if (x_position > -10)
        {
            x_position -= 0.15;
        }
        else
        {
            state = 1;
        }
    }
}

void init()
{
    glClearColor(0.0, 0.6, 0.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Real time of scene of people playing football");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
}
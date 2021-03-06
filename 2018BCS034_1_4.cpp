#include <GL/glut.h>

void polySegment()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.8, 0.4, 0.6);
    glTranslatef(5.f, 5.f, 0.f);
    GLfloat m[16] = {
        1.0f, -2.f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f};
    glMultMatrixf(m);
    glTranslatef(-5.f, -5.f, 0.f);

    glBegin(GL_POLYGON);

    int A[] = {3, 1};
    int B[] = {5, 1};
    int C[] = {5, 2};
    int D[] = {3, 2};

    glVertex2iv(A);
    glVertex2iv(B);
    glVertex2iv(C);
    glVertex2iv(D);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2018BCS034_1_4");
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-10, 10.0, -10, 10.0);

    glutDisplayFunc(polySegment);
    glutMainLoop();
}
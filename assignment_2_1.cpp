#include <iostream>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

typedef float Matrix4x4[4][4];
Matrix4x4 theMatrix;
float ptsIni[8][3] = {{2, 1, 1}, {4, 1, 1}, {4, 2, 1}, {2, 2, 1}};
float ptsFin[8][3];
float refptX, refptY, refptZ;             //Reference points
float TransDistX, TransDistY, TransDistZ; //Translations along Axes
float ScaleX, ScaleY, ScaleZ;             //Scaling Factors along Axes
float Alpha, Beta, Gamma, Theta;          //Rotation angles about Axes
float A, B, C;                            //Arbitrary Line Attributes
float aa, bb, cc;                         //Arbitrary Line Attributes
float x1, y11, z1, x2, y2, z2;
int choice, choiceRot, choiceRef;
void matrixSetIdentity(Matrix4x4 m) // Initialises the matrix as Unit Matrix
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            m[i][j] = (i == j);
}

void matrixPreMultiply(Matrix4x4 a, Matrix4x4 b)
{ // Multiplies matrix a times b, putting result in b
    int i, j;
    Matrix4x4 tmp;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            tmp[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            theMatrix[i][j] = tmp[i][j];
}
void Translate(int tx, int ty, int tz)
{
    Matrix4x4 m;
    matrixSetIdentity(m);
    m[0][3] = tx;
    m[1][3] = ty;
    m[2][3] = tz;
    matrixPreMultiply(m, theMatrix);
}
void Scale(float sx, float sy, float sz)
{
    Matrix4x4 m;
    matrixSetIdentity(m);
    m[0][0] = sx;
    m[0][3] = (1 - sx) * refptX;
    m[1][1] = sy;
    m[1][3] = (1 - sy) * refptY;
    m[2][2] = sz;
    m[2][3] = (1 - sy) * refptZ;
    matrixPreMultiply(m, theMatrix);
}
void RotateX(float angle)
{
    Matrix4x4 m;
    matrixSetIdentity(m);
    angle = angle * 22 / 1260;
    m[1][1] = cos(angle);
    m[1][2] = -sin(angle);
    m[2][1] = sin(angle);
    m[2][2] = cos(angle);
    matrixPreMultiply(m, theMatrix);
}
void RotateY(float angle)
{
    Matrix4x4 m;
    matrixSetIdentity(m);
    angle = angle * 22 / 1260;
    m[0][0] = cos(angle);
    m[0][2] = sin(angle);
    m[2][0] = -sin(angle);
    m[2][2] = cos(angle);
    matrixPreMultiply(m, theMatrix);
}
void RotateZ(float angle)
{
    Matrix4x4 m;
    matrixSetIdentity(m);
    angle = angle * 22 / 1260;
    m[0][0] = cos(angle);
    m[0][1] = -sin(angle);
    m[1][0] = sin(angle);
    m[1][1] = cos(angle);
    matrixPreMultiply(m, theMatrix);
}

void DrawRotLine(void)
{
    switch (choiceRot)
    {
    case 1:
        glBegin(GL_LINES);
        glVertex3s(-1000, B, C);
        glVertex3s(1000, B, C);
        glEnd();
        break;
    case 2:
        glBegin(GL_LINES);
        glVertex3s(A, -1000, C);
        glVertex3s(A, 1000, C);
        glEnd();
        break;
    case 3:
        glBegin(GL_LINES);
        glVertex3s(A, B, -1000);
        glVertex3s(A, B, 1000);
        glEnd();
        break;
    case 4:
        glBegin(GL_LINES);
        glVertex3s(x1 - aa * 500, y11 - bb * 500, z1 - cc * 500);
        glVertex3s(x2 + aa * 500, y2 + bb * 500, z2 + cc * 500);
        glEnd();
        break;
    }
}
void TransformPoints(void)
{
    int i, k;
    float tmp;
    for (k = 0; k < 8; k++)
        for (i = 0; i < 3; i++)
            ptsFin[k][i] = theMatrix[i][0] * ptsIni[k][0] + theMatrix[i][1] * ptsIni[k][1] + theMatrix[i][2] * ptsIni[k][2] + theMatrix[i][3];
    // Realign above line while execution
}
void Axes(void)
{
    glColor3f(0.0, 0.0, 0.0); // Set the color to BLACK
    glBegin(GL_LINES);        // Plotting X-Axis
    glVertex2s(-1000, 0);
    glVertex2s(1000, 0);
    glEnd();
    glBegin(GL_LINES); // Plotting Y-Axis
    glVertex2s(0, -1000);
    glVertex2s(0, 1000);
    glEnd();
}
void Draw(float a[8][3]) //Display the Figure
{
    int i;
    glColor3f(0.7, 0.4, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f(a[0][0], a[0][1], a[0][2]);
    glVertex3f(a[1][0], a[1][1], a[1][2]);
    glVertex3f(a[2][0], a[2][1], a[2][2]);
    glVertex3f(a[3][0], a[3][1], a[3][2]);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f(2, 2, 1);
    glVertex3f(6, 2, 1);
    glVertex3f(6, 4, 1);
    glVertex3f(2, 4, 1);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Axes();
    glColor3f(1.0, 0.0, 0.0); // Set the color to RED
    Draw(ptsIni);
    matrixSetIdentity(theMatrix);

    TransformPoints();
    Draw(ptsFin);
    glFlush();
}
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glEnable(GL_DEPTH_TEST);
}
int main(int argc, char *argv)
{
    glutInit(&argc, &argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(750, 750);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(" Basic Transformations ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

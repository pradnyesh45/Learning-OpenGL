#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>

void display();
void reshape(int, int);

void Football_Field(void)
{
    float x, y, ang, radius = 0.05;

    static float RAD_DEG = 57.296;

    glBegin(GL_QUADS);
    // GreenYard
    glColor3f(0.20, 0.60, 0.20);
    glVertex2f(0.10, 0.10);
    glVertex2f(0.90, 0.10);
    glVertex2f(0.90, 0.90);
    glVertex2f(0.10, 0.90);
    glColor3f(1.0, 1.0, 1.0);
    // Inner White Quad - Right
    glVertex2f(0.90, 0.35);
    glVertex2f(0.83, 0.35);
    glVertex2f(0.83, 0.65);
    glVertex2f(0.90, 0.65);
    // Inner White Quad - Left
    glVertex2f(0.10, 0.35);
    glVertex2f(0.17, 0.35);
    glVertex2f(0.17, 0.65);
    glVertex2f(0.10, 0.65);
    glEnd();

    // Change color to black
    glColor3f(0.0, 0.0, 0.0);

    // Mid Line
    glBegin(GL_LINES);
    glVertex2f(0.50, 0.10);
    glVertex2f(0.50, 0.90);

    // Left side of the Ground
    // Goal keeper front line
    glVertex2f(0.25, 0.25);
    glVertex2f(0.25, 0.75);
    // Goal keeper left line
    glVertex2f(0.10, 0.75);
    glVertex2f(0.25, 0.75);
    // Goal keeper right line
    glVertex2f(0.10, 0.25);
    glVertex2f(0.25, 0.25);

    // Right Side of the Ground
    // Goal keeper front line
    glVertex2f(0.75, 0.25);
    glVertex2f(0.75, 0.75);
    // Goal keeper left  Line
    glVertex2f(0.75, 0.25);
    glVertex2f(0.90, 0.25);
    // Goal keeper right line
    glVertex2f(0.75, 0.75);
    glVertex2f(0.90, 0.75);
    glEnd();

    // Circle at center of field
    glBegin(GL_LINE_LOOP);
    for (ang = 0.0; ang < 360.0; ang += 10.0)
    {
        x = radius * cos(ang / RAD_DEG) + 1.0;
        y = radius * sin(ang / RAD_DEG) + 0.5;
        glVertex2f(x / 2.0, y);
    }
    glEnd();

    // glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    // first person
    glColor3f(0.0, 0.44, 0.89);
    glVertex2f(0.33, 0.77);
    glVertex2f(0.33, 0.73);
    glVertex2f(0.37, 0.73);
    glVertex2f(0.37, 0.77);
    // second person
    glColor3f(0.0, 0.44, 0.89);
    glVertex2f(0.63, 0.37);
    glVertex2f(0.63, 0.33);
    glVertex2f(0.67, 0.33);
    glVertex2f(0.67, 0.37);
    // third person
    glColor3f(0.0, 0.44, 0.89);
    glVertex2f(0.33, 0.37);
    glVertex2f(0.33, 0.33);
    glVertex2f(0.37, 0.33);
    glVertex2f(0.37, 0.37);
    // fourth person
    glColor3f(0.0, 0.44, 0.89);
    glVertex2f(0.63, 0.77);
    glVertex2f(0.63, 0.73);
    glVertex2f(0.67, 0.73);
    glVertex2f(0.67, 0.77);
    glEnd();
}

float x_position = 0.5;
float y_position = 0.5;

void Moving_Ball(void)
{
    float theta;
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        theta = i * 3.142 / 180;
        glVertex2f(x_position + 0.01 * cos(theta), y_position + 0.01 * sin(theta));
    }
    glEnd();
    glFlush();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Window 1");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    Football_Field();
    Moving_Ball();

    glEnd();
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}


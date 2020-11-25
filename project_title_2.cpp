#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

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

// void timer(int)
// {
//     glutPostRedisplay();
//     glutTimerFunc(1000 / 60, timer, 0);

//     if (y_position > 0.37 && x_position == 0.37)
//     {

//         y_position -= 0.01;
//     }
//     else if (x_position < 0.73 && y_position == 0.37)
//     {
//         x_position += 0.01;
//     }
//     else if (y_position < 0.73 && x_position == 0.73)
//     {
//         y_position += 0.01;
//     }
//     else if (x_position > 0.37 && y_position == 0.37)
//     {
//         x_position -= 0.01;
//     }
// }

int main()
{
    if (!glfwInit())
    {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return 1;
    }

    GLFWwindow *window = glfwCreateWindow(1200, 800, "Soccer field", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // get version info
    const GLubyte *renderer = glGetString(GL_RENDERER); // get renderer string
    const GLubyte *version = glGetString(GL_VERSION);   // version as a string
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported %s\n", version);

    while (!glfwWindowShouldClose(window))
    {
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(0.1, 0.9, 0.1, 0.9, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        Football_Field();
        Moving_Ball();

        // glutTimerFunc(0, timer, 0);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // close GL context and any other GLFW resources
    glfwTerminate();
    return 0;
}

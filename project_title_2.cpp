#include <GL/gl.h>      // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <stdio.h>
#include <math.h>

void Soccer_Field();

int main()
{
    // start GL context and O/S window using the GLFW helper library
    if (!glfwInit())
    {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return 1;
    }

    // uncomment these lines if on Apple OS X
    /*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

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

    /* OTHER STUFF GOES HERE NEXT */
    while (!glfwWindowShouldClose(window))
    {
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(0.1, 0.9, 0.1, 0.9, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        Soccer_Field();

        // update other events like input handling
        glfwPollEvents();
        // put the stuff we've been drawing onto the display
        glfwSwapBuffers(window);
    }

    // close GL context and any other GLFW resources
    glfwTerminate();
    return 0;
}

void Soccer_Field(void)
{
    float x, y, ang, radius = 0.05; // Not sure what the radius of the center circle should be?

    static float RAD_DEG = 57.296;

    glBegin(GL_QUADS);
    glColor3f(0.20, 0.60, 0.20); // GreenYard
    glVertex2f(0.10, 0.10);
    glVertex2f(0.90, 0.10);
    glVertex2f(0.90, 0.90);
    glVertex2f(0.10, 0.90);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.90, 0.35);
    glVertex2f(0.83, 0.35); // Inner White Quad - Right
    glVertex2f(0.83, 0.65);
    glVertex2f(0.90, 0.65);
    glVertex2f(0.10, 0.35);
    glVertex2f(0.17, 0.35); // Inner White Quad - Left
    glVertex2f(0.17, 0.65);
    glVertex2f(0.10, 0.65);
    glEnd();

    glColor3f(0.0, 0.0, 0.0); // Change color to black

    glBegin(GL_LINES);
    glVertex2f(0.50, 0.10);
    glVertex2f(0.50, 0.90); // Mid Line

    // Left side of the Ground
    glVertex2f(0.25, 0.25);
    glVertex2f(0.25, 0.75); // Goal keeper front line
    glVertex2f(0.10, 0.75);
    glVertex2f(0.25, 0.75); // Goal keeper left line
    glVertex2f(0.10, 0.25);
    glVertex2f(0.25, 0.25); // Goal keeper right line

    // Right Side of the Ground
    glVertex2f(0.75, 0.25);
    glVertex2f(0.75, 0.75); // Goal keeper front line
    glVertex2f(0.75, 0.25);
    glVertex2f(0.90, 0.25); // Goal keeper left  Line
    glVertex2f(0.75, 0.75);
    glVertex2f(0.90, 0.75); // Goal keeper right line
    glEnd();

    glBegin(GL_LINE_LOOP); // Circle at center of field
    for (ang = 0.0; ang < 360.0; ang += 10.0)
    {
        x = radius * cos(ang / RAD_DEG) + 1.0;
        y = radius * sin(ang / RAD_DEG) + 0.5;
        glVertex2f(x / 2.0, y);
    }
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    // glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    // first person
    glVertex2f(0.63, 0.77);
    glVertex2f(0.63, 0.73);
    glVertex2f(0.67, 0.73);
    glVertex2f(0.67, 0.77);
    // second person
    glVertex2f(0.37, 0.77);
    glVertex2f(0.37, 0.77);
    glVertex2f(0.37, 0.77);
    glVertex2f(0.37, 0.77);
    // third person
    glVertex2f(0.67, 0.37);
    glVertex2f(0.67, 0.37);
    glVertex2f(0.67, 0.37);
    glVertex2f(0.67, 0.37);
    // fourth person
    glVertex2f(0.37, 0.37);
    glVertex2f(0.37, 0.37);
    glVertex2f(0.37, 0.37);
    glVertex2f(0.37, 0.37);
    glEnd();
}
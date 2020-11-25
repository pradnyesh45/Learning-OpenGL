#include <GLFW/glfw3.h>
#include <math.h>

const int steps = 300;
const float angle = 3.1415926 * 2.f / steps;

int main(void)
{
    GLFWwindow *window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Logo of ABV-IIITM Gwalior", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // big center grey rec
        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.4f);
        glVertex2f(-0.2f, -0.5f);
        glVertex2f(0.2f, -0.5f);
        glVertex2f(0.2f, 0.4f);
        glEnd();

        // three blue recs
        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.4f);
        glVertex2f(-0.1f, 0.0f);
        glVertex2f(0.1f, 0.0f);
        glVertex2f(0.1f, 0.4f);
        glEnd();

        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, 0.4f);
        glVertex2f(-0.3f, -0.0f);
        glVertex2f(-0.2f, 0.0f);
        glVertex2f(-0.2f, 0.4f);
        glEnd();

        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(0.2f, 0.4f);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.3f, 0.0f);
        glVertex2f(0.3f, 0.4f);
        glEnd();

        // small horizontal recs

        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.0f);
        glVertex2f(-0.1f, -0.05f);
        glVertex2f(0.15f, -0.05f);
        glVertex2f(0.15f, 0.0f);
        glEnd();

        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, 0.4f);
        glVertex2f(0.1f, 0.4f);
        glVertex2f(0.1f, 0.45f);
        glVertex2f(-0.15f, 0.45f);
        glEnd();

        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, 0.0f);
        glVertex2f(-0.3f, -0.05f);
        glVertex2f(-0.15f, -0.05f);
        glVertex2f(-0.15f, 0.0f);
        glEnd();

        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, 0.4f);
        glVertex2f(-0.2f, 0.4f);
        glVertex2f(-0.2f, 0.45f);
        glVertex2f(-0.3f, 0.45f);
        glEnd();

        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.2f, -0.05f);
        glVertex2f(0.35f, -0.05f);
        glVertex2f(0.35f, 0.0f);
        glEnd();

        glColor3f(0.0, 0.0, 0.39);
        glBegin(GL_QUADS);
        glVertex2f(0.15f, 0.4f);
        glVertex2f(0.3f, 0.4f);
        glVertex2f(0.3f, 0.45f);
        glVertex2f(0.15f, 0.45f);
        glEnd();

        // circles

        glBegin(GL_LINE_LOOP);
        glColor3f(0.6, 0.6, 0.6);
        for (int i = 0; i <= 300; i++)
        {
            double angle = 2 * 3.14 * i / 300;
            double x = 0.18 * cos(angle);
            double y = 0.18 * sin(angle) + 0.7;
            glVertex2d(x, y);
        }
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.6, 0.6, 0.6);
        for (int i = 0; i <= 300; i++)
        {
            double angle = 2 * 3.14 * i / 300;
            double x = 0.14 * cos(angle);
            double y = 0.14 * sin(angle) + 0.7;
            glVertex2d(x, y);
        }
        glEnd();

        // Bigger middle circle
        float xPos = 0.0, yPos = 0.7;
        float radius = 0.1;

        float prevX = xPos;
        float prevY = yPos - radius;

        for (int i = 0; i < steps; i++)
        {
            float newX = radius * sin(angle * i);
            float newY = -radius * cos(angle * i);

            glColor3f(0.0, 0.0, 0.39);
            glBegin(GL_TRIANGLES);

            glVertex2f(0.0, 0.7);
            glVertex2f(prevX, prevY);
            glVertex2f(newX, newY + 0.7);

            prevX = newX;
            prevY = newY + 0.7;
        }

        glEnd();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int gWindowSizeX = 640;
int gWindowSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height) {
    gWindowSizeX = width;
    gWindowSizeY = height;
    glViewport(0,0,gWindowSizeX,gWindowSizeY);
}
void glfwKeyCallBack(GLFWwindow* pWindow, int key, int scancode,int action,int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
    if (!glfwInit()) {
        std::cout << "glfwInit failed!\n";
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow * pWindow = glfwCreateWindow(gWindowSizeX, gWindowSizeY, "Practice", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "Error of creating window!\n";
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallBack);

    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL()) {
        std::cout<<"Cant load GLAD!"<<std::endl;
        return -1;
    }
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << "\n";
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";

    glClearColor(1, 0, 1, 1);

    while (!glfwWindowShouldClose(pWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
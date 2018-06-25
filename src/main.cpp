#include <iostream>
// GLEW

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>

//GLFW
#define GLFW_DLL
#include <GLFW/glfw3.h>


const GLint width = 800 , height = 600;



float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(void){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
  
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);   // safe on mac
  glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
  int a = 10;


  GLFWwindow *window = glfwCreateWindow(width,height,"LearnOpenGL",nullptr,nullptr);

  int screenWidth,screenHeight;

  glfwGetFramebufferSize(window,&screenWidth,&screenHeight);   // safe on mac

  if(nullptr == window){
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();

    return -1;
  }

  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;     // enabled opengl advanded feature 

  if(GLEW_OK != glewInit()){
    std::cout << "Failed to initialize GLEW" << std::endl;

    return -1;
  }

  // init vertices
  
  // init viewport
  glViewport(0,0,screenWidth,screenHeight);
  
  // print supported webgl version
  std::cout << (glGetString(GL_VERSION));

  while(!glfwWindowShouldClose(window)){
   
    processInput(window);

    glClearColor(0.2f,0.2f,0.2f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    
     glfwPollEvents();
  }

  glfwTerminate();

  return 0;

}



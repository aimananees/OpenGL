//
//  line.cpp
//  OpenGL_Tutorial
//
//  Created by Aiman Abdullah Anees on 10/01/17.
//  Copyright © 2017 Aiman Abdullah Anees. All rights reserved.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void){
    
    GLFWwindow *window;
    
    //Initialize the library
    if(!glfwInit()){
        return -1;
    }
    
    //create a windowed mode window and its OpenGL Context
    window=glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Hello World!", NULL,NULL);
    
    if(!window){
        glfwTerminate();
        return -1;
    }
    
    //make window's context current
    glfwMakeContextCurrent(window);
    
    
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //Important to use this...when glMatrixMode is used
    glOrtho(0,SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    GLfloat lineVerices[] = {
      200,100,0,
      100,300,0
    };
    
    

    
    //loop until the user closes the window
    while(!glfwWindowShouldClose(window)){
        
        glClear( GL_COLOR_BUFFER_BIT);
        
        //put all the OpenGL code here...
        glEnable(GL_LINE_SMOOTH);
        glLineWidth(10);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, lineVerices);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glEnable(GL_LINE_SMOOTH);
        
        
        
        //swap front and back buffers..
        glfwSwapBuffers(window);
        
        //pool for and process events
        glfwPollEvents();
        
    }
    
    glfwTerminate();
    return 0;
}

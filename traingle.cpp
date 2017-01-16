//A program to draw a VBO Triangle
//
//  main.cpp
//  Created by Aiman Abdullah Anees on 10/01/17.
//  Copyright © 2017 Aiman Abdullah Anees. All rights reserved.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void){
    
    GLFWwindow *window;
    
    //Initialize the library
    if(!glfwInit()){
        return -1;
    }
    
    //create a windowed mode window and its OpenGL Context
    window=glfwCreateWindow(640, 480,"Hello World!", NULL,NULL);
    
    if(!window){
        glfwTerminate();
        return -1;
    }
    
    //make window's context current
    glfwMakeContextCurrent(window);
    
    float vertices[] = {
        0.0,0.5,0.0,
        -0.5,-0.5,0.0,
        0.5,-0.5,0.0
    };
    
    //loop until the user closes the window
    while(!glfwWindowShouldClose(window)){
        
        glClear( GL_COLOR_BUFFER_BIT);
        
        //put all the OpenGL code here...
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_VERTEX_ARRAY);
        
        
        
        //swap front and back buffers..
        glfwSwapBuffers(window);
        
        //pool for and process events
        glfwPollEvents();
        
    }
    
    glfwTerminate();
    return 0;
}

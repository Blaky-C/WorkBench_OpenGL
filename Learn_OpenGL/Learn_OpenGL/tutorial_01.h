#ifndef TUTORIAL_01_H
#define TUTORIAL_01_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
using namespace std;

// public util function
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// tutorial contents
void initial_glfw() {
	// this can be used to test the environment
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

bool create_window() {
	// create a window
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	// initial GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD" << endl;
		return false;
	}

	// set viewport
	glViewport(0, 0, 800, 600);
	// set framebuffer callback
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// define a render loop
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// delete all resouces
	glfwTerminate();
	return true;
}

#endif // !TUTORIAL_01_H

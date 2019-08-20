#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
	// program ID
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	// active the program
	void use();
	// tool functions with uniform
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

	~Shader();
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

#endif


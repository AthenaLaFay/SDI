#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include "Classes.h"

class classFile
{
public:
	std::vector<Classes> classes;
	std::string name;
	void newClass(std::string className);
	bool save();
	bool rename();
	bool open();
private:

};
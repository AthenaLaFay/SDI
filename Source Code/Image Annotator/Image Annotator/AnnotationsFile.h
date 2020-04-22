#pragma once
#include "Shape.h"
#include "MyForm.h"
#include <string>
#include <filesystem>
#include <vector>
#include <fstream>

using namespace System::Drawing;

class AnnotationsFile
{
public:
	std::string annotationsFilename;
	std::string annotationsFileFolder;
	std::string annotationsFilePath;
	int numOfImages = 0;
	std::vector<std::string> imageFilenames;
	std::vector<int> numOfShapes;
	std::vector<std::string> shapeTypes;
	std::vector<std::vector<int>> shapePoints;
	//std::vector<ShapeSpace::Shape> shapes;

	void newShape();
	void save();
	bool rename();
	void open();
	bool autoSave();
};


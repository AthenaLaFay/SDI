#include "pch.h"
#include <iostream>
#include <fstream>
#include <filesystem> 
#include <vector>
#include <string>


namespace fs = std::experimental::filesystem;
struct ImageFolderT : testing::Test 
{
	imageFolder* folder;
	std::string filePath = "C:\\Users\\hogan\\OneDrive\\Documents\\SDI-master\\Source Code\\images";
	std::vector<std::string> fileNames;
	
	ImageFolderT() 
	{
		folder = new imageFolder;
	}	

	~ImageFolderT() 
	{
		delete folder;
	}
};
struct FilePaneTests : testing::Test
{
	imageFolder* folder;
	std::string filePath = "C:\\Users\\hogan\\OneDrive\\Documents\\SDI-master\\Source Code\\images";
	std::vector<std::string> images;
	std::vector<std::time_t> imagesTimes;
	//https://en.cppreference.com/w/cpp/filesystem/last_write_time
	FilePaneTests()
	{
		folder = new imageFolder;
		//images = folder->loadImages(filePath);
		images.push_back("wp4676578.png");
		images.push_back("trees.jpg");
		images.push_back("forest.jpg");
		imagesTimes.push_back(0);
		imagesTimes.push_back(10);
		imagesTimes.push_back(20);
	}

	~FilePaneTests()
	{

	}
};
TEST_F(ImageFolderT, LoadFile) { //First test
	

}
struct FormTests: testing::Test
{
	
};
TEST_F(FormTests, Point1Test)
{
	MyForm form;
}
TEST_F(ImageFolderT, FullPathTest)
{
	std::string test = folder->fullPath("C:\\Users\\hogan\\OneDrive\\Documents\\SDI-master\\Source Code\\images", "filename");
	EXPECT_EQ("C:\\Users\\hogan\\OneDrive\\Documents\\SDI-master\\Source Code\\images\\filename", test);
}
TEST(ImageFolderTests, LoadFile)
{
	imageFolder folder;
	std::string filePath = "C:\\Users\\hogan\\OneDrive\\Documents\\SDI-master\\Source Code\\images";
	std::vector<std::string> testFileNames;
	testFileNames.push_back("forest.jpg");
	testFileNames.push_back("trees.jpg");
	testFileNames.push_back("wp4676578.png");
	std::vector<std::string> actualFileNames = folder.loadImages(filePath);

	for (size_t i = 0; i < actualFileNames.size(); i++) {
		actualFileNames[i].resize(actualFileNames[i].size() - 1);
	}

	EXPECT_EQ(testFileNames, actualFileNames);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
TEST_F(FilePaneTests, ListImages)
{
	std::vector<std::string> testFileNames;
	testFileNames.push_back("wp4676578.png");
	testFileNames.push_back("trees.jpg");
	testFileNames.push_back("forest.jpg");
	 
	EXPECT_EQ(testFileNames, images);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
TEST_F(FilePaneTests, sortNameAscending)
{

	int sorting_option = 1;
	//images = images.sort_by(1);
	bool test = true;
	for (int i = 0; i < images.size() - 2; i++)
	{
		std::string a = images[i];
		std::string b = images[i + 1];
		if (a > b)
		{
			test = false;
			break;
		}
	}
	EXPECT_EQ(true, test);
}
TEST_F(FilePaneTests, sortNameDescending)
{
	int sorting_option = 2;
	//images = images.sort_by(2);
	bool test = true;
	for (int i = 0; i < images.size() - 2; i++)
	{
		std::string a = images[i];
		std::string b = images[i + 1];
		if (a < b)
		{
			test = false;
			break;
		}
	}
	EXPECT_EQ(true, test);
}
TEST_F(FilePaneTests, sortDateAscending)
{
	int sorting_option = 3;
	//images = images.sort_by(3);
	bool test = true;
	for (int i = 0; i < imagesTimes.size() - 2; i++)
	{
		std::time_t a = imagesTimes[i];
		std::time_t b = imagesTimes[i + 1];
		if (a > b)
		{
			test = false;
			break;
		}
	}
	EXPECT_EQ(true, test);
}
TEST_F(FilePaneTests, sortDateDescending)
{
	int sorting_option = 4;
	//images = images.sort_by(4);
	bool test = true;
	for (int i = 0; i < imagesTimes.size() - 2; i++)
	{
		std::time_t a = imagesTimes[i];
		std::time_t b = imagesTimes[i + 1];
		if (a < b)
		{
			test = false;
			break;
		}
	}
	EXPECT_EQ(true, test);
}
TEST(ImagePaneTests, displayImage)
{

}
TEST(ImagePaneTest, selectImage)
{

}
TEST(ImagePaneTests, displayAnnotations)
{

}
struct ClassFileTests : testing::Test
{

	classFile* file;
	std::string filePath = "C:\\Users\\hogan\\OneDrive\\Documents\\SDI-master\\Source Code\\images";
	std::vector<Classes> classes;
	Classes class1;
	Classes class2;
	ClassFileTests()
	{
		file = new classFile;
		file->newClass("animal");
		file->newClass("pond");
		file->newClass("tree");
		classes.push_back(class1);
		classes.push_back(class2);
		file->classes.push_back(class1);
		file->classes.push_back(class2);
	}
	~ClassFileTests()
	{

	}
};
TEST_F(ClassFileTests, saveClassFile)
{
	
	bool test = file->save(); //bool
	EXPECT_EQ(false, test);
	fs::exists(filePath + "//filetest.name");
	EXPECT_FALSE(false);
}
TEST_F(ClassFileTests, openClassFile)
{
	bool save = file->save();
	bool test = file->open();
	EXPECT_TRUE(true);
}
TEST_F(ClassFileTests, renameClassFile)
{
	bool save = file->save();
	bool test = file->rename();
	EXPECT_EQ(false, test);
}
TEST_F(ClassFileTests, addClass)
{

}
TEST_F(ClassFileTests, removeClass)
{

}
TEST(ClassPaneTests, sortClassAscending)
{

}
TEST(ClassPaneTests, sortClassDescending) 
{

}
TEST(ClassPaneTests, selectClass)
{

}
TEST(ClassPaneTests, BrowseClass)
{

}
struct AnnotationFileTests : testing::Test
{

	AnnotationsFile* file;
	imageFolder* folder;
	

	AnnotationFileTests()
	{
		file = new AnnotationsFile;
		file->newShape();
		file->newShape();
		file->newShape();
		file->annotationsFileFolder = "C:\\Users\\hogan\\OneDrive\\Documents\\SDI-master 3\\Source Code\\images";
		
	}
	~AnnotationFileTests()
	{

	}
};
TEST_F(AnnotationFileTests, saveAnnotationFile)
{

	file->annotationsFilename = "annfiletest.name";
	file->annotationsFilePath = file->annotationsFileFolder + "\\" + file->annotationsFilename;
	file->numOfImages = 1;
	file->imageFilenames.push_back("test.png");
	file->numOfShapes.push_back(1);
	file->shapeTypes.push_back("Quadrilaterous");
	file->shapePoints.push_back({10, 15 });
	file->shapePoints.push_back({10, 20});
	file->shapePoints.push_back({15, 15});
	file->shapePoints.push_back({15, 20});



 	file->save();

	int numOfImagesTest;
	std::vector<std::string> imageFilenamesTest;
	std::vector<int>numOfShapesTest;
	std::vector<std::string> shapeTypesTest;
	std::vector<std::vector<int>> shapePointsTest;
	bool save = true;

	std::ofstream logfile(file->annotationsFileFolder+"\\testlog.name");


	std::ifstream testFile(file->annotationsFilePath);
	std::string x;

	if (testFile)
	{
		//file does exist
		getline(testFile, x);
		numOfImagesTest = std::stoi(x);
		
			for (int i = 0; i < numOfImagesTest; i++)
			{
				int t = 0;//shape types counter
				int p = 0;//shape points counter
				getline(testFile, x);
				imageFilenamesTest.push_back(x);
				logfile << x;
				getline(testFile, x);
				numOfShapesTest.push_back(std::stoi(x));
				logfile << x;
				
				for (int j = 0; j < numOfShapesTest[i]; j++)
				{
					getline(testFile, x);
					shapeTypesTest.push_back(x);
					logfile.close();
					if (shapeTypesTest.back() == "Quadrilaterous")
					{
						for (int k = 0; k < 4; k++)
						{
							getline(testFile, x);
							int X = std::stoi(x);
							getline(testFile, x);
							int Y = std::stoi(x);
							shapePointsTest.push_back({ X, Y });
							p++;
						}
					}
					else if (shapeTypesTest.back() == "Triangle")
					{
						for (int k = 0; k < 3; k++)
						{
							getline(testFile, x);
							int X = std::stoi(x);
							getline(testFile, x);
							int Y = std::stoi(x);
							shapePointsTest.push_back({ X, Y });
							p++;
						}
					}
					else if (shapeTypesTest.back() == "Pentagon")
					{
						for (int k = 0; k < 5; k++)
						{
							getline(testFile, x);
							int X = std::stoi(x);
							getline(testFile, x);
							int Y = std::stoi(x);
							shapePointsTest.push_back({ X, Y });
							p++;
						}
					}
					else if (shapeTypesTest.back() == "Octagon")
					{
						for (int k = 0; k < 8; k++)
						{
							getline(testFile, x);
							int X = std::stoi(x);
							getline(testFile, x);
							int Y = std::stoi(x);
							shapePointsTest.push_back({ X, Y });
							p++;
						}
					}
					else
					{
						save = false;
					}
					t++;

				}

			}
		
	}
	else
	{
		//file doesn't exist
		bool save = true;
	}
	
	testFile.close();
	EXPECT_EQ(save, true);
	EXPECT_EQ(file->numOfImages, numOfImagesTest);
	EXPECT_EQ(file->imageFilenames, imageFilenamesTest);
	EXPECT_EQ(file->numOfShapes, numOfShapesTest);
	EXPECT_EQ(file->shapeTypes, shapeTypesTest);
	EXPECT_EQ(file->shapePoints, shapePointsTest);
}
TEST_F(AnnotationFileTests, openAnnotationFile)
{
	file->annotationsFilename = "annfiletest.name";
	file->annotationsFilePath = file->annotationsFileFolder + "\\" + file->annotationsFilename;
	int numOfImagesTest;
	std::vector<std::string> imageFilenamesTest;
	std::vector<int>numOfShapesTest;
	std::vector<std::string> shapeTypesTest;
	std::vector<std::vector<int>> shapePointsTest;
	bool save = true;

	file->open();
	
	numOfImagesTest = 1;
	imageFilenamesTest.push_back("test.png");
	numOfShapesTest.push_back(1);
	shapeTypesTest.push_back("Quadrilaterous");
	shapePointsTest.push_back({ 10, 15 });
	shapePointsTest.push_back({ 10, 20 });
	shapePointsTest.push_back({ 15, 15 });
	shapePointsTest.push_back({ 15, 20 });
	EXPECT_EQ(save, true);
	EXPECT_EQ(file->numOfImages, numOfImagesTest);
	EXPECT_EQ(file->imageFilenames, imageFilenamesTest);
	EXPECT_EQ(file->numOfShapes, numOfShapesTest);
	EXPECT_EQ(file->shapeTypes, shapeTypesTest);
	EXPECT_EQ(file->shapePoints, shapePointsTest);
}
TEST_F(AnnotationFileTests, renameAnnotationsFile)
{
	file->save();
	bool test = file->rename();
	EXPECT_EQ(false, test);
}
TEST_F(AnnotationFileTests, autosaveFile)
{
	file->save();
	bool test = file->autoSave();
	EXPECT_EQ(false, test);
}
TEST(PentagonTests, createPentagon)
{

}
TEST(PentagonTests, movePentagon)
{

}
TEST(PentagonTests, resizePentagon)
{

}
TEST(PentagonTests, copyPentagon)
{

}
TEST(PentagonTests, pastePentagon)
{

}
TEST(PentagonTests, deletePentagon)
{

}
TEST(PentagonTests, selectPentagon)
{

}
TEST(PentagonTests, countPentagon)
{

}
TEST(OctagonTests, createOctagon)
{

}
TEST(OctagonTests, moveOctagon)
{

}
TEST(OctagonTests, visualiseOctagon)
{

}
TEST(OctagonTests, resizeOctagon)
{

}
TEST(OctagonTests, copyOctagon)
{

}
TEST(OctagonTests, pasteOctagon)
{

}
TEST(OctagonTests, deleteOctagon)
{

}
TEST(OctagonTests, selectOctagon)
{

}
TEST(OctagonTests, countOctagon)
{

}
TEST(QuadrilaterousTests, createQuadrilaterous)
{

}
TEST(QuadrilaterousTests, moveQuadrilaterous)
{

}
TEST(QuadrilaterousTests, visualiseQuadrilaterous)
{

}
TEST(QuadrilaterousTests, resizeQuadrilaterous)
{

}
TEST(QuadrilaterousTests, copyQuadrilaterous)
{

}
TEST(QuadrilaterousTests, pasteQuadrilaterous)
{

}
TEST(QuadrilaterousTests, deleteQuadrilaterous)
{

}
TEST(QuadrilaterousTests, selectQuadrilaterous)
{

}
TEST(QuadrilaterousTests, countQuadrilaterous)
{

}
TEST(TriangleTests, createTriangle)
{

}
TEST(TriangleTests, moveTriangle)
{

}
TEST(TriangleTests, visualiseTriangle)
{

}
TEST(TriangleTests, resizeTriangle)
{

}
TEST(TriangleTests, copyTriangle)
{

}
TEST(TriangleTests, pasteTriangle)
{

}
TEST(TriangleTests, deleteTriangle)
{

}
TEST(TriangleTests, selectTriangle)
{

}
TEST(TriangleTests, countTriangle)
{

}

#include "AnnotationsFile.h"
#include "iostream"


void AnnotationsFile::newShape()
{

}
void AnnotationsFile::save()
{
	std::ofstream file(annotationsFilePath);
	file << numOfImages << std::endl;
	if (file)
	{
		for (int i = 0; i < numOfImages; i++)
		{
			int t = 0;//shape types counter
			int p = 0;//shape points counter
			file << imageFilenames[i]<<std::endl;
			file << numOfShapes[i] << std::endl;

			for (int j = 0; j < numOfShapes[i]; j++)
			{
				file << shapeTypes[t] << std::endl;

				if (shapeTypes[t] == "Quadrilaterous")
				{

					for (int k = 0; k < 4; k++)
					{

						file << std::to_string(shapePoints[p][0]) << std::endl;

						file << std::to_string(shapePoints[p][1]) << std::endl;
						p++;
					}
				}
				else if (shapeTypes[t] == "Triangle")
				{
					for (int k = 0; k < 3; k++)
					{
						file << std::to_string(shapePoints[p][0]) << std::endl;
						file << std::to_string(shapePoints[p][1]) << std::endl;
						p++;
					}
				}
				else if (shapeTypes[t] == "Pentagon")
				{
					for (int k = 0; k < 5; k++)
					{
						file << std::to_string(shapePoints[p][0]) << std::endl;
						file << std::to_string(shapePoints[p][1]) << std::endl;
						p++;
					}
				}
				else if (shapeTypes[t] == "Octagon")
				{
					for (int k = 0; k < 8; k++)
					{
						file << std::to_string(shapePoints[p][0]) << std::endl;
						file << std::to_string(shapePoints[p][1]) << std::endl;
						p++;
					}
				}
				else
				{
					std::cout << "Error message" << std::endl;
					
				}
				t++;
			}
		}
	}
	else
	{
		std::cout << "No file created";
	}
} 
	void AnnotationsFile::open()
	{
		std::ifstream testFile(annotationsFilePath);
		std::string x;

		if (testFile)
		{
			//file does exist
			getline(testFile, x);
			numOfImages = std::stoi(x);

			for (int i = 0; i < numOfImages; i++)
			{
				int t = 0;//shape types counter
				int p = 0;//shape points counter
				getline(testFile, x);
				imageFilenames.push_back(x);

				getline(testFile, x);
				numOfShapes.push_back(std::stoi(x));
				for (int j = 0; j < numOfShapes[i]; j++)
				{
					getline(testFile, x);
					shapeTypes.push_back(x);
					if (shapeTypes.back() == "Quadrilaterous")
					{
						for (int k = 0; k < 4; k++)
						{
							getline(testFile, x);
							int X = std::stoi(x);
							getline(testFile, x);
							int Y = std::stoi(x);
							shapePoints.push_back({ X, Y });
							p++;
						}
					}
					else if (shapeTypes.back() == "Triangle")
					{
						for (int k = 0; k < 3; k++)
						{
							getline(testFile, x);
							int X = std::stoi(x);
							getline(testFile, x);
							int Y = std::stoi(x);
							shapePoints.push_back({ X, Y });
							p++;
						}
					}
					else if (shapeTypes.back() == "Pentagon")
					{
						for (int k = 0; k < 5; k++)
						{
							getline(testFile, x);
							int X = std::stoi(x);
							getline(testFile, x);
							int Y = std::stoi(x);
							shapePoints.push_back({ X, Y });
							p++;
						}
					}
					else if (shapeTypes.back() == "Octagon")
					{
						for (int k = 0; k < 8; k++)
						{
							getline(testFile, x);
							int X = std::stoi(x);
							getline(testFile, x);
							int Y = std::stoi(x);
							shapePoints.push_back({ X, Y });
							p++;
						}
					}
					else
					{
						std::cout << "Incorrect shape name";
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
	}
	bool AnnotationsFile::rename()
	{
		return false;
	}

	bool AnnotationsFile::autoSave()
	{
		return false;
	}

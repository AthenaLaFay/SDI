#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace ShapeSpace {
	/// Creates a new shape used for drawing onto the main form
	class Shape{
	public:
		std::string type;
		std::vector<std::vector<int>> points;
		void setStart(); ///< Sets the initial point of the shape 
						 ///<
	};
}


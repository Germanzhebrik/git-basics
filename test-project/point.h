#pragma once
#include <iostream>


struct Point{
  double x;
  double y;
};

void VersionInMainBranch() {
	std::cout << "For merge with develop branch!" << std::endl;
}
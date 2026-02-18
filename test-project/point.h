#pragma once
#include <iostream>


struct Point{
  double x;
  double y;
};

// ????????? ? ????? dev 
void DevBranch() {
	std::cout << "Working on branch develop!" << std::endl;
}

int SumModule2(int a, int b) {
	return (a + b) % 2;
}

int NewFucn(const int& b) {
	return b;
}

void VersionInMainBranch() {
	std::cout << "For merge with develop branch!" << std::endl;
}
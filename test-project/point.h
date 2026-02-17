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
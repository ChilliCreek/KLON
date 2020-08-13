#pragma once
#include<vector>
struct areamap {
	std::vector < std::pair <int, int> > captured;
	void add(int i,int j);
};
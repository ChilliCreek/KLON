#include"pch.h"
#include"areamap.h"

void areamap::add(int i,int j)
{
	captured.push_back(std::make_pair(i,j));
}

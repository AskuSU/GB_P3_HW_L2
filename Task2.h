#pragma once
#include <vector>
#include <algorithm>

template<typename T>
void SortPointers(std::vector<T*>& vec)
{
	std::sort(vec.begin(), vec.end(),
		[](T* left, T* right)
		{
			return *left < *right;
		});
}
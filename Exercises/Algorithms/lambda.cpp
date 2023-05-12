#include <iostream>
#include <vector>
#include <algorithm>

void PrintIntVector(const std::vector<int>& vec_)
{
	for (auto& el : vec_)
	{
		std::cout << el << std::endl;
	}
}

int main(void)
{
	std::vector<int> nums = { 1, 2, 3, 4, 5 };

	std::sort(begin(nums), end(nums), [](int a, int b) { return a > b; });

	PrintIntVector(nums);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintIntVector(const std::vector<int>& vec_)
{
	for (auto& el : vec_)
	{
		std::cout << el << std::endl;
	}
}

int main(void)
{
	cout << "Algorithm With Lambda Expression:" << endl;

	std::vector<int> nums = { 1, 2, 3, 4, 5 };

	std::sort(begin(nums), end(nums), [](int a, int b) { return a > b; });

	PrintIntVector(nums);

	cout << "Mutable Lambda:" << endl;

	int x{ 42 }, y{ 99 }, z{ 0 };

	auto lam = [=, &z]() mutable { ++x; ++y; z = x + y; };
	lam();
	lam();

	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;

	cout << "Generalized Capture With Initialization:" << endl;

	int y1 = 1;
	auto lam2 = [y = y1 + 1](int x) { return x + y; };
	auto res = lam2(5);
	cout << "y1: " << y1 << endl;
	cout << "res: " << res << endl;

	return 0;
}
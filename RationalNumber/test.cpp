#include "RationalNumber.hpp"
#include <iostream>

using namespace std;

int main()
{
	RationalNumber r1;
	RationalNumber r2;
	std::cout << "r1: " << r1;
	std::cout << "r2: " << r2;
	std::cout << "r1 < r2: " << ((r1 < r2) ? "true" : "false") << endl;
	std::cout << "r1 <= r2: " << ((r1 <= r2) ? "true" : "false") << endl;
	std::cout << "r1 == r2: " << ((r1 == r2) ? "true" : "false") << endl;
	std::cout << "r1 != r2: " << ((r1 != r2) ? "true" : "false") << endl;
	std::cout << "r1 > r2: " << ((r1 > r2) ? "true" : "false") << endl;
	std::cout << "r1 >= r2: " << ((r1 >= r2) ? "true" : "false") << endl;
	std::cout << "r1 + r2: " << r1 + r2;
	std::cout << "r1 - r2: " << r1 - r2;;
	std::cout << "r1 * r2: " << r1 * r2;
	std::cout << "r1 / r2: " << r1 / r2;
}
#include <iostream>
using namespace std;

int main()
{
	int x = 1, y = 2;
	auto Swap = []<typename T>(T& a,T& b){
		T temp = a; 
		a = b;
		b = temp;
	};

	Swap(x, y);
	std::cout << x << std::endl; // 2
	std::cout << y << std::endl; // 1
}

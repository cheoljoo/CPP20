#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto r = v | views::drop(3) | views::filter([](int i) { return 0 == i % 2; });
	for(auto n : r){
		cout << n*2 << " " ;
	}
	cout << endl;
}

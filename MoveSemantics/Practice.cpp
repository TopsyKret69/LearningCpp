#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>



struct A
{
	std::string _aValue;
	A() :_aValue(std::string{ "empty string" }) { std::cout << "const contstructor - " + _aValue << std::endl; }

	A(std::string name) :_aValue(std::move(name)) { std::cout << "move semantics - " + _aValue << std::endl; }

};



int main()
{

	std::string lValue = "A string to be passed";
	
	auto value = std::move(lValue);

	A obj1 = A();
	A obj2 = A(value);

	int x;
	std::cin >> x;

	return 0;
}
#include "Lesson1.h"

Lesson1::~Lesson1()
{
	std::cout << "Class Lesson1 has been destructed" << std::endl;
}


int main()
{
	Lesson1 obj = Lesson1(5);
	std::cout << obj << std::endl;;
	std::cout << obj.getMyValue() << std::endl;
	int c;
	std::cin >> c;
	return 0;
}


std::ostream & operator<<(std::ostream & out, Lesson1 & obj)
{
	out << obj.print() << std::endl;
	return out;
}

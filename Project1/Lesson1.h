#pragma once
#include <iostream>
#include <string>

class Lesson1
{
private:
	int myInt;

public:
	Lesson1(int x) : myInt(x) { };
	virtual ~Lesson1();
	std::string print() { return "My value is " + std::to_string(getMyValue()); };
	int getMyValue() const { return myInt; }
	friend std::ostream & operator<<(std::ostream & out, Lesson1 & obj);
};



#include <iostream>
#include <vector>


using namespace std;


void runLambda(double(*pFunc)())
{
	cout << pFunc() << endl;
}

int main()
{
	int x{ 10 };
	int y{ 3 };
	double z{ 2.71 };


	auto lambda = [&]()->double { return x * y * z; };

	cout << lambda() << endl;

	int a;
	cin >> a;

	return 0;
}
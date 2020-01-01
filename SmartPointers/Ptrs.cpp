#include <iostream>
#include <vector>
#include <memory>

int* bad_allocation_behav()
{
	int *i = new int[3];
	i[0] = 22;
	i[1] = 33;
	delete i;

	return i;
}


struct foo
{
	foo() { std::cout << "constructed" << std::endl; }
	~foo() { std::cout << "deleted" << std::endl; }
};

void not_smart()
{
	foo* obj = new foo();
}

void smart()
{
	std::unique_ptr<foo> uniquePtr_foo{ new foo() };
}

template <typename T>
class my_Unique_Ptr {
private:
	T _ptr{ nullptr };
public:
	my_Unique_Ptr() = default;
	my_Unique_Ptr(T* ptr) :_ptr(ptr) {}
	~my_Unique_Ptr()
	{
		std::cout << "~my_Unique_Ptr" << std::endl;
		delete _ptr;
	}
	//no copy constructor or assignment operator
	///No copy constructor due to unique ownership
	my_Unique_Ptr(const my_Unique_Ptr& rhs) = delete;
	///No assinment operator due to unique ownership
	my_Unique_Ptr& operator=(const T rhs) = delete;
	
	my_Unique_Ptr(my_Unique_Ptr&& rhs) :_ptr(rhs._ptr) { 
		std::cout << "move constructor" << std::endl;
		rhs._ptr = nullptr;
	}

	my_Unique_Ptr& operator=(T&& rhs) {
		std::cout << "move assignmeng" << std::endl;
		_ptr = rhs._ptr;
		rhs._ptr = nullptr;
		return *this;
	}
};


int main()
{


	auto x = bad_allocation_behav();

	std::cout << typeid(x).name() << std::endl;
	//delete x;
	//the following is access violation problem
	//std::cout << x[0] << std::endl;

	not_smart();

	smart();

	//unique_ptr is not copyable, but moveable with move semantics, std::move()

	std::unique_ptr<int> i = std::make_unique<int>(10039485);

	std::cout << typeid(i).name() << std::endl;
	std::string stingVariable = "somethingString";
	my_Unique_Ptr<std::string> strg( my_Unique_Ptr<std::string>(stingVariable) );
	//the following cannot be done
	//my_Unique_Ptr<std::string> strg2 = strg;
	
	//the next is valid
	//my_Unique_Ptr<std::string> strg2(strg);

	auto strg3 = std::move(strg);


	int y;
	std::cin >> y;

	return 1;
}
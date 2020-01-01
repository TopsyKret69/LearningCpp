#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>


using namespace std;

void run(function<bool(string&)> check)
{
	string test = "doggy";
	cout << check(test) << endl;
}

class Base{
public:
	virtual void doSomething() = 0;
	Base()
	{
		cout << "Base class has been constructed" << endl;
	}
	virtual ~Base()
	{
		cout << "Base class has been destructed" << endl;
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived class has been constructed" << endl;
	}
	~ Derived()
	{
		cout << "Derived class has been destructed" << endl;
	}
	virtual void doSomething() override { cout << "This is the doSomething method"<<endl; }
};

class TextReader
{
private:
	string m_fileName;
	char m_delimeter;
public:
	TextReader(string fileName, char delimeter = ',') :
		m_fileName(fileName),
		m_delimeter(delimeter)
	{}

	string const getFileName() { return m_fileName; }
	char const getDelimeter() { return m_delimeter; }

	//the fetching method
	const vector<vector<string>> getDataFromTextFile();
};

void split(const std::string& str, vector<string>& cont, const std::string& delims = ",")
{
	std::size_t current, previous = 0;
	current = str.find_first_of(delims);
	while (current != std::string::npos) {
		cont.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find_first_of(delims, previous);
	}
	cont.push_back(str.substr(previous, current - previous));
}

const vector<vector<string>> TextReader::getDataFromTextFile()
{
	ifstream file(getFileName());
	vector<vector<string> > dataList;

	string line = "";
	while (getline(file,line))
	{
		string element = "";
		vector<string> tempVec;
		split(line, tempVec);
		dataList.push_back(tempVec);
	}

	file.close();
	return dataList;
}


class DataTable
{
public:
	DataTable() {
		cout << "Data Table has been created" << endl;
	}
};

int main()
{
	Base *x = new Derived();
	x->doSomething();

	Derived d;
	Base &b = d;

	b.doSomething();
	string fileName = "C:/Users/blond/Documents/SourceData/input.txt";
	char delimiter = ',';

	TextReader *reader = new TextReader(fileName, delimiter);
	vector<vector<string>> input = reader->getDataFromTextFile();

	for (auto line : input)
	{
		for (auto element : line)
		{
			cout << element << " , ";
		}
		cout << endl;
	}


	/*unique_ptr<Base> x_uPtr = make_unique<Derived>(Derived());

	x_uPtr->doSomething();


	int size = 5;
	auto lambda = [size](string test) {return test.size() == size; };

	run(lambda);*/

	int in;
	cin >> in;

	return 0;
}
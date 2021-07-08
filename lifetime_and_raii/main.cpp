#include <iostream>
#include <string>

#include "MyUniquePointer.hpp"

class A
{
public:
	A(std::string name)
	{
		this->name = name;
		std::cout << "constructor of " << name << std::endl;
	}

	~A()
	{
		std::cout << "destructor of " << name << std::endl;
	}

	void test()
	{
		std::cout << "test of " << name << std::endl;
	}

private:
	std::string name;
};

int main()
{
	MyUniquePointer<A> ptr(new A("first"));
	auto a_ptr = ptr.get();
	ptr.reset(new A("second"));
	auto b_ptr = ptr.get();
	delete ptr.release();
	auto c_ptr = ptr.get();
	ptr.reset(new A("third"));
	(*ptr).test();
	ptr->test();

	return 0;
}
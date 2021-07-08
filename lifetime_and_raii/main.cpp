#include <iostream>
#include <string>

#include "MyUniquePointer.hpp"
#include "MySharedPointer.hpp"

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

	MySharedPointer<A> sh_ptr(new A("sh_first"));
	auto a_sh_ptr = sh_ptr.get();
	auto sh_ptr2(sh_ptr);
	auto b_sh_ptr = sh_ptr2.get();
	sh_ptr.reset(new A("sh_second"));
	auto c_sh_ptr = sh_ptr.get();
	sh_ptr2.reset(new A("sh_third"));
	(*sh_ptr).test();
	sh_ptr->test();

	return 0;
}
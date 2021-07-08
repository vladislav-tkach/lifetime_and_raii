#pragma once

#pragma once

template<typename T>
class MyUniquePointer
{
public:
	MyUniquePointer();
	MyUniquePointer(T* value);
	MyUniquePointer(const MyUniquePointer& ptr) = delete;
	//MyUniquePointer(MyUniquePointer&& ptr);
	~MyUniquePointer();

	T* get() const;
	void reset(T* value);
	void release();
	T& operator*() const;
private:
	T* value;
};

template<typename T>
MyUniquePointer<T>::MyUniquePointer()
{
	value = nullptr;
}


template <typename T>
MyUniquePointer<T>::MyUniquePointer(T* value)
{
	this->value = value;
}


template<typename T>
MyUniquePointer<T>::~MyUniquePointer()
{
	delete this->value;
}


template<typename T>
T* MyUniquePointer<T>::get() const
{
	return value;
}


template<typename T>
void MyUniquePointer<T>::reset(T* value)
{
	delete this->value;
	this->value = value;
}

template<typename T>
void MyUniquePointer<T>::release()
{
	delete value;
	value = nullptr;
}


template<typename T>
T& MyUniquePointer<T>::operator*() const
{
	return *value;
}
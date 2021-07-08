#pragma once

template<typename T>
class MySharedPointer
{
public:
	MySharedPointer();
	explicit MySharedPointer(T* value);
	MySharedPointer(const MySharedPointer<T>& ptr);
	//MySharedPointer(MySharedPointer<T>&& ptr);
	~MySharedPointer();

	T* get() const;
	void reset(T* value);
	T& operator*() const;
	T* operator->() const;
private:
	T* _value;
	unsigned int* _counter;
};

template<typename T>
MySharedPointer<T>::MySharedPointer()
{
	_value = nullptr;
	_counter = new unsigned int(0);
}


template<typename T>
MySharedPointer<T>::MySharedPointer(T* value)
{
	_value = value;
	_counter = new unsigned int(0);
	++(*_counter);
}


template<typename T>
MySharedPointer<T>::MySharedPointer(const MySharedPointer<T>& ptr)
{
	_value = ptr._value;
	_counter = ptr._counter;
	++(*_counter);
}


template<typename T>
MySharedPointer<T>::~MySharedPointer()
{
	if (*_counter <= 1) {
		delete _value;
		delete _counter;
	} else {
		--(*_counter);
	}
}


template<typename T>
T* MySharedPointer<T>::get() const
{
	return _value;
}


template<typename T>
void MySharedPointer<T>::reset(T* value)
{
	if (*_counter <= 1) {
		delete _value;
		--(*_counter);
	}
	else {
		--(*_counter);
		_counter = new unsigned int(0);
	}

	_value = value;
	++(*_counter);
}


template<typename T>
T& MySharedPointer<T>::operator*() const
{
	return *_value;
}


template<typename T>
T* MySharedPointer<T>::operator->() const
{
	return _value;
}
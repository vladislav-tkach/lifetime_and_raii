#pragma once

#pragma once

template<typename T>
class MyUniquePointer
{
public:
	MyUniquePointer();
	explicit MyUniquePointer(T* value);
	MyUniquePointer(const MyUniquePointer<T>& ptr) = delete;
	//MyUniquePointer(MyUniquePointer<T>&& ptr);
	~MyUniquePointer();

	T* get() const;
	void reset(T* value);
	T* release();
	T& operator*() const;
	T* operator->() const;
private:
	T* _value;
};

template<typename T>
MyUniquePointer<T>::MyUniquePointer()
{
	_value = nullptr;
}


template <typename T>
MyUniquePointer<T>::MyUniquePointer(T* value)
{
	_value = value;
}


/*template <typename T>
MyUniquePointer<T>::MyUniquePointer(MyUniquePointer<T>&& ptr)
{
	_value(std::move(ptr._value));
}*/


template<typename T>
MyUniquePointer<T>::~MyUniquePointer()
{
	delete _value;
}


template<typename T>
T* MyUniquePointer<T>::get() const
{
	return _value;
}


template<typename T>
void MyUniquePointer<T>::reset(T* value)
{
	delete _value;
	_value = value;
}

template<typename T>
T* MyUniquePointer<T>::release()
{
	auto temp = _value;
	_value = nullptr;
	return temp;
}


template<typename T>
T& MyUniquePointer<T>::operator*() const
{
	return *_value;
}


template<typename T>
T* MyUniquePointer<T>::operator->() const
{
	return _value;
}
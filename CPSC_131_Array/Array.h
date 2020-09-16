#ifndef ARRAY_H
#define ARRAY_H

template <typename T>

class Array
{
public:

	Array(int size, T default_value)
	: elements_(new T [size]), size_(size)
	{
		for (int i = 0; i < size_; i++)
		{
			elements_[i] = default_value;
		}
	}
	
private:
	T* elements_;
	int size_;
};

#endif // !ARRAY_H

#ifndef ARRAY_H
#define ARRAY_H

template <typename T>

class Array
{
public:

	Array()		// Default Constructor
	: elements_(new T[0]), size_(0) { }

	Array(int size, T default_value)	// Initialization
	: elements_(new T [size]), size_(size)
	{
		if (size < 0)
		{
			throw std::out_of_range("Array::Array size must not be negative");
		}

		for (int i = 0; i < size_; i++)
		{
			elements_[i] = default_value;
		}
	}

	Array(const Array& other) 
	: elements_(new T[other.size_]), size_(other.size_)
	{ 
		for (int i = 0; i < size_; i++) 
		{ 
			elements_[i] = other.elements_[i]; 
		} 
	}

	~Array()	// Destructor
	{
		delete [] elements_;
	}

	Array& operator = (const Array& rhs)
	{
		delete[] elements_;

		size_ = rhs.size_;
		elements_ = new T[rhs.size_];

		for (int i = 0; i < size_; i++)
		{
			elements_[i] = rhs.elements_[i];
		}
		return *this;
	}

	int Size()	// Returns the size
	{
		return size_;
	}

	T Get(int i)	// Return the value x[i]
	{
		if ((i < 0) || (i >= Size()))	// When i is out of range, it throws a range_error
		{
			throw std::out_of_range("Array::Get index i out of range");
		}

		return elements_[i];
	}

	void Set(int i, T x)
	{
		if ((i < 0) || (i >= Size())) // When i is out of range, it throws a range_error
		{
			throw std::out_of_range("Array::Set index i out of range");
		}
		elements_[i] = x;
	}

	void Add(int i, T x)
	{
		throw std::overflow_error("Array:Add cannot add any elements");
	}
	
	void Remove(int i, T x)
	{
		throw std::underflow_error("Array:Remove cannot remove any elements");
	}

private:
	T* elements_;
	int size_;
};

#endif // !ARRAY_H
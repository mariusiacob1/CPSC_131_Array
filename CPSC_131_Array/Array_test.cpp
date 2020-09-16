#include <iostream>

#include "Array.h"

using namespace std;

int main(int argc, char* argv[])
{
	Array<float> a1(0, 0.0);

	Array<int> a2(5, 1);

	cout << "a1 size: " << a1.Size() << endl;
	cout << "a2 size: " << a2.Size() << endl;

	for (int i = 0; i < a2.Size(); i++)
	{
		cout << "Get(i): " << a2.Get(i) << endl;
	}

	a2.Set(1, 99);
	cout << "--" << endl;

	for (int i = 0; i < a2.Size(); i++)
	{
		cout << "Get(i): " << a2.Get(i) << endl;
	}

	try
	{
		a2.Get(1000 * 100);
	}
	
	catch (std::out_of_range e)
	{
		cout << "a2.Get threw an exception, what is " << e.what() << endl;
	}

	Array<int> a3(a2);		// Copy constructor
	
	Array<int> a4;
	a4 = a3;

	return 0;
}
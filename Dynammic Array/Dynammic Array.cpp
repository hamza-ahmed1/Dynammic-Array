// Dynammic Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class dynamicArray
{

public:
	dynamicArray();
	~dynamicArray();
	int& operator [](int index);
	void Add(int val);//add element to last index:
	void Print();
	int Length();
	int LastIndex();
		
	
	

private:
	int* p;
	static int size;

};
int dynamicArray::size = 0;
dynamicArray::dynamicArray()
{
	p = new int(0);
}



dynamicArray::~dynamicArray()
{
}

int& dynamicArray::operator[](int index)
{
	if (index < size) {
	//condition ensure if updation done only :
	return *(p + index);
	}
	else {
		int* temparr = new int[index] {};
		for (int i = 0; i < size; i++)
		{
			temparr[i] = p[i];
		}
	//	delete [] p;
		p = NULL;
		p = temparr;
		size = index+1;
		return *(p + index);
	}
	
}

void dynamicArray::Add(int val)
{
	p[size] = val;
	int nextsize = size + 1;
	int* temparr = new int[nextsize] {};
	for (int i = 0; i < nextsize; i++)
	{
		temparr[i] = p[i];
	}
//	delete[] p;
	p = NULL;
	p = temparr;
	size++;
}

void dynamicArray::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

int dynamicArray::Length()
{
	return size;
}

int dynamicArray::LastIndex()
{
	return size - 1;
}

int main()
{
	dynamicArray arr;
	arr.Add(1);
	arr.Add(2);
	arr.Add(3);
	arr.Add(4);
	arr.Add(5);
	arr[5] = 2;//add an element at index=5; 
	arr[1] = 3;//update an element at index=1
	arr[2] = 7;//update an element at index=1
	arr[12] = 7;//add an element at index=12 
	arr.Print();
	cout <<"Length :" << arr.Length() << endl;
	cout << "Last Index :" << arr.LastIndex() << endl;

}


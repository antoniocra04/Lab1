#include <iostream>
#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray()
{
	_capacity = 4;
	_length = 0;
	_array = new int[_capacity];
}

DynamicArray::~DynamicArray()
{
	delete[] _array;
}

void DynamicArray::IncreaseCapacity()
{
	int* ptrArray = _array;
	_capacity += 1;
	_array = new int[_capacity];

	for (int i = 0; i < _length; i++) 
	{
		_array[i] = ptrArray[i];
	}

	delete[] ptrArray;
}

void DynamicArray::DecreaseCapacity()
{
	int* ptrArray = _array;
	_capacity -= 1;
	_array = new int[_capacity];

	for (int i = 0; i < _length; i++)
	{
		_array[i] = ptrArray[i];
	}

	delete[] ptrArray;
}

DynamicArray& DynamicArray::InsertElement(const int& value, const int index)
{
	int* tempArray = _array;

	if(_capacity <= _length)
	{
		_capacity += 1;
	}

	_array = new int[_capacity];
	_length += 1;

	int j = 0;
	for (int i = 0; i < _length; i++)
	{
		if (i != index)
		{
			_array[i] = tempArray[j];
			j++;
		}
		else
		{
			_array[i] = value;
		}
	}

	return *this;
}

DynamicArray& DynamicArray::InsertAtBeginning(const int& value)
{
	InsertElement(value, 0);
	return *this;
}

DynamicArray& DynamicArray::InsertAtEnd(const int& value)
{
	InsertElement(value, _length);
	return *this;
}

DynamicArray& DynamicArray::AddElement(const int& value)
{
	InsertElement(value, _length);
	return *this;
}

DynamicArray& DynamicArray::DeleteElement(const int& index)
{
	if(index < 0 || _length == 0)
	{
		cout << "Index < 0 or length = 0" << endl;
		return *this;
	}

	int j = 0;
	for (int i = 0; i < _length; i++) 
	{
		if (i != index) 
		{
			_array[j] = _array[i];
			j++;
		}
	}

	_length -= 1;

	DecreaseCapacity();

	return *this;
}

DynamicArray& DynamicArray::Sort() 
{
	int temp = 0;

	for (int i = 0; i < _length; i++)
	{
		for (int j = 0; j < _length; j++) 
		{
			if(_array[i] < _array[j])
			{
				temp = _array[i];
				_array[i] = _array[j];
				_array[j] = temp;
			}
		}
	}

	return *this;
}

int DynamicArray::LinearSearch(const int& value)
{
	for (int i = 0; i < _length; i++)
	{
		if (_array[i] == value) {
			return i;
		}
	}

	return -1;
}

int DynamicArray::BinarySearch(const int& value)
{
	int right = _length-1, left = 0;

	while (right > left) {
		int middle = (right + left) / 2;

		if (_array[middle] < value)
		{
			left = middle + 1;
		}
		else if (_array[middle] > value) 
		{
			right = middle - 1;
		}
		else
		{
			return middle;
		}
	}

	return -1;
}

int& DynamicArray::operator[](const int& index) const
{
	return _array[index];
}

ostream& operator<<(ostream& os, const DynamicArray& array)
{
	os << "Current array: [ ";

	for (int i = 0; i < array._length; i++)
	{
		os << array[i] << " ";
	}

	os << "] | capacity: " << array._capacity << " | length: " << array._length;
	return os;
}
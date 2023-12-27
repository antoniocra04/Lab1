#pragma once
#include <iostream>

using std::ostream;

struct DynamicArray 
{
private:
	int _capacity;
	int _length;
	int* _array;

	void IncreaseCapacity();
	void DecreaseCapacity();

public:
	DynamicArray();
	~DynamicArray();

	/*
		Добавления элемента в массив
		@param value - значение нового элемента
		@return DynamicArray
	*/
	DynamicArray& AddElement(const int& value);

	/*
		Удаление элемента из массива
		@param value - значение нового элемента
		@return DynamicArray
	*/
	DynamicArray& DeleteElement(const int& index);

	/*
		Вставка элемента в начало
		@param value - значение нового элемента
		@return DynamicArray
	*/
	DynamicArray& InsertAtBeginning(const int& value);

	/*
		Вставка элемента в конец
		@param value - значение нового элемента
		@return DynamicArray
	*/
	DynamicArray& InsertAtEnd(const int& value);

	/*
		Вставка после определенного элемента
		@param value - значение нового элемента
		@return DynamicArray
	*/
	DynamicArray& InsertElement(const int& value, const int index);

	/*
		Сортировка массива
		@param value - значение нового элемента
		@return DynamicArray
	*/
	DynamicArray& Sort();

	/*
		Линейный поиск элемента в массиве
		@param value - значение нового элемента
		@return DynamicArray
	*/
	int LinearSearch(const int& value);

	/*
		Бинарный поиск элемента в массиве
		@param value - значение нового элемента
		@return DynamicArray
	*/
	int BinarySearch(const int& value);

	int& operator[](const int& index) const;
	friend ostream& operator<<(ostream& os, const DynamicArray& array);
};
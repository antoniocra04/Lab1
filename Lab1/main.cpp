#include <iostream>
#include "DynamicArray.h"
using namespace std;

DynamicArray* arr = new DynamicArray;

void PrintDynamicArray(DynamicArray* array)
{
    cout << "Current array: [ ";

    for (int i = 0; i < array->_length; i++)
    {
        cout << array->_array[i] << " ";
    }

    cout << "] | capacity: " << array->_capacity << " | length: " << array->_length;
}

void MenuMessage()
{
    PrintDynamicArray(arr);
    cout << "Choose one action: \n1) Add element \n2) Delete element \n3) Insert element into begining \n"
        << "4) Insert element into End \n5) Insert element \n6) Sort array \n7) Linear search \n"
        << "8) Binary search \nq - Quit \nYour choice: ";
}

void ModeControl(const char& mode)
{
    switch (mode)
    {
        static int index;
        static int value;
        static int searchingIndex;
    case '1':
        cout << "Enter value of adding element: ";
        cin >> value;
        arr->AddElement(value);
        break;
    case '2':
        PrintDynamicArray(arr);
        cout << endl << "Enter index of deleting element: ";
        cin >> index;
        arr->DeleteElement(index);
        break;
        PrintDynamicArray(arr);
    case '3':
        cout << endl << "Enter value of element inserting into begining: ";
        cin >> value;
        arr->InsertAtBeginning(value);
        break;
        PrintDynamicArray(arr);
    case '4':
        cout << endl << "Enter value of element inserting into end: ";
        cin >> value;
        arr->InsertAtEnd(value);
        break;
        PrintDynamicArray(arr);
    case '5':
        cout << endl << "Enter value of element: ";
        cin >> value;
        cout << "Enter the index: ";
        cin >> index;
        arr->InsertElement(value, index);
        break;
        PrintDynamicArray(arr);
    case '6':
        cout << "Array sorted" << endl;
        arr->Sort();
        break;
    case '7':
        PrintDynamicArray(arr);
        cout << endl << "Enter value of element needed to linear search: ";
        cin >> value;
        searchingIndex = arr->LinearSearch(value);
        if (searchingIndex == -1)
        {
            cout << "No elements found" << endl;
        }
        else
        {
            cout << "Index of searching element: " << searchingIndex << endl;
        }
        break;
    case '8':
        PrintDynamicArray(arr);
        cout << endl << "Enter value of element needed to binary search: ";
        cin >> value;
        searchingIndex = arr->BinarySearch(value);
        if (searchingIndex == -1)
        {
            cout << "No elements found" << endl;
        }
        else
        {
            cout << "Index of searching element: " << searchingIndex << endl;
        }
        break;
    default:
        break;
    }
}

int main()
{
    char mode;

    MenuMessage();
    mode = cin.get();
    while (cin.get() != '\n');
    while (mode != 'q')
    {
        system("cls");
        ModeControl(mode);

        MenuMessage();

        while (cin.get() != '\n');

        if (cin.peek() != '\n')
        {
            mode = cin.get();
        }
        else
        {
            mode = '\0';
        }
    }

    return 0;
}


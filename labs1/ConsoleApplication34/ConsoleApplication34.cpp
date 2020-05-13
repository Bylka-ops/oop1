// ConsoleApplication34.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"

int main()
{

	try
	{
		Array<int> Mas;
		Mas.set_array();
		Mas.get_array();
		Mas.sort();
		cout << endl;
		Mas.get_array();
		Mas.add_array(30);
		cout << endl;
		Mas.get_array();
		Mas.delete_array(2);
		cout << endl;
		Mas.get_array();
		cout << endl;
		Mas.find_array(30);
		Mas.find_array(117);

	}

	catch(Array<int>::size)
	{ 
		cout << "the array is empty"<<endl;
	}
	catch (Array<int>::input)
	{
		cout << "invalid input" << endl;
	}
	catch (Array<int>::memory)
	{
		cout << "memory freed" << endl;
	}
	catch (Array<int>::Delete)
	{
		cout << "array size is smaller" << endl;
	}
	system("pause");
}

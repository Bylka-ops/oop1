#pragma once
#include <iostream>

using namespace std;
template <typename T>
class Array
{
private:
	T *mas;
	int count;
	void quickSort(T *numbers, int left, int right);
public:
	class size
	{

	};
	class Delete
	{

	};
	class input
	{

	};
	class memory
	{

	};
	Array();
	void add_array(T new_size);
	void delete_array(T new_size);
	void find_array(T new_size);
	void set_array();
	void get_array();
	void sort();
	~Array();

private:

};

template <typename T>
Array<T>::Array()
{
	cout<<"enter size array"<<endl;
	if (!(cin >> count))
		throw input();
	mas = new T[count];


}

template <typename T>
void Array<T>::add_array(T new_mas)
{
	
	T *mas1 = new T[count];
	for (int i = 0; i < count; i++)
	{
		mas1[i] = mas[i];
	}
	delete mas;	
	count++;
	mas = new T[count];
	for (int i = 0; i < count; i++)
	{
		mas[i] = mas1[i];
	}
	delete mas1;
	mas[count - 1] = new_mas;
}

template <typename T>
void Array<T>::find_array(T new_mas)
{
	bool flag = false;
	for (int i = 0; i < count; i++)
	{
		if (mas[i] == new_mas)
			flag = true;
	}
	if (flag == true)
		cout << "yes" << endl;
	else 
		cout << "no" << endl;
}

template <typename T>
void Array<T>::delete_array(T new_mas)
{
	if (new_mas>count)
	{
		throw Delete();
	}
	else
	{
		if (new_mas == count)
			count--;
		else
		{
			T* mas1 = new T[count - 1];
			int k = 0;
			for (int i = 0; i < count; i++)
			{
				if (new_mas - 1 == i)
					i++;
				mas1[k] = mas[i];
				k++;
			}
			count--;
			for (int i = 0; i < count; i++)
			{
				mas[i] = mas1[i];
			}
			delete[] mas1;
		}
	}
}

template <typename T>
void Array<T>::quickSort(T *numbers, int left, int right)
{
	T pivot; 
	int l_hold = left; 
	int r_hold = right; 
	pivot = numbers[left];
	while (left < right) 
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; 
		if (left != right) 
		{
			numbers[left] = numbers[right]; 
			left++; 
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; 
		if (left != right) 
		{
			numbers[right] = numbers[left]; 
			right--; 
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) 
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}

template <typename T>
void Array<T>::set_array()
{
	for (int i = 0; i < count; i++)
	{
		mas[i] = rand()%10;
	}
}

template <typename T>
void Array<T>::get_array()
{
	for (int i = 0; i < count; i++)
	{
		cout << mas[i] << " ";
	}
}

template <typename T>
void Array<T>::sort()
{
	if (count==0)
		throw size();
	quickSort(mas, 0, count - 1);
}

template <typename T>
Array<T>::~Array()
{
	if (!mas)
		throw memory();
	delete[] mas;
}
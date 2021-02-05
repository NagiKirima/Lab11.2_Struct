#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct List 
{
	string data;
	List* next_block;
	List* previous_block;

};
int GetSize()
{
	int size;
	cin >> size;
	while (size <= 0)
	{
		cout << "������� ���������� �����:\t";
		cin >> size;
	}
	return size;
}
List* CreateList(int size) 
{
	List* first_element = nullptr;
	List* current_element;
	if (size == 1)
	{
		cout << "������� 0-� ������� ������:\t";
		current_element = new List;
		cin >> current_element->data;
		first_element = current_element;
		current_element->next_block = nullptr;
		current_element->previous_block = nullptr;
	}
	else
	{
		cout << "������� 0-� ������� ������:\t";
		current_element = new List;
		cin >> current_element->data;
		first_element = current_element;
		current_element->next_block = nullptr;
		current_element->previous_block = nullptr;
		for (int i = 1; i < size; i++)
		{
			cout << "������� " << i << "-� ������� ������:\t";
			List* new_element = new List;
			current_element->next_block = new_element;
			new_element->previous_block = current_element;
			current_element = new_element;
			cin >> current_element->data;
			current_element->next_block = nullptr;
		}
	}
	return first_element;
}
int Size(List* first_element)
{
	if (first_element == nullptr) return 0;
	int size = 0;
	if (first_element->previous_block == nullptr)
	{
		while (first_element != nullptr)
		{
			size++;
			first_element = first_element->next_block;
		}
	}
	else if (first_element->next_block == nullptr)
	{
		while (first_element != nullptr)
		{
			size++;
			first_element = first_element->previous_block;
		}
	}
	return size;
}
void PrintList(List* first_element) 
{
	if (first_element == nullptr)
	{
		cout << "������ ����!" << endl;
		return;
	}
	int size = Size(first_element);
	cout << "����� ������ � ������ �������:" << endl;
	int i = 0;
	while (first_element != nullptr)
	{
		cout << i << "-� ������� �������:\t" << first_element->data << endl;
		first_element = first_element->next_block;
		i++;
	}
	cout << endl;
}
bool AddElement(List*& first_element) 
{
	string value;
	cout << "������� ���� ��������, ����� �������� ����� �������� ����� �������:\t";
	cin >> value;
	bool check = false;
	List* current_element = first_element;
	while (current_element != nullptr)
	{
		if (current_element->data == value && current_element->next_block != nullptr)
		{
			List* tmp1 = new List;
			cout << "������� �������� ������ ��������:\t";
			cin >> tmp1->data;

			List* tmp2 = current_element->next_block;
			tmp2->next_block = current_element->next_block->next_block;
			current_element->next_block = tmp1;
			tmp1->previous_block = current_element;
			tmp1->next_block = tmp2;
			tmp2->previous_block = tmp1;
			check = true;
		}
		else if (current_element->data == value && current_element->next_block == nullptr)
		{
			List* tmp1 = new List;
			cout << "������� �������� ������ ��������:\t";
			cin >> tmp1->data;

			current_element->next_block = tmp1;
			tmp1->previous_block = current_element;
			tmp1->next_block = nullptr;
			check = true;
		}
		current_element = current_element->next_block;
	}
	return check;
}
int main() 
{
	setlocale(LC_ALL, "ru");
	List* list;
	cout << "������� ����� ������:\t";
	int size = GetSize();
	cout << "=====================================================" << endl;
	list = CreateList(size);
	cout << "=====================================================" << endl;
	cout << "����������� ������:" << endl << endl;
	PrintList(list);
	cout << "=====================================================" << endl;
	if (AddElement(list)) 
	{
		cout << "=====================================================" << endl;
		cout << "���������� ������:" << endl << endl;
		PrintList(list);
		cout << "=====================================================" << endl;
	}
	else 
	{
		cout << "������ �������� ���!" << endl;
	}
}
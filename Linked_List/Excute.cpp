#include "LinkedList.h"

typedef LinkedList<int> List;
typedef DoubleLinkedList<int> DoubleList;

int main()
{
	/*List* list = new List();
	for (int i = 1; i <= 7; i++)
	{
		int* index = new int;
		*index = *(&i);
		list->Push(List::Create(&index));
	}

	list->Print();

	cout << list->GetSize() << endl << endl;

	int* index = new int;
	*index = 20;
	list->Insert(3, List::Create(&index));

	list->Print();

	list->Pop_Back();
	list->Print();

	list->Delete(list->GetNode(3));
	list->Print();

	list->Delete(0);
	list->Print();

	list->Delete(4);
	list->Print();*/

	DoubleList* doubleList = new DoubleList;
	for (int i = 1; i <= 7; i++)
	{
		int* index = new int;
		*index = *(&i);
		doubleList->Push_Back(DoubleList::Create(&index));
	}

	doubleList->Print();

	cout << doubleList->GetSize() << endl << endl;

	int* index = new int;
	*index = 20;
	doubleList->Push_Cur(DoubleList::Create(&index));

	doubleList->Print();

	cout << doubleList->GetSize() << endl << endl;

	DoubleList::Node* node = doubleList->Pop_Back();
	cout << *node->Data << endl;

	doubleList->Print();

	node = doubleList->Pop_Cur();
	cout << *node->Data << endl;

	doubleList->Print();

	
	return 0;
}
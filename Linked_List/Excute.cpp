#include "LinkedList.h"

typedef LinkedList<int> List;

int main()
{
	List* list = new List();
	for(int i = 1; i <= 7; i++)
		list->Push(List::Create(i));

	list->Print();

	cout << list->GetNodeCount() << endl << endl;

	list->Insert(3, List::Create(20));

	list->Print();

	list->Pop_Back();
	list->Print();

	list->Delete(list->GetNode(3));
	list->Print();

	list->Delete(0);
	list->Print();

	list->Delete(4);
	list->Print();
	
	return 0;
}
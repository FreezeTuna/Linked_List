#include "LinkedList.h"

typedef LinkedList<int> List;

int main()
{
	List::Node* node = List::Create(1);
	
	List* list = new List(node);
	for(int i = 2; i <= 7; i++)
		list->Push(List::Create(i));

	list->Print(list->Head());

	cout << list->GetNodeCount() << endl << endl;

	list->Insert(3, List::Create(20));

	list->Print(list->Head());

	
	return 0;
}
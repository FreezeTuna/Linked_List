#pragma once

#include <iostream>
using namespace std;

template<typename T>
class LinkedList
{
public:
	//전방 선언 < 이후에 정의를 해줄거기에 미리 알려준다. >
	struct Node;

public:
	//Set Head Node
	LinkedList(Node* head)
	{
		this->head = head;
	}

	//Get Head Node
	Node* Head() { return head; }

public:
	//Add New Node
	static Node* Create(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;

		return node;
	}
	
	//Remove Node
	static void Destroy(Node* node)
	{
		delete node;
		node = NULL;
	}
	//Remove Node With Index
	static void Destroy(int location)
	{
		Node* current = head;
		Node* prev;
		Node* next;
		int count = 0;

		while (current->Next != NULL && count++ != location)
		{
			current = current->Next;
			if (count == location - 1)
				prev = current;
		}
		next = current->Next;

		prev->Next = next;
		delete current;
		current = NULL;
	}

public:
	//Push Node to End
	void Push(Node* node)
	{
		Node* tail = head;
		while (tail->Next != NULL)
			tail = tail->Next;
		tail->Next = node;
		node->Next = NULL;
	}
	//Insert Node to Behind Current Node
	void Insert(Node* current, Node* node)
	{
		node->Next = current->Next;
		current->Next = node;
	}
	//Insert Node to Behind Location Index
	void Insert(int location, Node* node)
	{
		Node* current = head;
		int count = 0;
		while (current->Next != NULL && count++ != location)
			current = current->Next;
		node->Next = current->Next;
		current->Next = node;
	}

	//Get Node from Location Index
	Node* GetNode(int location)
	{
		Node* current = head;
		int count = 0;
		while (current->Next != NULL && count++ != location)
			current = current->Next;
		return current;
	}

	//Get Node Count
	int GetNodeCount()
	{
		Node* current = head;
		int count = 0;
		while (current->Next != NULL)
		{
			current = current->Next;
			count++;
		}
		return count;
	}

	//Print Node <재귀 함수>
	void Print(Node* node)
	{
		if (node == NULL)
		{
			cout << endl;
			return;
		}
		cout << node->Data;
		if (node->Next != NULL)
			cout << " -> ";
		Print(node->Next);
	}

public:
	//Struct of Linked List Node
	struct Node
	{
		//Linked List Data
		T Data;
		//Linked List Next Node Pointer
		Node* Next;
	};

private:
	//Add Linked List Head Node
	Node* head;

};
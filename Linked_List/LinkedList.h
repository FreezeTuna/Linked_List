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
	////Set Head Node
	//LinkedList(Node* head)
	//{
	//	this->head = head;
	//}

	//Get Head Node
	//Node* Head() { return head; }

public:
	//Add New Node
	static Node* Create(T** data)
	{
		Node* node = new Node();
		node->Data = *data;
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
		Node* current = m_Head;
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
		if (m_Head == NULL)
		{
			node->Next = NULL;
			m_Head = node;
			return;
		}

		Node* tail = m_Head;
		while (tail->Next != NULL)
			tail = tail->Next;
		tail->Next = node;
		node->Next = NULL;
	}

	//	Pop to End
	void Pop_Back()
	{
		if (m_Head == NULL)
		{
			return;
		}

		Node* tail = m_Head;
		Node* prev = NULL;
		while (tail->Next != NULL)
		{
			prev = tail;
			tail = tail->Next;
		}

		prev->Next = NULL;
		delete tail;
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
		Node* current = m_Head;
		int count = 0;
		while (current->Next != NULL && count++ != location)
			current = current->Next;
		node->Next = current->Next;
		current->Next = node;
	}
	//Delete Node from Node
	void Delete(Node* node)
	{
		if (m_Head == NULL)
		{
			return;
		}

		if (m_Head->Data == node->Data)
		{
			delete m_Head;
			m_Head = NULL;
		}

		Node* findNode = m_Head;
		Node* prev = NULL;
		Node* next = NULL;
		while (findNode->Next != NULL)
		{
			if (findNode->Next->Data == node->Data)
			{
				prev = findNode;
				findNode = findNode->Next;
				next = findNode->Next;
				break;
			}
			findNode = findNode->Next;
		}

		if (prev == NULL)
		{
			return;
		}

		prev->Next = next;
		delete findNode;
	}
	//Delete Node from Location
	void Delete(int location)
	{
		if (GetSize() < location)
		{
			return;
		}

		if (m_Head == NULL)
		{
			return;
		}

		if (location == 0)
		{
			Node* next = m_Head->Next;
			delete m_Head->Data;
			delete m_Head;
			m_Head = next;
			return;
		}

		Node* current = m_Head;
		Node* prev = NULL;
		Node* next = NULL;
		int count = 0;
		while (current->Next != NULL && count++ != location)
		{
			if (count == location)
			{
				prev = current;
				next = current->Next->Next;
				current = current->Next;
				break;
			}
			current = current->Next;
		}

		prev->Next = next;
		delete current->Data;
		delete current;
	}

	//Get Node from Location Index
	Node* GetNode(int location)
	{
		Node* current = m_Head;
		int count = 0;
		while (current->Next != NULL && count++ != location)
			current = current->Next;
		return current;
	}

	//Get Node Count
	int GetSize()
	{
		Node* current = m_Head;
		int count = 0;
		while (current->Next != NULL)
		{
			current = current->Next;
			count++;
		}
		return count;
	}

	//Print Node <재귀 함수>
	void Print(Node* node = NULL)
	{
		if (node == NULL)
		{
			if (m_Head != NULL)
			{
				cout << *m_Head->Data;
				if (m_Head->Next != NULL)
				{
					cout << " -> ";
					Print(m_Head->Next);
				}
			}
			return;
		}
		cout << *node->Data;
		if (node->Next != NULL)
		{
			cout << " -> ";
			Print(node->Next);
		}
		else
		{
			cout << endl;
		}
	}

public:
	//Struct of Linked List Node
	struct Node
	{
		//Linked List Data
		T* Data;
		//Linked List Next Node Pointer
		Node* Next;
	};

private:
	//Add Linked List Head Node
	Node* m_Head = NULL;
};

template<typename T>
class DoubleLinkedList
{
public:
	struct Node;

public:
	//Add New Node
	static Node* Create(T** data)
	{
		Node* node = new Node();
		node->Data = *data;
		node->Next = NULL;

		return node;
	};

public:
	bool SetCurNode()
	{
		return false;
	}

	void Push_Back(Node* node)
	{
		if (m_HeadNode == NULL)
		{
			node->Next = NULL;
			node->Prev = NULL;
			m_HeadNode = node;
			m_CurNode = node;
			return;
		}

		m_CurNode->Next = node;
		node->Prev = m_CurNode;
		node->Next = NULL;

		m_CurNode = node;
	}

	void Push_Cur(Node* node)
	{
		if (m_CurNode == NULL)
		{
			return;
		}

		if (m_CurNode->Next != NULL)
		{
			Node* nextNode = m_CurNode->Next;
			nextNode = node;
			nextNode->Prev = node;
			node->Prev = m_CurNode;
			node->Next = nextNode;
			m_CurNode = node;
		}
		else
		{
			m_CurNode->Next = node;
			node->Prev = m_CurNode;
			m_CurNode = node;
		}
	}

	Node* Pop_Back()
	{
		if (m_HeadNode == NULL)
		{
			return NULL;
		}

		while (m_CurNode->Next != NULL)
		{
			m_CurNode = m_CurNode->Next;
		}

		Node* popNode = m_CurNode;

		m_CurNode->Prev->Next = NULL;

		m_CurNode = m_CurNode->Prev;

		return popNode;
	}

	Node* Pop_Cur()
	{
		if (m_CurNode == NULL)
		{
			return NULL;
		}

		Node* popNode = m_CurNode;

		if (m_CurNode->Next != NULL)
		{
			m_CurNode->Prev->Next = m_CurNode->Next;
			m_CurNode->Next->Prev = m_CurNode->Prev;
			m_CurNode = m_CurNode->Prev;
		}
		else
		{
			m_CurNode->Prev->Next = NULL;
			m_CurNode = m_CurNode->Prev;
		}

		return popNode;
	}

	void RemoveAll()
	{
		if (m_HeadNode == NULL)
		{
			return;
		}

		if (m_HeadNode->Next == NULL)
		{
			delete m_HeadNode->Data;
			delete m_HeadNode;

			m_HeadNode = NULL;
			m_CurNode = NULL;
			return;
		}

		while (m_CurNode != NULL)
		{
			Node* temp = m_CurNode;
			m_CurNode = m_CurNode->Next;
			delete temp->Data;
			delete temp;
		}


		m_HeadNode = NULL;
		m_CurNode = NULL;
	}

	int GetSize()
	{
		if (m_HeadNode == NULL)
		{
			return 0;
		}

		Node* End = m_HeadNode;
		int Count = 1;

		while (End->Next != NULL)
		{
			End = End->Next;
			Count++;
		}

		return Count;
	}

	//Print Node <재귀 함수>
	void Print(Node* node = NULL)
	{
		if (node == NULL)
		{
			if (m_HeadNode != NULL)
			{
				cout << *m_HeadNode->Data;
				if (m_HeadNode->Next != NULL)
				{
					cout << " -> ";
					Print(m_HeadNode->Next);
				}
			}
			return;
		}
		cout << *node->Data;
		if (node->Next != NULL)
		{
			cout << " -> ";
			Print(node->Next);
		}
		else
		{
			cout << endl;
		}
	}

public:
	//Struct of Linked List Node
	struct Node
	{
		//Linked List Data
		T* Data;
		Node* Prev;
		//Linked List Next Node Pointer
		Node* Next;
	};

private:
	//Add Linked List Head Node
	Node* m_HeadNode = NULL;
	Node* m_CurNode = NULL;
};
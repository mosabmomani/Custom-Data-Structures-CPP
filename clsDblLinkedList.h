#pragma once
#include<iostream>
using namespace std;
template<class T>
class clsDblLinkedList
{
protected:
	int _Size = 0;

public:
	class  Node
	{
	public:
		T Value;
		Node* next;
		Node* prev;

	};

	Node* head = NULL;


	void InsertAtBeginning(T Value) {
		Node* new_node = new Node();

		new_node->Value = Value;
		new_node->prev = NULL;
		new_node->next = head;

		if (head != NULL) {
			head->prev = new_node;
		}

		head = new_node;
		_Size++;
	}
	Node* Find(T value) {
		Node* current = head;

		if (current == NULL)return NULL;

		while (current != NULL) {
			if (current->Value == value)
				return current;

			current = current->next;
		}

		return NULL;
	}
	void InsertAfter(Node* node, T Value) {
		if (node == NULL)return;
		Node* New_node = new Node();
		New_node->Value = Value;
		New_node->prev = node;
		New_node->next = node->next;

		if (node->next != NULL) {
			node->next->prev = New_node;
		}
		node->next = New_node;
		_Size++;
	}
	void InsertAtEnd(T value) {
		Node* New_node = new Node();
		New_node->Value = value;
		New_node->next = NULL;
		_Size++;
		if (head == NULL) {
			New_node->prev = NULL;
			head = New_node;
			return;
		}

		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = New_node;
		New_node->prev = current;

	}
	void DeleteFirstNode() {
		if (head == NULL)return;

		Node* CurrentToDelete = head;
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}

		delete CurrentToDelete;
		_Size--;
	}
	void DeleteLastNode() {
		if (head == NULL)return;
		_Size--;
		Node* NodeToDelete = head;

		if (head->next == NULL) {
			delete NodeToDelete;
			head = NULL;

			return;
		}
		while (NodeToDelete->next != NULL) {
			NodeToDelete = NodeToDelete->next;
		}
		NodeToDelete->prev->next = NULL;
		delete NodeToDelete;

	}
	void DeleteNode(Node* NodetoDelete) {
		if (head == NULL || NodetoDelete == NULL)return;
		_Size--;
		if (NodetoDelete->prev == NULL) {
			DeleteFirstNode();
			return;
		}
		if (NodetoDelete->next == NULL) {
			DeleteLastNode();
			return;
		}

		NodetoDelete->prev->next = NodetoDelete->next;
		NodetoDelete->next->prev = NodetoDelete->prev;

		delete NodetoDelete;

	}

	void PrintList() {
		Node* current = head;
		if (current == NULL)return;
		while (current != NULL) {
			cout << current->Value << "  ";
			current = current->next;
		}
		cout << "\n";
		///*delete current;*/ //we don't need it becose we dont crieat a new node 
	}

	int Size() {
		return _Size;

	}
	bool IsEmpty() {
		return (_Size == 0);
	}
	void Clear() {
		while (_Size != 0) {
			DeleteFirstNode();
		}
	}

	void Revrse() {
		if (head == NULL) return;
		if (head->next == nullptr)return;
		Node* current = head;

		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->prev;
		}
		if (temp != NULL) {
			head = temp->prev;
		}

	}
	Node* GetNode(int index) {
		/*f (head == nullptr)return NULL;*/
		if (index > _Size - 1 || index < 0)return NULL;
		Node* current = head;
		int count = 0;
		while (current != nullptr) {

			if (count == index) {
				return current;
			}
			current = current->next;
			count++;
		}
		return current;
	}

	T GetItem(int numberofitem) {
		if (numberofitem > _Size - 1 || numberofitem < 0)return 0;
		Node* ItemNode = GetNode(numberofitem);
		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->Value;
	}
	bool UpdateItem(int numberofnode, T update) {
		Node* N1 = GetNode(numberofnode);
		if (N1 != NULL) {
			N1->Value = update;
			return true;

		}
		else
			return false;

	}
	bool IsertAfter(T Indix, T toadd) {
		Node* current = GetNode(Indix);
		if (current != NULL) {
			InsertAfter(current, toadd);
			return true;
		}
		else
			return false;

	}

};




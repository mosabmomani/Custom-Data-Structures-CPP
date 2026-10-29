#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;
template<class T>
class clsMyQueue
{
protected:
	clsDblLinkedList<T>_MyList;


public:
	void Push(T value) {
		_MyList.InsertAtEnd(value);
	}
	T Size() {
		return _MyList.Size();
	}
	T Front() {
		return _MyList.GetItem(0);

	}
	T Back() {
		return _MyList.GetItem(Size() - 1);
	}
	bool IsEmpty() {
		return _MyList.IsEmpty();
	}
	void pop() {
		_MyList.DeleteFirstNode();
	}
	void Print() {
		_MyList.PrintList();
	}
	T GetItem(int NumberOfItem) {
		return _MyList.GetItem(NumberOfItem);
	}
	void Reverse() {
		_MyList.Revrse();
	}
	bool UpdateItem(int NumberofItem, T UpdateValue) {
		return	_MyList.UpdateItem(NumberofItem, UpdateValue);
	}
	void InsertAfter(int NumberofItem, T ValuetoAdd) {
		_MyList.InsertAfter(NumberofItem, ValuetoAdd);
	}
	void InsertAtFront(T Item) {
		_MyList.InsertAtBeginning(Item);
	}
	void InsertAtBack(T Item) {
		/*_MyList.InsertAtEnd(Item);*/
		Push(Item);
	}
	void Clear() {
		_MyList.Clear();
	}


};

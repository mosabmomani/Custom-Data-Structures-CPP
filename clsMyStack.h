#pragma once
#include"clsMyQueue.h"
#include<iostream>
using namespace std;
template<class T>
class clsMyStack :public clsMyQueue<T>
{

	

  public:
	void Push(T value) {
		clsMyQueue<int>::_MyList.InsertAtBeginning(value);
	}
	
	T Top() {
		return clsMyQueue<T> ::Front() ;

	}
	T Bottom() {
		return clsMyQueue<T> ::Back();
	}
	
};


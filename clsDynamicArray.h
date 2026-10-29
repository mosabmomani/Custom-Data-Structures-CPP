#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsDynamicArray
{
protected:
	T* _temparray;
	int _Size;
public:
	T* OriginalArray;
	clsDynamicArray(int Size = 0) {
		if (_Size < 0) {
			_Size = 0;
		}

		_Size = Size;
		OriginalArray = new T[Size];

	}
	~clsDynamicArray() {
		delete[] OriginalArray;
	}

	bool SetItem(int index, T value) {
		_Size++;
		if (index >= _Size || _Size < 0) {
			return false;
		}

		OriginalArray[index] = value;
		return true;
	}
	int Size() {
		return _Size;
	}
	bool IsEmpty() {
		if (_Size == 0)
			return true;
		else
			return false;
	}
	void Print() {
		for (int i = 0; i < _Size; i++) {
			cout << OriginalArray[i] << "  ";
		}
	}

	void Resize(int newsize) {
		if (newsize < 0) {
			_Size = 0;
		}
		_temparray = new T[newsize];
		if (newsize < _Size)
			_Size = newsize;

		for (int i = 0; i < _Size; i++) {
			_temparray[i] = OriginalArray[i];
		}
		_Size = newsize;
		delete[]OriginalArray;
		OriginalArray = _temparray;
	}
	T GetItem(int index) {
		return OriginalArray[index];
	}
	void Reverse() {
		if (_Size <= 0)return;

		_temparray = new T[_Size];

		for (int i = 1; i <= _Size; i++) {
			_temparray[i - 1] = OriginalArray[_Size - i];
		}
		delete[]OriginalArray;
		OriginalArray = _temparray;
	}
	void Clear() {

		/*_Size = 0;
		_temparray = new T[0];
		delete[]OriginalArray;
		OriginalArray = _temparray;*/
		Resize(0);

	}
	bool DeleteItemAt(int index) {
		if (index >= _Size || index < 0)return false;
		_Size--;
		_temparray = new T[_Size];
		/*_temparray = new T[_Size - 1];
		int count = 0;
		for (int i = 0; i < _Size; i++) {
			if (i == index) {

				continue;
			}
			_temparray[count] = OriginalArray[i];
			count++;
		}
		_Size--;*/
		for (int i = 0; i < index; i++) {
			_temparray[i] = OriginalArray[i];
		}
		for (int i = index + 1; i < _Size + 1; i++) {
			_temparray[i - 1] = OriginalArray[i];
		}

		delete[]OriginalArray;
		OriginalArray = _temparray;
		return true;
	}

	void DeleteFirstItem() {

		DeleteItemAt(0);
	}
	void DeleteLastItem() {
		DeleteItemAt(_Size - 1);
	}
	int Find(T value) {
		if (_Size == 0)return -1;
		for (int i = 0; i < _Size; i++) {
			if (OriginalArray[i] == value) {
				return i;
			}
		}
		return -1;
	}
	bool DeleteItem(T value) {
		int index = Find(value);
		if (index == -1)return false;
		DeleteItemAt(index);
		return true;
	}
	bool InsertAt(int index, T value) {
		if (index > _Size || index < 0)return false;

		_Size++;
		_temparray = new T[_Size];

		for (int i = 0; i < index; i++) {
			_temparray[i] = OriginalArray[i];
		}

		_temparray[index] = value;
		for (int i = index; i < _Size - 1; i++) {
			_temparray[i + 1] = OriginalArray[i];
		}
		delete[]OriginalArray;
		OriginalArray = _temparray;
		return true;

	}
	bool InsertAtBeginning(T value) {
		return InsertAt(0, value);
	}
	bool InsertAtEnd(T value) {

		return InsertAt(_Size, value);
	}
	bool InsertAfter(int index, T value) {
		if (index >= _Size)return InsertAt(_Size, value);
		else
			return InsertAt(index + 1, value);
	}
	bool InsertBefore(int index, T value) {
		if (index < 1)return InsertAt(0, value);
		else
			return InsertAt(index - 1, value);
	}
}; 

Custom C++ Data Structures Library

A collection of custom, header-only data structures implemented from scratch in C++ using Object-Oriented Programming (OOP), Templates, and manual memory management.

Note: These projects were built as part of my learning path and practical exercises a while ago to deeply understand how fundamental data structures work under the hood without relying solely on the Standard Template Library (STL).

📂 Included Data Structures

clsDynamicArray.h

A custom template-based dynamic array implementation supporting resizing, element insertion/deletion at specific indices, searching, reversing, and clearing.

clsDblLinkedList.h

A fully functional Doubly Linked List implementation supporting node operations, navigation, insertion (beginning, end, after, before), deletion, and reversal.

clsMyQueue.h

A Queue data structure built on top of the custom clsDblLinkedList, implementing FIFO (First-In, First-Out) behavior with standard operations (Push, pop, Front, Back, Size, etc.).

clsMyQueueArr.h

An alternative Queue implementation built using the custom clsDynamicArray.

clsMyStack.h

A Stack data structure built using inheritance from clsMyQueue, implementing LIFO (Last-In, First-Out) behavior (Push, Top, Bottom, etc.).

🚀 Getting Started

Since this is a header-only library, you can simply copy the .h files into your project and include them directly:

#include "clsMyStack.h"
#include <iostream>

using namespace std;

int main() {
    clsMyStack<int> myStack;
    myStack.Push(10);
    myStack.Push(20);
    myStack.Push(30);

    cout << "Top: " << myStack.Top() << endl;       // Output: 30
    cout << "Bottom: " << myStack.Bottom() << endl; // Output: 10
    
    return 0;
}


🛠️ Technologies Used

Language: C++

Concepts: Object-Oriented Programming (OOP), Templates, Pointers, Dynamic Memory Allocation, Inheritance.

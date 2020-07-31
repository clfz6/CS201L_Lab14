#pragma once
#include <string> 
#include <list>
#include <iostream>
using namespace std; 

class MyListException {
public: 
    MyListException(const string& M = "List Exception") { Msg = M; }
    string what() const { return Msg; }
private: 
    string Msg; 
};

template <class T> 
class MyList {
public: 
    MyList(); 
    MyList(const MyList<T>& other); 
    const MyList<T>& operator=(const MyList<T>& rhs); 
    ~MyList() { clear(); }
    int size() const { return Count; } 
    bool is_empty() const { return Count == 0; }

    // You will need to implement the following methods: 
    bool push_front(const T& item); 
    bool push_back(const T& item); 
      // add item to either front or back of list. 

    bool push_ordered(const T& item); 
    // The push_ordered method may assume that the list is already ordered if it is non-empty.

    T pop_front();  
      // returns first item from list, removing it. Throws MyListException if list is empty
    T pop_back();   
      // returns last item from list, removing it. Throws MyListException if list is empty. 
    bool is_present(const T& item); 
      // returns true if item is present anywhere in list, false otherwise. 
    T pop(const T& item); 
      // searches list for item, removes first occurrence of it that it finds.
      // If item is not in list, throw ListException
    void clear();
      // deletes all items from list. 

    void print(ostream& out) const; 
    // prints the items in the list, 1 item per line. 


private: 
    template<class T> 
    struct Node {
        T data; 
        Node<T>* Next, * Prev;
        Node(const T& item) { data = item; Next = Prev = nullptr; }
    };
    Node<T>* Head, * Tail; 
    int Count; 
};

template <class T> 
MyList<T>::MyList() {
    Head = Tail = nullptr; 
    Count = 0; 
}

template<class T>
MyList<T>::MyList(const MyList<T>& other) {
    Node<T>* P = other.Head;
    Head = Tail = nullptr; 
    Count = 0; 
    while (P != nullptr) {
        if (push_back(P->data)) {
            P = P->Next;
        }
    }
}

template <class T>
const MyList<T>& MyList<T>::operator= (const MyList<T>& rhs) {
    Node<T>* P; 
    if (this != &rhs) {
        clear();
        P = rhs.Head(); 
        while (P != nullptr) {
            push_back(P->data); // this will update everything as needed. 
            P = P->Next; 
        }
    }
    return *this; 
}

template <class T>
void MyList<T>::clear() {
 // TODO: Write this code. 
    while (Count > 0)
    {
        Node<T>* ptr = Head;
        Head = Head->Next;
        delete ptr;
        Count--;
    }
}

template <class T>
bool MyList<T>::push_front(const T& item) {
 // TODO: Write this code. 
    try
    {
        Node<T>* node = new Node<T>(item);
    }
    catch (MyListException e)
    {
        cout << e.what() << endl;
        return false;
    }
    Node<T>* node = new Node<T>(item);
    node->Next = Head;
    Head = node;
    
    return true;
}

template <class T>
bool MyList<T>::push_back(const T& item) {
 // TODO: Write this code. 
    Node<T>* node = new Node<T>(item);
    if (Head == nullptr)
    {
        Head = node;
        Tail = node;
        Count++;
    }
    else if (Count == 1)
    {
        Tail = node;
        Head->Next = Tail;
        Tail->Prev = Head;
        Count++;
    }
    else
    {
        Tail->Next = node;
        node->Prev = Tail;
        Tail = Tail->Next;
        Count++;
    }
    return true;
}

template <class T> 
bool MyList<T>::push_ordered(const T& item) {
    // TODO: Write this code. 
    Node<T>* node = new Node<T>(item);
    Node<T>* current_node = Head;
    while (current_node != nullptr)
    {
        if (current_node->data < node->data && current_node->Next->data >= node->data)
        {
            node->Next = current_node->Next;
            current_node->Next->Prev = node;
            current_node->Next = node;
            node->Prev = current_node;
            Count++;
        }
        current_node = current_node->Next;
    }
    return true;
}


template <class T>
T MyList<T>::pop_front() {
       // TODO: Write this code. 
    T data_return;
    data_return = Head->data;
    Node<T>* ptr = Head;
    Head = Head->Next;
    delete ptr;
    Count--;
    return data_return;
}

template <class T>
T MyList<T>::pop_back() {
    // TODO: Write this code. 
    T data_return;
    data_return = Tail->data;
    Node<T>* ptr = Tail;
    Tail = Tail->Prev;
    Tail->Next = nullptr;
    delete ptr;
    Count--;
    return data_return;
}

template <class T>
T MyList<T>::pop(const T& item) {
    // TODO: Write this code. 
    Node<T>* current_node = Head;
    Node<T>* ptr;
    while (current_node != nullptr)
    {
        if (current_node->data == item)
        {
            ptr = current_node;
            current_node = current_node->Prev;
            current_node->Next = current_node->Next->Next;
            current_node->Next->Prev = current_node;
            delete ptr;
            Count--;
        }
        current_node = current_node->Next;
    }
    return item;
}

template<class T> 
void MyList<T>::print(ostream& out) const {
    // TODO: Write this code. 
    Node<T>* current_node = Head;
    while (current_node != nullptr)
    {
        cout << current_node->data << endl;
        current_node = current_node->Next;
    }
}
#pragma once
#include <string> 
using namespace std; 

class MyListException {
public: 
    MyListException(const std::string& M = "List Exception") { Msg = M; }
    std::string what() const { return Msg; }
private: 
    std::string Msg; 
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
}

template <class T>
bool MyList<T>::push_front(const T& item) {
 // TODO: Write this code. 
}

template <class T>
bool MyList<T>::push_back(const T& item) {
 // TODO: Write this code. 
}

template <class T> 
bool push_ordered(const T& item) {
    // TODO: Write this code. 
}


template <class T>
T MyList<T>::pop_front() {
       // TODO: Write this code. 

}

template <class T>
T MyList<T>::pop_back() {
    // TODO: Write this code. 
    
}

template <class T>
T MyList<T>::pop(const T& item) {
    // TODO: Write this code. 

}

template<class T> 
void MyList<T>::print(ostream& out) const {
    // TODO: Write this code. 

}
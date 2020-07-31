#include "MyList.h"
#include <iostream> 
using namespace std; 


int main() {
    MyList<int> IntList;
    MyList<string> StringList; 
    int k; 
    
    for (int j = 0; j < 5; j++) {
        IntList.push_back(j);
    }
    cout << "Integer list contains " << IntList.size() << " items.\n"; 
    IntList.clear();
    if (IntList.size() == 0) {
        cout << "List is now empty.\n";
    }
    else {
        cout << "Error: List is not empty, but it should be.\n";
    }
    for (int j = 0; j < 5; j++) {
        IntList.push_back(j * 3);
    }
    cout << "Updated list. Current contents: \n";
    IntList.print(cout);
    IntList.push_ordered(11);
    cout << "\nContents after adding 11:\n";
    IntList.print(cout); 
    k = IntList.pop_front();
    cout << "Just removed " << k << ", list is now: \n";
    IntList.print(cout); 
    k = IntList.pop_back();
    cout << "Just removed " << k << ", list is now: \n";
    IntList.print(cout);
    k = IntList.pop(9);
    cout << "Just removed " << k << ", list is now: \n";
    IntList.print(cout);

    cout << "\nMoving to string list...\n";
    StringList.push_back("apple");
	StringList.push_back("banana"); 
	StringList.push_back("cherry"); 
	cout << "3 items in list, trying to pop non-existent item...\n";
	try { 
	    StringList.pop("coconut");
	}
	catch(MyListException e) { 
	    cout << "Got exception of expected type, message: " << e.what() << endl;
	}
	cout << "\n\nEnding program....\n"; 

    return 0; 
}
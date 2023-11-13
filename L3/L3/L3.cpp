#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable hashTable;

    try {
        hashTable.add(1, "Value 1");
        hashTable.add(2, "Value 2");
        hashTable.add(3, "Value 3");
        hashTable.add(4, "Value 4");
        hashTable.add(5, "Value 5");
        hashTable.add(6, "Value 6");
        hashTable.add(7, "Value 7");

        cout << "Table after adding:" << std::endl;
        hashTable.print();

        cout << "Value with key 3: " << hashTable.find(3) << std::endl;

        // hashTable.add(8, "Value 8");

        hashTable.remove(4);

        cout << "Table after removing key 4:" << std::endl;
        hashTable.print();

        hashTable.remove(9);

    }
    catch (const char* error_message) {
        cout << "Error: " << error_message << endl;
    }

    return 0;
}

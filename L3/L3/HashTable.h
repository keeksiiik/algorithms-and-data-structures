#include <iostream>

using namespace std;

class HashTable
{
private:
	static const int SIZE = 7;

	struct Node
	{
		int key;
		string value;
		bool deleted;
	};

	Node table[10];
	int count;

	int hash(int key, int i) {
		int hash2Value = hash2(key);
		return (hash2Value + i) % SIZE;
	}

	int hash2(int key) {
		return key % 3;
	}

public:
	HashTable() {
		for (int i = 0; i < SIZE; i++)
		{
			table[i].key = -1;
			table[i].deleted = false;
		}
		count = 0;
	}

	void add(int key, string value) {
		if (count == SIZE)
		{
			throw "Hash table is full";
		}
		int i = 0;
		int index = hash(key, i);

		while (table[index].key != -1 && table[index].key != key && !table[index].deleted)
		{
			i++;
			index = hash(key, i);

			if (i >= SIZE)
			{
				throw "Failed to insert element into hash table";
			}
		}

		if (table[index].key == -1 || table[index].deleted)
		{
			table[index].key = key;
			table[index].value = value;
			table[index].deleted = false;
			count++;
		}
	}

	string find(int key) {
		int i = 0;
		int index = hash(key, i);

		while (table[index].key != -1 && (table[index].key != key || table[index].deleted)) {
			i++;
			index = hash(key, i);
			if (i >= SIZE)
			{
				throw "Element not found in hash table";
			}
		}

		if (table[index].key == key)
			return table[index].value;
		else
			throw "Element not found in hash table";
	}

	void remove(int key) {
		int i = 0;
		int index = hash(key, i);

        while (table[index].key != -1 && (table[index].key != key || table[index].deleted)) {
            i++;
            index = hash(key, i);

			if (i >= SIZE)
			{
				throw "Element not found in hash table";
			}
        }

        if (table[index].key == key) {
            table[index].key = -1;
            table[index].deleted = true;
            count--;
        }
		else {
			throw "Element not found in hash table";
		}
	}

	void print() const {
		for (int i = 0; i < SIZE; i++) {
			if (table[i].key != -1 && !table[i].deleted) {
				std::cout << "Key: " << table[i].key << ", Value: " << table[i].value << std::endl;
			}
		}
	}
};


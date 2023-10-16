#include "Product.h"

class LinkedList
{
private:
	struct Node
	{
		Product* data;
		Node* next;
	};

	Node* head;
	int length;

public:
	LinkedList();

	void displayAllProducts();
	void addProduct(Product* product);
	void removeProduct(const string& productName);
	Product* findProduct(const string& productName);
	int getLength() const;
};


#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head(nullptr), length(0) {}


void LinkedList::displayAllProducts()
{
    Node* currentNode = head;
    while (currentNode != nullptr) {
        Product* product = currentNode->data;
        cout << product->getName() << " " << product->getQuantity() << " " << product->getCategory() << endl;

        currentNode = currentNode->next;
    }
}

void LinkedList::addProduct(Product* product)
{
    Node* newNode = new Node;
    newNode->data = product;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    length++;
}

void LinkedList::removeProduct(const string& productName)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data->getName() != productName) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return;
    }
    else if (current == head) {
        head = current->next;
    }
    else {
        previous->next = current->next;
    }

    delete current;
    length--;
}

Product* LinkedList::findProduct(const string& productName)
{
    Node* current = head;

    while (current != nullptr) {
        if (current->data->getName() == productName) {
            return current->data;
        }
        current = current->next;
    }

    return nullptr;
}

int LinkedList::getLength() const
{
    return length;;
}

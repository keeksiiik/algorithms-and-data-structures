#include "LinkedList.h"
#include "Product.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

LinkedList readFromFile(string fileName)
{
    LinkedList productList;

    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            istringstream iss(line);

            string name, category;
            int quantity;

            if (iss >> name >> quantity >> category) {
                Product* product = new Product(name, quantity, category);
                productList.addProduct(product);
            }
            else {
                cout << "Ошибка чтения строки: " << line << endl;
            }
        }

        file.close();
    }
    else {
        cout << "Не удалось открыть файл: " << fileName << endl;
    }

    return productList;
}

void getProductQuantity(LinkedList productList)
{
    cout << "Укажите название товара" << endl;
    string name;
    cin >> name;
    Product* foundProduct = productList.findProduct(name);
    if (foundProduct != nullptr) {
        cout << "Количество товара " << name << ": " << foundProduct->getQuantity() << endl;
    }
    else {
        cout << "Товар " << name << " не найден." << endl;
    }
}

void addProduct(LinkedList productList, string fileName)
{
    string name, category;
    int quantity;
    cout << "Введите название товара" << endl;
    cin >> name;
    cout << "Введите количество товара" << endl;
    cin >> quantity;
    cout << "Введите категорию товара" << endl;
    cin >> category;
    Product* product = new Product(name, quantity, category);
    productList.addProduct(product);
    ofstream file(fileName, ios_base::app);
    if (file.is_open()) {
        file << name << " " << quantity << " " << category;
        file.close();
    }
    else {
        cout << "Не удалось открыть файл: " << fileName << endl;
    }
}

void changeProduct(LinkedList productList)
{
    cout << "Введите название товара: ";
    string name;
    cin >> name;
    Product* product = productList.findProduct(name);
    if (product != nullptr) {
        cout << "1. Изменить название\n2. Изменить количество\n3. Изменить категорию";
        int point;
        cin >> point;
        switch (point)
        {
        case(1):
        {
            string newName;
            cout << "Введите новое количество товара: ";
            cin >> newName;
            product->setName(newName);
            cout << "Информация о товаре " << name << " успешно изменена." << endl;
        }
        case(2):
        {
            int newQuantity;
            cout << "Введите новое количество товара: ";
            cin >> newQuantity;
            product->setQuantity(newQuantity);
            cout << "Информация о товаре " << name << " успешно изменена." << endl;
        }
        case(3):
        {
            string newCategory;
            cout << "Введите новую категорию товара: ";
            cin >> newCategory;
            product->setCategory(newCategory);
            cout << "Информация о товаре " << name << " успешно изменена." << endl;
        }
        default:
            break;
        }
    }
    else {
        cout << "Товар " << name << " не найден." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    LinkedList productList = readFromFile("data.txt");

    while (true)
    {
        cout << "1. Получить список товаров на складе\n2. Добавить товар\n3. Проверить наличие товара\n4. Изменить информацию о товаре\n5. Удалить товар" << endl;
        int point;
        cin >> point;
        switch (point)
        {
        case(1):
            productList.displayAllProducts();
        case(2):
            addProduct(productList, "data.txt");
        case(3):
            getProductQuantity(productList);
        case(4):
            changeProduct(productList);
        case(5):
        {
            string name;
            cout << "Введите название товара, которое желаете удалить: ";
            cin >> name;
            productList.removeProduct(name);
            cout << "Товар был удален";
        }
        default:
            break;
        }
    }

    return 0;
}

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Product {
private:
    string name;
    int quantity;
    string category;

public:
    Product(const string& name, int quantity, const string& category);

    string getName() const;
    void setName(const string& name);

    int getQuantity() const;
    void setQuantity(int quantity);

    string getCategory() const;
    void setCategory(const string& category);
};

#endif // PRODUCT_H
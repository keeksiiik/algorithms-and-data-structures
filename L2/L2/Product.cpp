#include "Product.h"

Product::Product(const string& name, int quantity, const string& category)
	: name(name), quantity(quantity), category(category) {}

string Product::getName() const
{
	return name;
}

void Product::setName(const string& name)
{
	this->name = name;
}

int Product::getQuantity() const
{
	return quantity;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}

string Product::getCategory() const
{
	return category;
}

void Product::setCategory(const string& category)
{
	this->category = category;
}

#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productId;
    string productName;
    double price;
    int quantity;

public:
    Product() {
        productId = 0;
        productName = "";
        price = 0;
        quantity = 0;
    }

    Product(int id, string name, double p, int q) {
        productId = id;
        productName = name;
        price = p;
        quantity = q;
    }

    virtual double calculateDiscount() const {
        return 0;
    }

    double getCost() const {
        return price * quantity;
    }

    virtual void display() const {
        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Cost: " << getCost() << endl;
    }

    virtual ~Product() {}
};

class DiscountProduct : public Product {
public:
    DiscountProduct(int id, string name, double p, int q)
        : Product(id, name, p, q) {}

    double calculateDiscount() const override {
        double total = getCost();

        if (total >= 5000)
            return total * 0.10;
        else if (total >= 3000)
            return total * 0.05;
        else
            return 0;
    }

    void display() const override {
        double total = getCost();
        double discount = calculateDiscount();

        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Cost: " << total << endl;
        cout << "Discount: " << discount << endl;
        cout << "Final Amount: " << total - discount << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product **products = new Product*[n];

    for (int i = 0; i < n; i++) {
        int id, quantity;
        string name;
        double price;

        cout << "\nEnter details of Product " << i + 1 << ":\n";
        cout << "Product ID: ";
        cin >> id;
        cout << "Product Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;

        products[i] = new DiscountProduct(id, name, price, quantity);
    }

    cout << "\n===== DETAILED INVOICE =====\n";
    double grandTotal = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        products[i]->display();
        grandTotal += products[i]->getCost() - products[i]->calculateDiscount();
    }

    cout << "\nGrand Total: " << grandTotal << endl;

    for (int i = 0; i < n; i++) {
        delete products[i];
    }
    delete[] products;

    return 0;
}

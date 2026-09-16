#include <iostream>
#include <cstring>
using namespace std;

class Publication {
protected:
    char *title;
    char *author;
    float price;
    char *publisher;

public:
    Publication() {
        title = new char[1]; title[0] = '\0';
        author = new char[1]; author[0] = '\0';
        publisher = new char[1]; publisher[0] = '\0';
        price = 0;
    }

    Publication(const char *t, const char *a, float p, const char *pub) {
        title = new char[strlen(t) + 1]; strcpy(title, t);
        author = new char[strlen(a) + 1]; strcpy(author, a);
        publisher = new char[strlen(pub) + 1]; strcpy(publisher, pub);
        price = p;
    }

    Publication(const Publication &p) {
        title = new char[strlen(p.title) + 1]; strcpy(title, p.title);
        author = new char[strlen(p.author) + 1]; strcpy(author, p.author);
        publisher = new char[strlen(p.publisher) + 1]; strcpy(publisher, p.publisher);
        price = p.price;
    }

    virtual ~Publication() {
        delete[] title;
        delete[] author;
        delete[] publisher;
    }
};

class Books : public Publication {
private:
    int stock;

public:
    Books() : Publication() {
        stock = 0;
    }

    Books(const char *t, const char *a, float p, const char *pub, int s)
        : Publication(t, a, p, pub) {
        stock = s;
    }

    Books(const Books &b) : Publication(b) {
        stock = b.stock;
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << endl;
    }

    bool searchBook(const char *key) const {
        return strcmp(title, key) == 0 || strcmp(author, key) == 0;
    }

    void purchaseBook(int copies) {
        if (copies <= stock) {
            cout << "Total Cost: " << copies * price << endl;
            stock -= copies;
            cout << "Purchase successful." << endl;
            cout << "Remaining Stock: " << stock << endl;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;
    cin.ignore();

    Books *books = new Books[n];

    for (int i = 0; i < n; i++) {
        char title[100], author[100], publisher[100];
        float price;
        int stock;

        cout << "\nEnter details for Book " << i + 1 << ":\n";
        cout << "Title: "; cin.getline(title, 100);
        cout << "Author: "; cin.getline(author, 100);
        cout << "Price: "; cin >> price;
        cin.ignore();
        cout << "Publisher: "; cin.getline(publisher, 100);
        cout << "Stock: "; cin >> stock;
        cin.ignore();

        books[i] = Books(title, author, price, publisher, stock);
    }

    char key[100];
    cout << "\nEnter title or author to search: ";
    cin.getline(key, 100);

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (books[i].searchBook(key)) {
            cout << "\nBook Found:\n";
            books[i].display();
            found = true;

            int copies;
            cout << "Enter number of copies to purchase: ";
            cin >> copies;
            books[i].purchaseBook(copies);
            break;
        }
    }

    if (!found)
        cout << "Book not found." << endl;

    delete[] books;
    return 0;
}

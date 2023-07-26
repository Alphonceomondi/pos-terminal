#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Define a struct to represent a product
struct Product {
    string name;
    double price;
    int stock;

    Product(const string& _name, double _price, int _stock) : name(_name), price(_price), stock(_stock) {}
};

// Function to display the menu
void displayMenu(const vector<Product>& menu) {
    cout << "-----------------------------" << endl;
    cout << "          MENU               " << endl;
    cout << "-----------------------------" << endl;

    for (size_t i = 0; i < menu.size(); ++i) {
        cout << menu[i].name << " - KSH " << menu[i].price << " (" << menu[i].stock << " in stock)" << endl;
    }

    cout << "-----------------------------" << endl;
}

// Function to update stock
void updateStock(vector<Product>& menu) {
    string itemName;
    int quantity;

    cout << "Enter the name of the item: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, itemName);

    cout << "Enter the quantity: ";
    while (!(cin >> quantity) || quantity <= 0) {
        cout << "Invalid quantity. Please enter a positive integer value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Find the product in the menu
    bool found = false;

    for (size_t i = 0; i < menu.size(); ++i) {
        if (menu[i].name == itemName) {
            found = true;
            menu[i].stock += quantity;
            break;
        }
    }

    if (found) {
        cout << "Stock updated successfully." << endl;
    } else {
        cout << "Item not found in the menu." << endl;
    }
}

// Function to process the order
void processOrder(vector<Product>& menu) {
    string itemName;
    int quantity;

    cout << "Enter the name of the item: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, itemName);

    cout << "Enter the quantity: ";
    while (!(cin >> quantity) || quantity <= 0) {
        cout << "Invalid quantity. Please enter a positive integer value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Find the product in the menu
    bool found = false;
    double totalAmount = 0.0;

    for (size_t i = 0; i < menu.size(); ++i) {
        if (menu[i].name == itemName) {
            found = true;

            if (menu[i].stock >= quantity) {
                totalAmount = menu[i].price * quantity;
                menu[i].stock -= quantity;
            } else {
                cout << "Insufficient stock for the selected quantity." << endl;
                return;
            }

            break;
        }
    }

    if (found) {
        cout << "-----------------------------" << endl;
        cout << "         RECEIPT             " << endl;
        cout << "-----------------------------" << endl;
        cout << "Aticas Cafe" << endl;
        cout << "-----------------------------" << endl;
        cout << "Item: " << itemName << endl;
        cout << "-----------------------------" << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "-----------------------------" << endl;
        cout << "Total Amount: KSH " << totalAmount << endl;
        cout << "-----------------------------" << endl;
        cout << "YOU WERE SERVED BY SIR ALEMBA " << endl;
        cout << "-----------------------------" << endl;
        cout << "For inquiries, contact: 0786181670" << endl; // Aticas Cafe manager's mobile number
        cout << "-----------------------------" << endl;
        cout << "Your Hospitality Partner" << endl;
        cout << "-----------------------------" << endl;
        cout << "-----------------------------" << endl;
        cout << "-----------------------------" << endl;
    } else {
        cout << "Item not found in the menu." << endl;
    }
}

// Function to delete an item from the menu
void deleteItem(vector<Product>& menu) {
    string itemName;

    cout << "Enter the name of the item to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, itemName);

    // Find the product in the menu
    bool found = false;

    for (vector<Product>::iterator it = menu.begin(); it != menu.end(); ++it) {
        if (it->name == itemName) {
            menu.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Item deleted successfully." << endl;
    } else {
        cout << "Item not found in the menu." << endl;
    }
}

// Function to add a new item to the menu
void addItem(vector<Product>& menu) {
    string itemName;
    double price;
    int stock;

    cout << "Enter the name of the new item: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, itemName);

    cout << "Enter the price of the new item: ";
    while (!(cin >> price) || price <= 0) {
        cout << "Invalid price. Please enter a positive value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the stock quantity of the new item: ";
    while (!(cin >> stock) || stock < 0) {
        cout << "Invalid stock quantity. Please enter a non-negative integer value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    menu.push_back(Product(itemName, price, stock));
    cout << "Item added successfully." << endl;
}

int main() {
    // Create a vector to hold the menu items
    vector<Product> menu;

    // Add items to the menu
    menu.push_back(Product("Coffee", 50.00, 10));
    menu.push_back(Product("beef plain", 150.00, 15));
    menu.push_back(Product("beef minji", 100.00, 8));
    menu.push_back(Product("chips", 100.00, 12));
    menu.push_back(Product("chapo ndengu", 100.00, 12));
    menu.push_back(Product("chapo beans", 100.00, 12));
    menu.push_back(Product("chapo beef minji", 150.00, 12));
    menu.push_back(Product("chapo beef plain", 200.00, 12));
    menu.push_back(Product("ugali greens", 100.00, 12));
    menu.push_back(Product("greens", 50.00, 12));
    menu.push_back(Product("chapo", 25.00, 12));
    menu.push_back(Product("kebab", 60.00, 12));
    menu.push_back(Product("uji power", 60.00, 12));
    menu.push_back(Product("samosa", 40.00, 12));

    // Display the menu
    displayMenu(menu);

    char choice;
    do {
        int option;
        cout << "Select an option:" << endl;
        cout << "1. Place Order" << endl;
        cout << "2. Update Stock" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Add Item" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        while (!(cin >> option) || option < 1 || option > 5) {
            cout << "Invalid option. Please enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (option) {
            case 1:
                processOrder(menu);
                break;
            case 2:
                updateStock(menu);
                break;
            case 3:
                deleteItem(menu);
                break;
            case 4:
                addItem(menu);
                break;
            case 5:
                break;
        }
        cout << "Do you want to continue? (Y/N): ";
        cin >> choice;
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
            cout << "Invalid choice. Please enter Y or N: ";
            cin >> choice;
        }
        cout << endl;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

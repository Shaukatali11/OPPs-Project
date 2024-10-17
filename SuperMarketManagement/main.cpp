#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;
    int quantity;

public:
    // Constructor
    Product() : id(0), name(""), price(0.0), quantity(0) {}

    // Getter methods
    int getId() const { return id; }
    string getName() const { return name; }
    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Setter methods
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setPrice(float price) { this->price = price; }
    void setQuantity(int quantity) { this->quantity = quantity; }

    // Input method for adding new product
    void inputProduct() {
        cout << "Enter product ID: ";
        cin >> id;
        cout << "Enter product name: ";
        cin.ignore();  // To avoid issues with getline
        getline(cin, name);
        cout << "Enter product price: ";
        cin >> price;
        cout << "Enter product quantity: ";
        cin >> quantity;
    }

    // Display product details
    void displayProduct() const {
        cout << "Product ID: " << id << "\n";
        cout << "Product Name: " << name << "\n";
        cout << "Price: " << price << "\n";
        cout << "Quantity: " << quantity << "\n";
    }
};




class Supermarket {
private:
    vector<Product> products;  // Store all products

public:
    // Function to add a new product
    void addProduct() {
        Product newProduct;
        newProduct.inputProduct();
        products.push_back(newProduct);
        cout << "Product added successfully.\n";
    }

    // Function to display all products
    void displayProducts() {
        if (products.empty()) {
            cout << "No products available.\n";
            return;
        }
        cout << "--- Product List ---\n";
        for (const auto &product : products) {
            product.displayProduct();
            cout << "--------------------\n";
        }
    }

    // Function to modify a product by ID
    void modifyProduct(int id) {
        for (auto &product : products) {
            if (product.getId() == id) {
                cout << "Enter new details for the product:\n";
                product.inputProduct();
                cout << "Product updated successfully.\n";
                return;
            }
        }
        cout << "Product not found.\n";
    }

    // Function to delete a product by ID
    void deleteProduct(int id) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getId() == id) {
                products.erase(it);
                cout << "Product deleted successfully.\n";
                return;
            }
        }
        cout << "Product not found.\n";
    }

    // Function to handle customer orders
    void handleCustomer() {
        vector<Product> cart;
        int id, quantity;
        char choice;

        do {
            cout << "Enter product ID to add to cart: ";
            cin >> id;
            bool productFound = false;

            for (auto &product : products) {
                if (product.getId() == id) {
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    if (quantity <= product.getQuantity()) {
                        product.setQuantity(product.getQuantity() - quantity);  // Update stock
                        Product cartProduct = product;  // Add to cart
                        cartProduct.setQuantity(quantity);  // Update cart quantity
                        cart.push_back(cartProduct);
                        cout << "Added to cart.\n";
                    } else {
                        cout << "Not enough stock available.\n";
                    }
                    productFound = true;
                    break;
                }
            }
            if (!productFound) {
                cout << "Product not found.\n";
            }

            cout << "Do you want to add more items? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        // Generate bill
        generateBill(cart);
    }

    // Function to generate bill
    void generateBill(const vector<Product> &cart) {
        float total = 0;
        cout << "\n--- Bill ---\n";
        for (const auto &product : cart) {
            float cost = product.getPrice() * product.getQuantity();
            cout << product.getName() << " - " << product.getQuantity() << " @ " << product.getPrice()
                 << " each = " << cost << "\n";
            total += cost;
        }
        cout << "Total Amount: " << total << "\n";
        cout << "Thank you for shopping!\n";
    }
};



int main() {
    Supermarket market;
    int choice;
    while (true) {
        cout << "\n--- Supermarket Management System ---\n";
        cout << "1. Admin Mode\n";
        cout << "2. Customer Mode\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int adminChoice;
                cout << "\n--- Admin Mode ---\n";
                cout << "1. Add Product\n";
                cout << "2. Modify Product\n";
                cout << "3. Delete Product\n";
                cout << "4. Display Products\n";
                cout << "Enter your choice: ";
                cin >> adminChoice;

                switch (adminChoice) {
                    case 1:
                        market.addProduct();
                        break;
                    case 2: {
                        int id;
                        cout << "Enter product ID to modify: ";
                        cin >> id;
                        market.modifyProduct(id);
                        break;
                    }
                    case 3: {
                        int id;
                        cout << "Enter product ID to delete: ";
                        cin >> id;
                        market.deleteProduct(id);
                        break;
                    }
                    case 4:
                        market.displayProducts();
                        break;
                    default:
                        cout << "Invalid option.\n";
                }
                break;
            }

            case 2:
                cout << "\n--- Customer Mode ---\n";
                market.displayProducts();
                market.handleCustomer();
                break;

            case 3:
                cout << "Exiting system...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

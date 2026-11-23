// An online shopping platform requires a system to efficiently manage product
// records. The system should allow administrators to add new products, search
// products by ID, update product details, and display all product records.
// Since the number of products changes frequently, the records should be
// maintained using a linked list to support dynamic insertion and deletion.
// Each product should be assigned a unique Product ID and the system should
// provide functionality to search for a product by its ID using a hash table.
// If multiple Product IDs map to the same hash value, the system should handle
// collisions using chaining with linked lists.
#include <iostream>
#include <string>
#include <limits>
using namespace std;
class Product
{
    public:
    int id;
    string name;
    float price;
    int quantity;
    Product* next;
    Product* hashNext;
};
Product* head = NULL;
const int TABLE_SIZE = 10;
Product* hashTable[TABLE_SIZE] = { NULL };
int hashFunction(int id)
{
    return id % TABLE_SIZE;
}
void addProduct()
{
    Product* newProduct = new Product();
    cout << "Enter Product ID: ";
    cin >> newProduct->id;
    // Check for duplicate ID
    int index = hashFunction(newProduct->id);
    Product* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == newProduct->id)
        {
            cout << "Product ID already exists. Addition failed." << endl;
            delete newProduct;
            return;
        }
        temp = temp->hashNext;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter product name: ";
    getline(cin, newProduct->name);
    cout << "Enter product price: ";
    cin >> newProduct->price;
    cout << "Enter product quantity: ";
    cin >> newProduct->quantity;
    newProduct->next = head;
    head = newProduct;
    newProduct->hashNext = hashTable[index];
    hashTable[index] = newProduct;
    cout << "Product added successfully." << endl;
}
void searchProduct()
{
    int id;
    cout << "Enter Product ID to search: ";
    cin >> id;
    int index = hashFunction(id);
    Product* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Product found:" << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Quantity: " << temp->quantity << endl;
            return;
        }
        temp = temp->hashNext;
    }
    cout << "Product with ID " << id << " not found." << endl;
}
void updateProduct()
{
    int id;
    cout << "Enter Product ID to update: ";
    cin >> id;
    int index = hashFunction(id);
    Product* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter new product name: ";
            getline(cin, temp->name);
            cout << "Enter new product price: ";
            cin >> temp->price;
            cout << "Enter new product quantity: ";
            cin >> temp->quantity;
            cout << "Product updated successfully." << endl;
            return;
        }
        temp = temp->hashNext;
    }
    cout << "Product with ID " << id << " not found." << endl;
}
void displayProduct()
{
    Product* temp = head;
    if (temp == NULL)
    {
        cout << "No product records available." << endl;
        return;
    }
    cout << "All Product Records:" << endl;
    while (temp != NULL)
    {
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "-------------------" << endl;
        temp = temp->next;
    }
}
void deleteProduct()
{
    int id;
    cout << "Enter Product ID to delete: ";
    cin >> id;
    int index = hashFunction(id);
    Product* temp = hashTable[index];
    Product* prev = NULL;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (prev == NULL)
                hashTable[index] = temp->hashNext;
            else
                prev->hashNext = temp->hashNext;
            break;
        }
        prev = temp;
        temp = temp->hashNext;
    }
    if (temp == NULL)
    {
        cout << "Product with ID " << id << " not found." << endl;
        return;
    }
    Product* current = head;
    Product* previous = NULL;
    while (current != NULL)
    {
        if (current->id == id)
        {
            if (previous == NULL)
                head = current->next;
            else
                previous->next = current->next;
            delete current;
            cout << "Product deleted successfully." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "\nProduct Inventory Management System" << endl;
        cout << "1. Add New Product" << endl;
        cout << "2. Search Product by ID" << endl;
        cout << "3. Display All Product Records" << endl;
        cout << "4. Update Product Details" << endl;
        cout << "5. Delete Product" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                displayProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}

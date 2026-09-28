//Write a C++ Program using recursion to display a restauraant menu and allow the user to select an option
//until the user chooses exit.
#include <iostream>
using namespace std;
void Menu()
{
    int choice;
    cout << "Restaurant Menu:" << endl;
    cout << "1. Pizza" << endl;
    cout << "2. Eggs" << endl;
    cout << "3. Pasta" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin>>choice;
    if (choice == 1)
    {
        cout << "You selected Pizza." << endl;
        Menu();
    }
    else if (choice == 2)
    {
        cout << "You selected Eggs." << endl;
        Menu();
    }
    else if (choice == 3)
    {
        cout << "You selected Pasta." << endl;
        Menu();
    }
    else if (choice == 4)
    {
        cout << "Exiting the menu." << endl;
        return;
    }
    else
    {
        cout << "Invalid choice. Please try again." << endl;
        Menu();
    }


}
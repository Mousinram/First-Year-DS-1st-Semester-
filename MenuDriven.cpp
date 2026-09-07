//write a menu driven C++ program for a simple library system that allows the user to add book IDs
//Display all book IDS,search for book ID and exit the program
#include <iostream>
using namespace std;
int main()
{
    int bookID[10];
    int i = 0;
    int choice;
    int searchID;
    do 
    {
        cout<<"1. Add Book ID\n2. Display All Book IDs\n3. Search for Book ID\n4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        if (choice == 1)
        {
            cout<<"Enter Book ID to add:";
            cin>>bookID[i];
            i++;
            cout<<"Book ID added successfully!"<<endl;
        }
        else if (choice == 2)
        {
            cout<<"All Book IDS"<<endl;
            for (int a = 0; a < i; a++)
            {
                cout<<bookID[a]<<endl;
            }
        }
        else if (choice == 3)
        {
            cout<<"Enter Book ID to search: ";
            cin>>searchID;
            bool found = false;
            for (int a = 0; a < i; a++)
            {
                if (bookID[a] == searchID)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                cout<<"BOOK Found"<<endl;
            }
            else
            {
                cout<<"BOOK NOT FOUND"<<endl;
            }
        }
        else if (choice == 4)
        {
            cout<<"Exiting the program."<<endl;
        }
        else
        {
            cout<<"Invalid choice. Please try again."<<endl;
        }
    } while (choice != 4);
    return 0;
}

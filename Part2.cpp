//Write a C++ code to store 5 library books in an array and search for a given book ID.
//Display ""BOOK Found" if the ID is present or display "BOOK NOT FOUND" if missing.
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int book[5];
    int SearchID;
    cout << "Enter 5 Book IDs: " << endl;
    for (int i=0; i<5; i++)
    {
        cin >> book[i];
    }
    cout << "Enter Book ID to search: ";
    cin >> SearchID;
    for (int i=0; i<5; i++)
    {
        if (book[i] == SearchID)
        {
            cout << "BOOK Found" << endl;
            return 0;
        }
    }
    cout << "BOOK NOT FOUND" << endl;
        
}
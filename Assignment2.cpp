//Write a C++ Program to store roll numbers of 5 students and display all the roll numbers entered
//by the user 
#include <iostream>
using namespace std;
int main()
{
    int rollNumbers[5]; 

    cout << "Enter roll numbers of 5 students:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Roll number " << (i + 1) << ": ";
        cin >> rollNumbers[i];
    }

    cout << "\nThe roll numbers entered are:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Roll number " << (i + 1) << ": " << rollNumbers[i] << endl;
    }

    return 0;
}
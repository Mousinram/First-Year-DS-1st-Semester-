// A university requires a system to efficiently manage student records.
// The system should allow administrators to register new students, update
// student information, enroll students in courses, withdraw students from
// courses, and remove student records when required. Since the number of
// students changes frequently, the records should be maintained using a
// linked list to support dynamic insertion and deletion. Each student should
// be assigned a unique Roll Number and the system should provide functionality
// to search for a student by their Roll Number using a hash table.
// If multiple Roll Numbers map to the same hash value, the system should
// handle collisions using chaining with linked lists.

#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Student
{
    public:
    int rollNo;
    string name;
    int age;
    string course;
    Student* next;
    Student* hashNext;
};

Student* head = NULL;

const int TABLE_SIZE = 10;
Student* hashTable[TABLE_SIZE] = { NULL };

int hashFunction(int rollNo)
{
    return rollNo % TABLE_SIZE;
}

void registerStudent()
{
    Student* newStudent = new Student();

    cout << "Enter Roll Number: ";
    cin >> newStudent->rollNo;

    // Check for duplicate Roll Number
    int index = hashFunction(newStudent->rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == newStudent->rollNo)
        {
            cout << "Roll Number already exists. Registration failed." << endl;
            delete newStudent;
            return;
        }
        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter student name: ";
    getline(cin, newStudent->name);

    cout << "Enter student age: ";
    cin >> newStudent->age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter student course: ";
    getline(cin, newStudent->course);

    // Add student to the linked list
    newStudent->next = head;
    head = newStudent;

    // Add student to the hash table
    newStudent->hashNext = hashTable[index];
    hashTable[index] = newStudent;

    cout << "Student registered successfully." << endl;
}

void searchStudent()
{
    int rollNo;

    cout << "Enter Roll Number to search: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cout << "Student found:" << endl;
            cout << "Roll Number: " << temp->rollNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Course: " << temp->course << endl;
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student with Roll Number " << rollNo << " not found." << endl;
}

void updateStudent()
{
    int rollNo;

    cout << "Enter Roll Number to update: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new student name: ";
            getline(cin, temp->name);

            cout << "Enter new student age: ";
            cin >> temp->age;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new student course: ";
            getline(cin, temp->course);

            cout << "Student information updated successfully." << endl;
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student with Roll Number " << rollNo << " not found." << endl;
}

void enrollCourse()
{
    int rollNo;

    cout << "Enter Roll Number to enroll: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter course to enroll: ";
            getline(cin, temp->course);

            cout << "Student enrolled successfully." << endl;
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student with Roll Number " << rollNo << " not found." << endl;
}

void withdrawCourse()
{
    int rollNo;

    cout << "Enter Roll Number to withdraw: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            temp->course = "Not Enrolled";
            cout << "Student withdrawn from course successfully." << endl;
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student with Roll Number " << rollNo << " not found." << endl;
}

void deleteStudent()
{
    int rollNo;

    cout << "Enter Roll Number to delete: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);

    // Delete student from hash table
    Student* temp = hashTable[index];
    Student* prev = NULL;

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
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
        cout << "Student with Roll Number " << rollNo << " not found." << endl;
        return;
    }

    // Delete student from linked list
    Student* current = head;
    Student* previous = NULL;

    while (current != NULL)
    {
        if (current->rollNo == rollNo)
        {
            if (previous == NULL)
                head = current->next;
            else
                previous->next = current->next;

            delete current;

            cout << "Student record deleted successfully." << endl;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void displayStudent()
{
    Student* temp = head;

    if (temp == NULL)
    {
        cout << "No student records available." << endl;
        return;
    }

    cout << "All Student Records:" << endl;

    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNo << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Course: " << temp->course << endl;
        cout << "-------------------" << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\nUniversity Student Management System" << endl;
        cout << "1. Register New Student" << endl;
        cout << "2. Search Student by Roll Number" << endl;
        cout << "3. Display All Student Records" << endl;
        cout << "4. Update Student Information" << endl;
        cout << "5. Enroll Student in Course" << endl;
        cout << "6. Withdraw Student from Course" << endl;
        cout << "7. Remove Student Record" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                displayStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                enrollCourse();
                break;

            case 6:
                withdrawCourse();
                break;

            case 7:
                deleteStudent();
                break;

            case 8:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
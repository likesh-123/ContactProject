#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// global variables
string fname, lname, phone_number;

void addContact();
void searchContact();
void help();
void self_exit();
bool chech_digits(string x);
bool check_numbers(string x);

int main()
{
    short int choice;
    // To clear the screen
    system("cls");

    // To change the color
    // system("color 0A");

    cout << "\n\n\n\t\t\tContact Management";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        addContact();
        break;
    case 2:
        searchContact();
        break;
    case 3:
        help();
        break;
    case 4:
        self_exit();
        break;
    default:
        cout << "\n\n\tInvalid Input!";
        cout << "\n\tPress any key to continue...";
        getch();
        main();
        break;
    }

    return 0;
}

void self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank You For Using !!!";
    exit(1);
}

void help()
{
    cout << "This display help";
    getch();
    main();
}

void addContact()
{
    ofstream phone("number.txt", ios::app);

    system("cls");
    cout << "\n\n\tEnter First name : ";
    cin >> fname;
    cout << "\n\n\tEnter Last name : ";
    cin >> lname;
    cout << "\n\n\tEnter 10-Digit Phone Number : ";
    cin >> phone_number;

    if (chech_digits(phone_number))
    {
        if (check_numbers(phone_number))
        {
            if (phone.is_open())
            {
                phone << fname << " " << lname << " " << phone_number << endl;
                cout << "\n\tContact Saved Successfully !!!";
            }
            else
                cout << "\n\tError Opening File !!!";
        }
        else
            cout << "\n\tA Phone Number Must Contain Numbers Only.";
    }
    else
        cout << "\n\tA Phone Number Must Contain 10 Digits.";

    phone.close();
    getch();
    main();
}
void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string key;
    cout << "\n\tEnter Name To Search : ";
    cin >> key;
    while (myfile >> fname >> lname >> phone_number)
    {
        if (key == fname || key == lname)
        {
            system("cls");
            cout << "\n\n\n\t\tContact details : ";
            cout << "\n\n\tFirst Name : " << fname;
            cout << "\n\n\tLast Name : " << lname;
            cout << "\n\n\tPhone Number : " << phone_number;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\n\tNo such Contact Found !!!";
    getch();
    main();
}

bool chech_digits(string x)
{
    if (x.length() == 10)
        return true;
    return false;
}

bool check_numbers(string x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (!(x[i] >= 49 && x[i] <= 57))
            return false;
    }
    return true;
}
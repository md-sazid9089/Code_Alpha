#include<bits/stdc++.h>
using namespace std;

void Green()         { cout << "\033[1;32m"; }
void Red()           { cout << "\033[1;31m"; }
void Cyan()          { cout << "\033[1;36m"; }
void Yellow()        { cout << "\033[1;33m"; }
void ResetTextColor(){ cout << "\033[0m";    }
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class Authentication {
private:
    string userName, password, fullName, emailId;

public:
    void login() {
        clearScreen();
        string uName, pass;
        cout << "\n";
        Cyan();
        cout << "=========== LOGIN ===========" << endl;
        ResetTextColor();

        cout << "Enter Username : ";
        cin.ignore();
        getline(cin, uName);

        cout << "Enter Password : ";
        getline(cin, pass);

        ifstream fin(uName + ".txt");

        if (fin.is_open()) {
            getline(fin, fullName);
            getline(fin, emailId);
            getline(fin, userName);
            getline(fin, password);
            fin.close();

            if (password == pass) {
                Green();
                cout << "\n Login Successful! Welcome, " << fullName << "!\n";
                ResetTextColor();
            } else {
                Red();
                cout << "\n Invalid Password!\n";
                ResetTextColor();
            }
        } else {
            Red();
            cout << "\n Username not found!\n";
            ResetTextColor();
        }
    }

    void registration() {
        clearScreen();
        cout << "\n";
        Cyan();
        cout << "======= REGISTRATION ========" << endl;
        ResetTextColor();

        cin.ignore();
        cout << "Enter Full Name  : ";
        getline(cin, fullName);
        cout << "Enter Email ID   : ";
        getline(cin, emailId);
        cout << "Choose Username  : ";
        getline(cin, userName);
        cout << "Choose Password  : ";
        getline(cin, password);

        ofstream fout(userName + ".txt");

        if (fout.is_open()) {
            fout << fullName << "\n" << emailId << "\n" << userName << "\n" << password << "\n";
            fout.close();

            clearScreen();
            Green();
            cout << "Registration Complete!\n";
            ResetTextColor();

            cout << "Your username: ";
            Yellow(); cout << userName << endl; ResetTextColor();

            cout << "Your password: ";
            Yellow(); cout << password << endl; ResetTextColor();
        } else {
            Red();
            cout << "\n Registration Failed!\n";
            ResetTextColor();
        }
    }
};

int main() {
    Authentication a1;
    int choice;

    while (true) {
        clearScreen();
        Cyan();
        cout << "==============================" << endl;
        cout << "   LOGIN & REGISTRATION MENU  " << endl;
        cout << "==============================" << endl;
        ResetTextColor();

        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: a1.login(); break;
            case 2: a1.registration(); break;
            case 3: clearScreen(); Green(); cout << "Exiting... Goodbye!\n"; ResetTextColor(); return 0;
            default:
                Red(); cout << "\nInvalid option! Try again.\n"; ResetTextColor();
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
}

#include<bits/stdc++.h>
using namespace std;
struct Transaction {
    string type;
    float amount;
    float balanceAfter;
};
class Account {
private:
    int accountNumber;
    float balance;
    vector<Transaction> history;

public:
    Account(int accNo) : accountNumber(accNo), balance(0.0) {}

    int getAccountNumber() const { return accountNumber; }

    float getBalance() const { return balance; }

    void deposit(float amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        history.push_back({"Deposit", amount, balance});
        cout << "Deposited ₹" << amount << ". New Balance: ₹" << balance << "\n";
    }

    void withdraw(float amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid or insufficient funds.\n";
            return;
        }
        balance -= amount;
        history.push_back({"Withdrawal", amount, balance});
        cout << "Withdrawn ₹" << amount << ". New Balance: ₹" << balance << "\n";
    }

    bool transfer(Account &receiver, float amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Transfer failed. Check amount or balance.\n";
            return false;
        }
        balance -= amount;
        receiver.balance += amount;
        history.push_back({"Transfer Out", amount, balance});
        receiver.history.push_back({"Transfer In", amount, receiver.balance});
        cout << "Transferred ₹" << amount << " to Account " << receiver.getAccountNumber() << "\n";
        return true;
    }

    void printTransactions() const {
        cout << "\nTransaction History for Account " << accountNumber << ":\n";
        cout << left << setw(15) << "Type" << setw(15) << "Amount" << setw(15) << "Balance After" << "\n";
        cout << "---------------------------------------------\n";
        for (const auto& t : history) {
            cout << setw(15) << t.type << setw(15) << t.amount << setw(15) << t.balanceAfter << "\n";
        }
        if (history.empty()) {
            cout << "No transactions found.\n";
        }
    }
};

class Customer {
private:
    string name;
    int customerId;
    Account account;

public:
    Customer(string n, int id) : name(n), customerId(id), account(id * 1001) {}

    int getId() const { return customerId; }

    void showDetails() const {
        cout << "\n Customer ID: " << customerId << "\n";
        cout << "Name        : " << name << "\n";
        cout << "Account No. : " << account.getAccountNumber() << "\n";
        cout << "Balance     : ₹" << fixed << setprecision(2) << account.getBalance() << "\n";
    }

    Account& getAccount() { return account; }
};

class BankingSystem {
private:
    vector<Customer> customers;

    Customer* findCustomer(int id) {
        for (auto &c : customers) {
            if (c.getId() == id)
                return &c;
        }
        return nullptr;
    }

public:
    void createCustomer() {
        string name;
        int id;
        cout << "\nEnter Customer ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        if (findCustomer(id)) {
            cout << "Customer ID already exists.\n";
            return;
        }

        customers.emplace_back(name, id);
        cout << "Customer created successfully!\n";
    }

    void showCustomerDetails() {
        int id;
        cout << "\nEnter Customer ID: ";
        cin >> id;
        Customer* c = findCustomer(id);
        if (c)
            c->showDetails();
        else
            cout << "Customer not found.\n";
    }

    void depositToAccount() {
        int id;
        float amount;
        cout << "\nEnter Customer ID: ";
        cin >> id;
        Customer* c = findCustomer(id);
        if (!c) {
            cout << "Customer not found.\n";
            return;
        }
        cout << "Enter deposit amount: ₹";
        cin >> amount;
        c->getAccount().deposit(amount);
    }

    void withdrawFromAccount() {
        int id;
        float amount;
        cout << "\nEnter Customer ID: ";
        cin >> id;
        Customer* c = findCustomer(id);
        if (!c) {
            cout << "Customer not found.\n";
            return;
        }
        cout << "Enter withdrawal amount: ₹";
        cin >> amount;
        c->getAccount().withdraw(amount);
    }

    void transferBetweenAccounts() {
        int fromId, toId;
        float amount;
        cout << "\n Sender Customer ID: ";
        cin >> fromId;
        cout << "Receiver Customer ID: ";
        cin >> toId;
        cout << "Transfer Amount: ₹";
        cin >> amount;

        Customer* sender = findCustomer(fromId);
        Customer* receiver = findCustomer(toId);

        if (!sender || !receiver) {
            cout << "One or both customer IDs not found.\n";
            return;
        }

        sender->getAccount().transfer(receiver->getAccount(), amount);
    }

    void showTransactionHistory() {
        int id;
        cout << "\nEnter Customer ID: ";
        cin >> id;
        Customer* c = findCustomer(id);
        if (c)
            c->getAccount().printTransactions();
        else
            cout << "Customer not found.\n";
    }

    void menu() {
        int choice;
        while (true) {
            cout << "\n\n=========== BANKING MENU ===========\n";
            cout << "1. Create Customer\n";
            cout << "2. Show Customer Details\n";
            cout << "3. Deposit\n";
            cout << "4. Withdraw\n";
            cout << "5. Transfer\n";
            cout << "6. View Transaction History\n";
            cout << "7. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: createCustomer(); break;
                case 2: showCustomerDetails(); break;
                case 3: depositToAccount(); break;
                case 4: withdrawFromAccount(); break;
                case 5: transferBetweenAccounts(); break;
                case 6: showTransactionHistory(); break;
                case 7: cout << "Exiting Banking System. Goodbye!\n"; return;
                default: cout << "Invalid choice.\n";
            }
        }
    }
};

int main() {
    BankingSystem bank;
    bank.menu();
    return 0;
}

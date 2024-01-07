#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(const string& number, const string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Error: Insufficient funds." << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Accessor methods
    const string& getAccountNumber() const {
        return accountNumber;
    }
};

class OnlineBankingSystem {
private:
    vector<BankAccount> accounts;
    static int lastAccountNumber;

public:
    OnlineBankingSystem() {
        lastAccountNumber = 1000;
    }
string intToString(int value) {
    stringstream ss;
    ss << value;
    return ss.str();
}
    void createAccount(const string& holder, const string& cnic) {
        // Generate a unique account number
        string accountNumber = "A" + intToString(lastAccountNumber++);

        BankAccount newAccount(accountNumber, holder, 0.0);  // Initial balance set to 0
        accounts.push_back(newAccount);
        cout << "Account created successfully. Account Number: " << accountNumber << endl;
    }

    BankAccount* findAccount(const string& accountNumber) {
         // Check if the account number already exists
for (size_t i = 0; i < accounts.size(); ++i) {
    if (accounts[i].getAccountNumber() == accountNumber) {
        cout << "Account with this number already exists." << endl;
        return &accounts[i];
    }
}
    }
};

int OnlineBankingSystem::lastAccountNumber = 1000;

int main() {
    OnlineBankingSystem bankingSystem;

    int choice;
    string accountNumber;
    string accountHolder;
    string cnic;
    double amount;

    do {
        cout << "\nMenu:\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder's name: ";
                cin.ignore();
                getline(cin, accountHolder);
                cout << "Enter CNIC: ";
                cin >> cnic;
                bankingSystem.createAccount(accountHolder, cnic);
                break;

            case 2:
                cout << "Enter account number for deposit: ";
                cin >> accountNumber;
                {
                    BankAccount* account = bankingSystem.findAccount(accountNumber);
                    if (account) {
                        cout << "Enter amount to deposit: $";
                        cin >> amount;
                        account->deposit(amount);
                    } else {
                        cout << "Account not found." << endl;
                    }
                }
                break;

            case 3:
                cout << "Enter account number for withdrawal: ";
                cin >> accountNumber;
                {
                    BankAccount* account = bankingSystem.findAccount(accountNumber);
                    if (account) {
                        cout << "Enter amount to withdraw: $";
                        cin >> amount;
                        account->withdraw(amount);
                    } else {
                        cout << "Account not found." << endl;
                    }
                }
                break;

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> 

using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;
    string pin;
    
public:
    Account(int accNum, string accName, string accPin) {
        accountNumber = accNum;
        name = accName;
        pin = accPin;
        balance = 0.0;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getName() {
        return name;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;  // Add deposit amount to balance
            cout << "Deposit successful! New balance: " << balance << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;  // Deduct withdrawal amount from balance
            cout << "Withdrawal successful! New balance: " << balance << endl;
            return true;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
            return false;
        }
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    bool authenticate(string enteredPin) {
        return pin == enteredPin;  // Check if entered PIN matches account PIN
    }

    void changePin(string newPin) {
        pin = newPin;  // Change account PIN
        cout << "PIN changed successfully!" << endl;
    }

    bool resetPin(int accNum, string accName) {
        // Validate account details for PIN reset
        if (accountNumber == accNum && name == accName) {
            return true;
        }
        return false;
    }
};

class Bank {
private:
    vector<Account> accounts;
    int nextAccountNumber;  // Tracks the next available account number

public:
    Bank() {
        nextAccountNumber = 1000;  // Start account numbers from 1000
    }

    void createAccount() {
        string name, pin;

        // Clear input buffer
        cin.ignore();

        cout << "Enter Account Holder Name: ";
        getline(cin, name);  // Use getline to read full name
        cout << "Enter PIN: ";
        cin >> pin;

        // Automatically assign the next account number
        int accNum = nextAccountNumber++;
        
        Account newAccount(accNum, name, pin);
        accounts.push_back(newAccount);  // Add new account to the bank
        cout << "Account created successfully! Your account number is " << accNum << endl;
    }

    Account* findAccount(int accNum) {
        // Search for account using account number
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;  // Return nullptr if account not found
    }

    void loginAndManageAccount() {
        int accNum;
        string pin;

        // Input validation for account number
        while (true) {
            cout << "Enter Account Number: ";
            cin >> accNum;

            // Check if input is valid (i.e., an integer)
            if (cin.fail()) {
                cin.clear();  // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the invalid input
                cout << "Invalid input! Please enter a valid account number (numeric values only).\n";
            } else {
                break;  // Valid input, exit the loop
            }
        }

        Account* account = findAccount(accNum);  // Look up the account by account number
        if (account == nullptr) {
            cout << "Account not found!" << endl;
            return;  // Exit the function if account is not found
        }

        cout << "Enter PIN: ";
        cin >> pin;

        if (account->authenticate(pin)) {  // Authenticate user with PIN
            int choice;
            do {
                cout << "\n1. View Balance\n2. Deposit\n3. Withdraw\n4. View Account Info\n5. Change PIN\n6. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                double amount;
                string newPin;
                switch (choice) {
                    case 1:
                        cout << "Balance: " << account->getBalance() << endl;  // View balance
                        break;
                    case 2:
                        cout << "Enter deposit amount: ";
                        cin >> amount;
                        account->deposit(amount);  // Deposit funds
                        break;
                    case 3:
                        cout << "Enter withdrawal amount: ";
                        cin >> amount;
                        account->withdraw(amount);  // Withdraw funds
                        break;
                    case 4:
                        account->displayAccountInfo();  // Display account info
                        break;
                    case 5:
                        cout << "Enter new PIN: ";
                        cin >> newPin;
                        account->changePin(newPin);  // Change account PIN
                        break;
                    case 6:
                        cout << "Logging out..." << endl;  // Exit from account management
                        break;
                    default:
                        cout << "Invalid choice! Please try again." << endl;
                }
            } while (choice != 6);
        } else {
            cout << "Invalid PIN!" << endl;
            int resetChoice;
            cout << "Would you like to reset your PIN? (1: Yes / 2: No): ";
            cin >> resetChoice;

            if (resetChoice == 1) {
                resetPin(account);  // Option to reset PIN
            }
        }
    }

    void resetPin(Account* account) {
        int accNum;
        string accName;

        // Ask for the account details to reset the PIN
        cout << "Enter Account Number: ";
        cin >> accNum;
        cin.ignore();  // To clear the input buffer

        cout << "Enter Account Holder Name: ";
        getline(cin, accName);
        
        if (account->resetPin(accNum, accName)) {  // Validate details for PIN reset
            string newPin;
            cout << "Enter new PIN: ";
            cin >> newPin;
            account->changePin(newPin);  // Change PIN
        } else {
            cout << "Incorrect account details!" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n1. Create Account\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();  // Create a new account
                break;
            case 2:
                bank.loginAndManageAccount();  // Log in and manage account
                break;
            case 3:
                cout << "Exiting program..." << endl;  // Exit program
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

#include <iostream>
#include <utility>
#include <map>
#include <string>

class bankAcc {
public:
    std::string name;
    std::string pin;
    int bal;
    bankAcc(std::string x, std::string y, int z);
    void withdraw();
    void deposit();
    void showBal();
    std::string editAcc();
};

bankAcc::bankAcc(std::string x, std::string y, int z) {
    name = std::move(x);
    pin = std::move(y);
    bal = z;
}

void bankAcc::withdraw() {
    int val;

    std::cout << "How Much Do You Want to Withdraw\n"; std::cin >> val;

    if (val <= bal) {
        bal -= val;
        std::cout << "Fund Withdraw Successful\n";
    } else {
        std::cout << "The Account Does Not Have Enough Funds\n";
    }
    showBal();
}

void bankAcc::deposit() {
    int val;

    std::cout << "How Much Do You Want to Deposit\n"; std::cin >> val;

    bal += val;

    std::cout << "Fund Deposit Successful\n";
    showBal();
}

void bankAcc::showBal() {
    std::cout << "Current Balance is $" << bal << "\n";
}

std::string bankAcc::editAcc() {
    std::string input;

    std::cout << "Enter Your PIN to Continue\n"; std::cin >> input;

    if (pin == input) {
        std::cout << "New Name:\n"; std::cin >> name;
        std::cout << "New PIN:\n"; std::cin >> pin;
    } else {
        std::cout << "You Are Not Authorized\n";
    }

    return name;
}

int main() {
    std::map<std::string, bankAcc*> users;
    std::string input, name, pin;

    do {
        std::cout << "A. Log-in\nB. Sign-up\nC. Quit\n";std::cin >> input;

        if (input == "C") break;

        std::cout << "Name:\n"; std::cin >> name;
        std::cout << "PIN:\n"; std::cin >> pin;

        if (input == "A") {
            if (users.find(name) == users.end()) {
                std::cout << "The User Does Not Exist\n";
            } else if (users[name]->pin != pin) {
                std::cout << "The PIN is Incorrect\n";
            } else {
                std::cout << "You Have Been Logged-In Successfully\n";
                do {
                    std::cout << "A. Withdraw\nB. Deposit\nC. Current Balance\nD. Edit Account\nE. Delete Account\nF. Back\n"; std::cin >> input;

                    if (input == "A") {
                        users[name]->withdraw();
                    } else if (input == "B") {
                        users[name]->deposit();
                    } else if (input == "C") {
                        users[name]->showBal();
                    } else if (input == "D") {
                        //users[name]->editAcc();
                        users.extract(name).key() = users[name]->editAcc();
                        users.insert(std::move(users.extract(name)));
                    } else if (input == "E") {
                        std::cout << "Confirm Delete by Typing PIN\n"; std::cin >> input;
                        if (users[name]->pin == pin) users.erase(name);
                    } else if (input == "F") {
                        break;
                    }
                } while (true);
            }
        } else if (input == "B") {
            users.insert({name, new bankAcc(name, pin, 0)});
            std::cout << "Your Account Has Been Initialized Successfully\n";
        }
    } while (true);

    // store to csv

    return 0;
}

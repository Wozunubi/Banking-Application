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
    void withdraw(int);
    void deposit(int);
    void showBal();
};

bankAcc::bankAcc(std::string x, std::string y, int z) {
    name = std::move(x);
    pin = std::move(y);
    bal = z;
}

void bankAcc::withdraw(int val) {

}

void bankAcc::deposit(int val) {

}

void bankAcc::showBal() {
    std::cout << "Current Balance: " << bal;
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
            //Action
            std::cout << "You Have Been Logged-In Successfully\n";
            do {
                std::cout << "A. Withdraw\nB. Deposit\nC. Current Balance\nD. Edit Account\nE. Delete Account\nF. Back\n"; std::cin >> input;

                if (input == "A") {

                } else if (input == "B") {

                } else if (input == "C") {

                } else if (input == "D") {

                } else if (input == "E") {

                } else if (input == "F") {
                    break;
                }
            } while (true);
        } else if (input == "B") {
            users.insert({name, new bankAcc(name, pin, 0)});
            std::cout << "Your Account Has Been Initialized Successfully\n";
        }
    } while (true);

    std::cout << users["George"]->name;

    std::cin >> input;

    return 0;
}

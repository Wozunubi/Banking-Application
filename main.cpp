#include <iostream>
#include <utility>
#include <vector>
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
    std::vector<bankAcc> users;
    std::string input, name, pin;

    do {
        std::cout << "A. Log-in\nB. Sign-up\n"; std::cin >> input;
        std::cout << "Name:\n"; std::cin >> name;
        std::cout << "PIN:\n"; std::cin >> pin;

        if (input == "A") {
            //Action
            std::cout << "You Have Been Logged-In Successfully\n";
            break;
        } else if (input == "B") {
            //Action
            std::cout << "Your Account Has Been Initialized Successfully\n";
        }
    } while (true);

    return 0;
}

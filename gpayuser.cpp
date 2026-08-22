#include <iostream>
using namespace std;

class GPayUser {

private:
    string name;
    string phone;
    string upiId;
    double balance;

public:

    // Constructor
    GPayUser(string n, string p, string u, double b) {
        name = n;
        phone = p;
        upiId = u;
        balance = b;
    }

    // Getters
    string getName() {
        return name;
    }

    string getPhone() {
        return phone;
    }

    string getUpiId() {
        return upiId;
    }

    double getBalance() {
        return balance;
    }

    // Setters
    void setName(string n) {
        name = n;
    }

    void setPhone(string p) {
        phone = p;
    }

    void setUpiId(string u) {
        upiId = u;
    }

    void setBalance(double b) {
        balance = b;
    }

    // Behavior: Send money
    void sendMoney(GPayUser &receiver, double amount) {

        if (balance >= amount) {

            balance = balance - amount;
            receiver.balance = receiver.balance + amount;

            cout << name << " (" << upiId << ") sent Rs. "
                 << amount << " to "
                 << receiver.name << " (" << receiver.upiId << ")"
                 << endl;
        }
        else {
            cout << name << " does not have enough balance." << endl;
        }
    }

    // Destructor
    ~GPayUser() {
        cout << name << " object destroyed." << endl;
    }
};


int main() {

    // Creating 5 GPay users
    GPayUser user1("Shalini", "9876543210", "shalini@upi", 5000);
    GPayUser user2("Rahul", "9876543211", "rahul@upi", 3000);
    GPayUser user3("Priya", "9876543212", "priya@upi", 4000);
    GPayUser user4("Anu", "9876543213", "anu@upi", 6000);
    GPayUser user5("Arjun", "9876543214", "arjun@upi", 2000);


    // Display details before payment
    cout << "Before Payment:" << endl;

    cout << user1.getName()
         << " | UPI ID: " << user1.getUpiId()
         << " | Balance: Rs. " << user1.getBalance()
         << endl;

    cout << user2.getName()
         << " | UPI ID: " << user2.getUpiId()
         << " | Balance: Rs. " << user2.getBalance()
         << endl;


    // Payment
    cout << endl;

    user1.sendMoney(user2, 1000);


    // Display details after payment
    cout << endl;
    cout << "After Payment:" << endl;

    cout << user1.getName()
         << " | UPI ID: " << user1.getUpiId()
         << " | Balance: Rs. " << user1.getBalance()
         << endl;

    cout << user2.getName()
         << " | UPI ID: " << user2.getUpiId()
         << " | Balance: Rs. " << user2.getBalance()
         << endl;


    return 0;
}

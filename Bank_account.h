#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
#include <cstring>
using namespace std;

/*Name: Vikharankar Vishakha Chandrakant
   Enrol. No.: BT19CSE118
   Assignment No: 1
   Description: System in which user can create account if he doesnt have one and can then login and perform withdrawal/deposit/show balance*/

class Bank_account
{
private:
    int user_id;
    string password;
    int balance;
public:
    Bank_account(int n = 0, string s = "", int bal = 0);//Default + Parameterised constructor
    void set_data(int n, string s, int bal);//Setter function
    void display();//Displaying info of account holder
    void withdraw(int val);//For withdrawing money
    void deposit(int val);//For depositting money
    int get_balance();//Getter function for balance
    string get_password();//Getter function to get password
};

#endif // BANK_ACCOUNT_H

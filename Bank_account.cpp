#include "Bank_account.h"

//Default + Parameterised constructor
Bank_account::Bank_account(int n, string s, int bal)
{
    user_id = n;
    password = s;
    balance = bal;
}
//Setter function
void Bank_account::set_data(int n, string s, int bal)
{
    user_id = n;
    password = s;
    balance = bal;
}
//Function for withdrawing and making changes in balance as required
void Bank_account::withdraw(int val)
{
    if(val <= balance)
    {
        balance -= val;
        cout << "Current balance: " << balance;
    }
    else
    {
        cout << "Low balance\n";
    }
}
//Function for depositting and making changes as required
void Bank_account::deposit(int val)
{
    balance += val;
    cout << "Current balance is: " << balance << '\n';
}
//Getter function for balance
int Bank_account::get_balance()
{
    return balance;
}
//Getter function for password
string Bank_account::get_password()
{
    return password;
}
//Function to display data of person
void Bank_account::display()
{
    cout << "User Id: " << user_id << '\n';
    cout << "Password: " << password << '\n';
    cout << "Bank balance: " << balance << '\n';
}

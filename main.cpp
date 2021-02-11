#include <iostream>
#include "Bank_account.h"
using namespace std;
//Function for logging in, quitting, and performing various
//operations in case of successful login
void fun(Bank_account b[])
{
    cout << "\n**********************************************************************\n";
    cout << "\n\nPlease enter your userid and password to login\n\n";
    cout << "Enter userid\n";
    int id;//Variable that takes id of user
    cin >> id;
    if(id > 0 && id <= 3 )//Initial check if id lies within range
    {
        string s;
        cout << "Enter password\n";//Input password for given username
        fflush(stdin);
        cin >> s;
        //Comparing if strings match
        if(b[id - 1].get_password() == s)//If password matches providing option for further possible operations
        {
            cout << "\n\nLOGIN SUCCESSFUL\n\n";
            int n, val;
            cout << "If you want to \n 1)Withdraw money press 1\n 2)Deposit money press 2\n 3)Request balance press 3\n 4)Quit session press 4\n";
            cin >> n;
            //Using switch so as to call member fun as per requirement
            switch(n)
            {
            case 1:cout << "Enter val\n";cin >> val;b[id - 1].withdraw(val);//For withdrawal
                    break;
            case 2:cout << "Enter val\n";cin >> val;b[id - 1].deposit(val);//For depositting
                    break;
            case 3:cout << b[id - 1].get_balance();//For checking balance
                    break;
            default:cout << "Thanks\n";
            }
        }
        else//If password doesnt match giving user option to enter id password again
        {
            cout << "Given info doesnt exist\n";
            cout << "If u want to try again press 1 else 0 for exitting\n";
            int x;
            cin >> x;
            if(x)
            {
                fun(b);//Calling function again
            }
            else
            {
                return ;//Else exitting
            }
        }
    }
    else//If id provide doesnt match giving user option to enter id password again
    {
        cout << "Given info doesnt exist\n";
        cout << "If u want to try again press 1 else 0 for exitting\n";
        int x;
        cin >> x;
        if(x)
        {
            fun(b);//Calling function again
        }
        else
        {
            return ;//Else exitting
        }
    }

}

int main()
{
    Bank_account b[3];//System with 3 entries
    //Set id, password and initial balance for all 3 entries
    b[0].set_data(1, "pass123", 1000);
    b[1].set_data(2, "123pass", 1500);
    int status;//To keep track if user wants to create account or has one already
    cout << "If you want to register enter 1 else if you already have account and want to login enter 0\n";
    cin >> status;//Variable to keep track of what user demands
    if(status)
    {
        //Id assigned to new user is 3
        cout << "Your id is 3\n";
        //Ask user to create his new password
        cout << "Create password\n";
        string pass;//Variable to store password
        fflush(stdin);
        getline(cin, pass);
        //And then setting values to object
        b[2].set_data(3, pass, 500);
        cout << "\nWELCOME\nYour current account info is as follows\n";
        //Using display function to display current info of user
        b[2].display();
    }

    fun(b);//Function call by passing argument as entries in system
    return 0;
}

// ATM Machine program QA by VITUG, Angelo G. 11 - Python
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userId, userPass;
    string createId, createPass;
    bool loginReq = false;

    cout << "Welcome to Vitug's ATM Machine !" << endl;

    while (!loginReq) {
        int passAttempt = 1;
        char loginOpt, verify = 'n';
        bool verifyReq;

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "* Kindly use the corresponding character when selecting *" << endl;
        cout << "Select an option from the menu below: " << endl;
        cout << "l > Login" << endl;
        cout << "c > Create Account" << endl;
        cout << "q > Quit" << endl;
        cout << "Input: ";
        cin >> loginOpt;

        switch (loginOpt) {
        case 'l':
        case 'L':
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~ Login ~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Please enter your username: ";
            cin >> userId;
            cout << "Please enter your password: ";
            cin >> userPass;
            if (userId == createId && userPass == createPass) {
                cout << "You have successfully logged in !" << endl;
                loginReq = true;
                break;
            }
            else {
                cout << "Login failed !" << endl;
                continue;
            }
        case 'c':
        case 'C':
            cout << "~~~~~~~~~~~~~~~~~~~~~ Account Creation ~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "REMINDER !!! Spaces are not allowed. This is to keep login info simple." << endl;
            while (verify == 'n') {
                string verifyPass;
                verifyReq = false;
                cout << "Please enter your username: ";
                cin >> createId;
                cout << "Please enter your password: ";
                cin >> createPass;
                cout << "You only have 3 attempts to verify your password." << endl;
                while (verifyPass != createPass && passAttempt <= 3) {
                    cout << "You are on attempt number " << passAttempt << "." << endl;
                    cout << "Please verify your password: ";
                    cin >> verifyPass;
                    if (verifyPass == createPass) {
                        cout << "Password Match !" << endl;
                        break;
                    }
                    else {
                        cout << "-----------------------------------------------------------" << endl;
                        cout << "Your password is wrong. Please try again." << endl;
                        passAttempt++;
                        continue;
                    }
                }
				if (passAttempt == 4) {
                    break;
                }
                cout << "-----------------------------------------------------------" << endl;
                cout << "Please verify if the following information is correct.\nEnter 'y' to proceed or 'n' to restart the process\n";
                cout << "Username: " << createId << endl;
                cout << "Password: " << createPass << endl;
                while (!verifyReq) {
                    cout << "Input: ";
                    cin >> verify;
                    if (verify == 'y') {
                        verifyReq = true;
                        break;
                    }
                    else if (verify == 'n') {
                        verifyReq = true;
                        break;
                    }
                    else {
                        cout << "You input an invalid character" << endl;
                        continue;
                    }
                }
                if (verify == 'y') {
                    break;
                }
                else if (verify == 'n') {
                    cout << "-----------------------------------------------------------" << endl;
                    cout << "User request to restart process." << endl;
                    continue;
                }
            }
            if (verify == 'y') {
                cout << "Account created successfully !" << endl;
                userId = createId;
                userPass = createPass;
                continue;
            }
            else if (passAttempt == 4) {
                cout << "You failed to verify your password. Please recreate your account." << endl;
                continue;
            }
        case 'q':
        case 'Q':
            cout << "Thank you for using this ATM Machine ! The app will now exit." << endl;
            return 0;
            break;
        default:
            cout << "You input an invalid option, please try again." << endl;
            continue;
        }
    }
    char atmOpt;
    float accBal = 0, accDep, accWtdrw;
    bool atmReq = false;

    while (!atmReq) {
        cout << "-----------------------------------------------------------" << endl;
        cout << "* Kindly use the corresponding character when selecting *" << endl;
        cout << "Select an option from the menu below: " << endl << endl;
        cout << "d > Deposit Money" << endl;
        cout << "w > Withdraw Money" << endl;
        cout << "b > Account Balance" << endl;
        cout << "q > Quit" << endl;
        cout << "Input: ";
        cin >> atmOpt;
        
        switch (atmOpt) {
        case 'd':
        case 'D':
            cout << "Deposit amount: $";
            cin >> accDep;
            cout << "Successfully deposited $" << accDep << endl;
            accBal = accBal + accDep;
            continue;
        case 'w':
        case 'W':
            cout << "Withdraw amount: $";
            cin >> accWtdrw;
            if (accBal - accWtdrw < 0) {
                cout << "Sorry, but you cannot withdraw $" << accWtdrw << " as you do not have enough money in your account." << endl;
                continue;
            }
            else {
                cout << "Successfully withdrew $" << accWtdrw << endl;
                accBal = accBal - accWtdrw;
                continue;
            }
        case 'b':
        case 'B':
            cout << "Your balance is: $" << accBal << endl;
            continue;
        case 'q':
        case 'Q':
            cout << "Thank you for using this ATM Machine ! The app will now exit." << endl;
            atmReq = true;
            break;
        default:
            cout << "You input an invalid option, please try again." << endl;
            continue;
        }
    }
    return 0;
}
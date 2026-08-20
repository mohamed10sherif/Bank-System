#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool  _Login()
    {
        bool LoginFaild = false;
        short TrialsToLogin = 3; 
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                TrialsToLogin--; 
                cout << "\nInvlaid Username/Password!\n";
                cout << "You have " << TrialsToLogin << " trial(s) to login \n\n";
            }
            if (TrialsToLogin == 0)
            {
                cout << "You are locked after 3 failed trails \n\n";
                return false; 
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true; 

    }

public:


    static bool  ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};
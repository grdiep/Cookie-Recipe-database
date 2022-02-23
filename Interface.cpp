#include "Interface.h"

#include <string>
#include <iostream>

using namespace std;

void displayMenu()
{
    cout << "**************************************************************" << endl
    << "                        COOKIE RECIPES" << endl
    << "**************************************************************" << endl
    << endl;

    cout << "Select one of the following:" << endl << endl << "    a. Print all recipes"
    << endl << "    b. Print cookie recipe" << endl
    << "    c. Print cookie calories" << endl << "    d. Print limited calories"
    << endl << "    e. To exit" << endl << endl;
}

void processChoice(CookieList& cookieList)
{
    char input = 'y';

    bool isE = false;
    while (input != 'n' && !isE)
    {
        cout << "Enter your choice: ";
        cin >> input;
        bool changeQuestion = false;
        size_t selection = 0;
        size_t maxCalories = 0;

        switch(input)
        {
            case 'a':
                if (cookieList.isEmpty())
                {
                    // SWITCHED TO CERR
                    cerr << endl << "  => There are no recipes in the list." << endl
                    << endl << "=============================================================="
                    << endl << endl << "Please contact your administrator. Good bye!" << endl;
                    isE = true;
                }
                else
                {
                    cout << endl << "--------------------------------------------------------------"
                        << endl << "    COOKIE RECIPES" << endl <<
                        "--------------------------------------------------------------" << endl
                        << endl;
                    cookieList.printAllCookies();
                    changeQuestion = true;
                    //cout << endl;
                }
                break;

            case 'b':
                if (cookieList.isEmpty())
                {
                    // SWITCHED TO CERR
                    cerr << endl << "  => There are no recipes in the list." << endl
                    << endl << "=============================================================="
                    << endl << endl << "Please contact your administrator. Good bye!" << endl;
                    isE = true;
                }

                else
                {
                    cout << endl << "--------------------------------------------------------------"
                        << endl << "    COOKIE RECIPE" << endl <<
                        "--------------------------------------------------------------" << endl
                        << endl << "Choose a cookie to view the recipe." << endl << endl;
                    cookieList.printCookiesSelection();
                    cout << "Your choice: ";

                    cin >> selection;
                    cout << endl;
                    cookieList.printRecipe(selection);
                    cout << endl;
                    changeQuestion = true;
                }
                break;

            case 'c':
                if (cookieList.isEmpty())
                {
                    // SWITCHED TO CERR
                    cerr << endl << "  => There are no recipes in the list." << endl
                    << endl << "=============================================================="
                    << endl << endl << "Please contact your administrator. Good bye!" << endl;
                    isE = true;
                }
                else
                {
                    cout << endl << "--------------------------------------------------------------"
                            << endl << "    COOKIE CALORIES" << endl <<
                            "--------------------------------------------------------------" << endl
                            << endl << "Choose a cookie # to view number of calories." << endl
                            << endl;
                    cookieList.printCookiesSelection();
                    cout << "Your choice: ";
                    cin >> selection;
                    cout << endl;
                    cookieList.printCalories(selection);
                    cout << endl;
                    changeQuestion = true;
                }
                break;

            case 'd':
                if (cookieList.isEmpty())
                {
                    // SWITCHED TO CERR
                    cerr << endl << "  => There are no recipes in the list." << endl
                    << endl << "=============================================================="
                    << endl << endl << "Please contact your administrator. Good bye!" << endl;
                    isE = true;
                }
                else
                {
                    cout << endl << "--------------------------------------------------------------"
                        << endl << "    MAXIMUM CALORIES" << endl <<
                        "--------------------------------------------------------------" << endl
                        << endl << "What is the maximum # of calories (100-200)? ";

                    cin >> maxCalories;
                    cout << endl;
                    cookieList.printLimitedCalories(maxCalories);
                    cout << endl;
                    changeQuestion = true;
                }
                break;

            case 'e':
                cout << endl << "Thank you for using our software. Good bye!";
                isE = true;
                break;

            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'z': cout << endl << "  => Sorry. That is not a selection." << endl << endl; break;
        }

        if (input != 'e' && !isE)
        {
            if (!changeQuestion)
            {
                cout << "=============================================================="
                    << endl << endl << "Would you like to try again (y/n)? ";
            }
            else
            {
                cout << "=============================================================="
                    << endl << endl << "Would you like to continue (y/n)? ";
            }

            cin >> input;

            if (input == 'n')
                cout << endl << "Thank you for using our software. Good bye!";
            else if (input == 'y')
            {
                cout << endl;
                displayMenu();
            }
        }
    }
}
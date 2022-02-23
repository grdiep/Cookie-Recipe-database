#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "Testing.cpp"
#include "Interface.cpp"

using namespace std;

int main()
{
    CookieList cList;
    createCookieList(cList);
    displayMenu();
    processChoice(cList);

        cout << endl;
        return 0;
}
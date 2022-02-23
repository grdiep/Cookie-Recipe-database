//MainPartB

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <iomanip>

#include "Testing.h"
#include "CookieList.h"

using namespace std;

int main()
{
    // cout << "Default CookieList Constructor" << endl;
    CookieList cookieList1;
    // cout << "Count for Default CookieList1: " << cookieList1.getCount() << endl << endl;

    //count1 = 12;
    createCookieList(cookieList1);
    cout << "CookieList 1 contains: " << endl;
    cookieList1.printAllCookies();
    cout << "Count for CookieList1: " << cookieList1.getCount() << endl;

    // CookieList cookieList2;
    // createCookieList(cookieList2);

    // cout << "CookieList 1 contains: " << endl;
    // cookieList1.printAllCookies();
    // // cout << "Count for CookieList1: " << cookieList1.getCount() << endl;

    // count2 = 12
    cout << "this is COPY CONSTRUCTOR for cookieList2" << endl;
    CookieList cookieList2(cookieList1); // copy
    cookieList2.printAllCookies();

    cout <<"-------------------------------------------------------------" << endl;

    // cookieList1.clearList();
    // cout << "Printing out CookieList1: ";
    // cookieList1.printAllCookies(); //cookieList1 is empty
    // cout << "Count for EMPTY CookieList1: " << cookieList1.getCount() << endl;

    //set<string> ingre = {"flour", "sugar"};

    //cout << "Adding 1 cookie to empty CookieList1" << endl;
    // set<string> ingre = {"flour", "sugar"};
    //Cookie yum ("brownie", 33, ingre, 999);  // maybe const has bugs
    //cookieList1.addCookie(yum);
    //cookieList1.printAllCookies();
    //cout << "Count for CookieList1 should now HAVE :  " << cookieList1.getCount() << endl;

    // cout << "Printing out CookieList2: " << endl;
    // cookieList2.printAllCookies(); //cookieList1 is empty
    // cout << "Count for CookieList2: " << cookieList2.getCount() << endl;

    // cout << "testing out copyCallingShorter function: " << endl;
    // cout << "cookielist1 should now have 12 cookies;" << endl;
    // cookieList1.copyCallingObjShorter(cookieList2);
    // cookieList1.printAllCookies(); //cookieList1 is now filled

    // cout << "testing out copyCallingSameLength function: " << endl;
    // cookieList1.copyObjectsSameLength(cookieList2);
    // cookieList1.printAllCookies(); //cookieList1 is now filled

    // cout << "testing out copyCallingLonger function: " << endl;
    // cookieList1.copyCallingObjLonger(cookieList2);
    // cookieList1.printAllCookies(); //cookieList1 is now filled
    cout << cookieList1.searchCookie("Lemon Square Bars") << endl;

    cout << "---------------------------------------------------------" << endl;

    CookieList cookieList3;
    cookieList3 = cookieList1; //cookieList3 count = 12

    cout << "print assignment operator for cookieList3" << endl;
    cookieList3.printAllCookies();

    //count == otherCookieList.count
    CookieList cookieList4;
    set<string> ingre = {"flour", "sugar"};
    Cookie yum ("brownie", 33, ingre, 999);
    cookieList4.addCookie(yum);

    CookieList cookieList5;
    set<string> ingre2 = {"chicken", "sugar"};
    Cookie yummy ("vanilla", 33, ingre2, 999);
    cookieList5.addCookie(yummy);

    cookieList4 = cookieList5;
    cout << "CookieList4 contains: \n";
    cookieList4.printAllCookies();

    CookieList cookieList6;
    set<string> ingre3 = {"porkchop", "sugar"};
    Cookie yuck ("chocolate", 33, ingre3, 999);
    cookieList6.addCookie(yuck);
    set<string> ingre4 = {"milk", "sugar"};
    Cookie yucky ("chocolate", 33, ingre4, 999);
    cookieList6.addCookie(yucky); //cookieList6 has 2 elems

    cookieList6 = cookieList5; //cookieList6 has 2 obj, cookieList5 has 1
    cout << "CookieList6 contains: \n";
    cookieList6.printAllCookies(); //"vanilla"

    //cookieList 7 and 8
    CookieList cookieList7; //has 2 objs
    set<string> ingre5 = {"skim", "sugar"};
    Cookie jam ("chocolate", 33, ingre5, 999);
    cookieList7.addCookie(jam);
    set<string> ingre6 = {"fat", "sugar"};
    Cookie dog ("cocoa", 33, ingre6, 999);
    cookieList7.addCookie(dog);

    CookieList cookieList8; //has 1 obj
    set<string> ingre7 = {"cat", "sugar"};
    Cookie jack ("peanutButtre", 33, ingre7, 999);
    cookieList8.addCookie(jack);

    cookieList8 = cookieList7; //cookieList8 to have 2 objs,
    cout << "cookieList8 contains: \n";
    cookieList8.printAllCookies(); //chocolate and cocoa

}
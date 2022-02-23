#include "CookieList.h"
#include "Cookie.cpp"

using namespace std;

// Constructors
CookieList::CookieList()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

// Function addCookie
void CookieList::addCookie(const Cookie& aCookie)
{
    if (count == 0)
    {
        first = new Node(aCookie, nullptr);
        last = first;
    }
    else
    {
        last->setNext(new Node(aCookie, nullptr));
        last = last->getNext();
    }
    ++count;
}

void CookieList::addCookie(const string& newName, size_t newCalories,
	const set<string>& newIngredients, size_t newServings)
{
    Cookie aCookie(newName, newCalories, newIngredients,
                    newServings);

    addCookie(aCookie);
}

// Accessor function
size_t CookieList::getCount() const
{
    return count;
}

// Boolean functions
bool CookieList::isEmpty() const
{
    return (count == 0);
}

bool CookieList::searchCookie(const string& aCookie) const
{
    bool found = false;
    if ((first->getCookie().getName() == aCookie)
       || (last->getCookie().getName() == aCookie))
    {
        found = true;
        return found;
    }
    else
    {
        Node * ptr = first->getNext();
        while(!found && ptr->getNext() != nullptr)
        {
            if (ptr->getCookie().getName() == aCookie)
                found = true;
            else
                ptr = ptr->getNext();
        }
        return found;
    }
}

// Print functions
void CookieList::printAllCookies() const
{
        Node * ptr = first;
        while (ptr != nullptr)
        {
            cout << "    " << ptr->getCookie().getName() << endl;
            ptr = ptr->getNext();
        }
        cout << endl;
}

void CookieList::printCookiesSelection() const
{
    Node * ptr = first;
    int i = 1;
    while (ptr != nullptr)
    {
        cout << "    " << i << ": " << ptr->getCookie().getName() << endl;
        ptr = ptr->getNext();
        ++i;
    }
    cout << endl;
}

void CookieList::printRecipe(size_t& selection)
{
    Node * cookieAtAddress = getCookieLocation(selection);

    cookieAtAddress->getCookie().printRecipe();
    cookieAtAddress->getCookie().printIngredients();
}

void CookieList::printCalories(size_t& selection)
{
    Node * cookieAtAddress = getCookieLocation(selection);
    cookieAtAddress->getCookie().printCalories();
}

void CookieList::printLimitedCalories(size_t& maxCalories)
{
    Node * ptr = first;
    while (ptr != nullptr)
    {
        if (ptr->getCookie().getCalories() <= maxCalories)
        {
            ptr->getCookie().printCalories();
        }
        ptr = ptr->getNext();
    }
}

// Function clearList
void CookieList::clearList()
{
    Node * temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    last = nullptr;
    count = 0;
}

 // The Big Three
CookieList::CookieList(const CookieList& otherCookieList)
{
    first = nullptr;
    last = nullptr;
    count = 0;

    Node * temp = otherCookieList.first;
    while (temp != nullptr)
    {
        addCookie(temp->getCookie());
        temp = temp->getNext();
    }
    count = otherCookieList.count;
}

CookieList& CookieList::operator=(const CookieList& otherCookieList)
{
    if (this == &otherCookieList)
        cerr << "Cannot do self-assignment." << endl;
    else
    {
        if (otherCookieList.isEmpty())
            cout << "Cannot copy because there is nothing to copy." << endl;
        else if (count == 0)
            copyCallingObjIsEmpty(otherCookieList);
        else if (count == otherCookieList.count)
          copyObjectsSameLength(otherCookieList);
        else if (count > otherCookieList.count)
            copyCallingObjLonger(otherCookieList);
        else if (count < otherCookieList.count)
            copyCallingObjShorter(otherCookieList);

        count = otherCookieList.count;
    }
    return *this;
}

CookieList::~CookieList()
{
    clearList();
}

//helper functions
void CookieList::copyCallingObjIsEmpty(const CookieList& otherCookieList)
{
    Node * paramPtr = otherCookieList.first;
    while (paramPtr != nullptr)
    {
        addCookie(paramPtr->getCookie());
        paramPtr = paramPtr->getNext();
    }
    count = otherCookieList.count;
}

void CookieList::copyObjectsSameLength(const CookieList& otherCookieList)
{
    Node * paramPtr = otherCookieList.first;
    Node * callingPtr = first;
    while (paramPtr != nullptr)
    {
        callingPtr->setCookie(paramPtr->getCookie());
        paramPtr = paramPtr->getNext();
        callingPtr = callingPtr->getNext();
    }
    count = otherCookieList.count;
}

void CookieList::copyCallingObjLonger(const CookieList& otherCookieList)
{
    size_t callingCount = count;
    size_t paramCount = otherCookieList.count;

    Node * paramPtr = otherCookieList.first;
    Node * callingPtr = first;
    while (paramPtr != nullptr)
    {
        callingPtr->setCookie(paramPtr->getCookie());
        paramPtr = paramPtr->getNext();
        callingPtr = callingPtr->getNext();
    }

    size_t i = paramCount - 1;
    Node * anotherPtr = first;
    while (i > 0)
    {
        anotherPtr = anotherPtr->getNext();
        --i;
    }

    Node * tempLast = anotherPtr->getNext();
    Node * ptrDelete = anotherPtr->getNext();
    while (ptrDelete != nullptr)
    {
        ptrDelete = ptrDelete->getNext();
        delete tempLast;
        tempLast = ptrDelete;
    }
    delete tempLast;
    anotherPtr->setNext(nullptr);
    last = anotherPtr;

    count = otherCookieList.count;

}

void CookieList::copyCallingObjShorter(const CookieList& otherCookieList)
{
    Node * paramPtr = otherCookieList.first;
    Node * callingPtr = first;

    callingPtr->setCookie(paramPtr->getCookie());
    paramPtr = paramPtr->getNext();
    callingPtr = callingPtr->getNext();

    while (callingPtr != nullptr)
    {
        callingPtr->setCookie(paramPtr->getCookie());
        paramPtr = paramPtr->getNext();
        callingPtr = callingPtr->getNext();
    }

    while (paramPtr != nullptr)
    {
        addCookie(paramPtr->getCookie());
        paramPtr = paramPtr->getNext();
    }
    count = otherCookieList.count;
}

// added function from part c
Node * CookieList::getCookieLocation(size_t selection) const
{
    size_t i = 1;
    Node * ptr = first;
    while (i < selection)
    {
        ptr = ptr->getNext();
        ++i;
    }
    return ptr;
}




#include <set>
#include <vector>
#include <string>

#include "Cookie.h"

using namespace std;


Cookie::Cookie(const string& cookieName, size_t cookieCalories,
        const set<string>& ingredients, size_t servings)
        : CookieType(cookieName, cookieCalories)
        {
            ingredientsList = ingredients;
            numOfServings = servings;
        }

//accessor
size_t Cookie::getServings() const
{
    return numOfServings;
}

set<string> Cookie::getIngredients()
{
    return ingredientsList;
}

const Cookie& Cookie::getCookie() const
{
    return *this;
}

//mutator
void Cookie::setServings(size_t servingSize)
{
    numOfServings = servingSize;
}

void Cookie::setIngredients(const vector<string>& listOfIngredients)
{
    int vectorSize = static_cast<int>(listOfIngredients.size());
    ingredientsList.clear();
    for (int i = 0; i < vectorSize; ++i)
        ingredientsList.insert(listOfIngredients[i]);
}

void Cookie::printRecipe() const
{
    cout << "    Recipe for " << getName()
        << endl << "        Servings: "
        << numOfServings << endl;
}

void Cookie::printIngredients() const
{
    cout << "        Ingredients: ";

    auto iter = ingredientsList.begin();
    cout << endl << "           * " << *iter << endl;
    ++iter;

    auto iterEnd = ingredientsList.end();

    for (iter; iter != iterEnd; ++iter)
    {
        cout << "           * " << *iter << endl;
    }
}

void Cookie::printCalories() const
{
    cout << "    " << getName()
        << " " << "(calories: "
        << getCalories() << ")" << endl;
}




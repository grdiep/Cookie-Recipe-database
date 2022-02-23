#ifndef COOKIE_H
#define COOKIE_H

#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "CookieType.cpp"

class Cookie : public CookieType
{
public:

    Cookie() : numOfServings(0) {}
    Cookie(const std::string& cookieName, size_t cookieCalories,
        const std::set<std::string>& ingredients, size_t servings);

    //accessor
    size_t getServings() const;
    std::set<std::string> getIngredients();
    const Cookie& getCookie() const;

    //mutator
    void setServings(size_t servingSize);
    void setIngredients(const std::vector<std::string>&
                            listOfIngredients);

    //print
    void printRecipe() const;
    void printIngredients() const;
    void printCalories() const;

    ~Cookie() {}

private:
    std::set<std::string> ingredientsList;
    size_t numOfServings;
};

#endif

//storing cookie data (name, calories, serving count, ingredients) into a set and methods to access data
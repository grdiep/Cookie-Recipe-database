#include "CookieDB.h"

#include <iostream>
using namespace std;

void getData(std::string& newName, size_t& newCalories,
	std::set<std::string>& newIngredients, size_t& newServings,
	size_t idx)
{
	vector<string> names = {
		"Lemon Square Bars",
		"Biscotti",
		"Nutella Brownies",
		"Butter Snow Flakes",
		"Chocolate Chip Cookies",
		"Oatmeal Cookies",
		"Walnut Tassies",
		"Jam Thumbprints",
		"Gingersnaps",
		"Meringues",
		"Pizzelles",
		"Snickerdoodle",
	};

	vector<size_t> calories = {
		136, 104, 204, 105,
		183, 128, 159, 126,
		121, 62, 102, 120,
	};

	// More than one prerquisite: AND
	vector<set<string>> ingredients = {
		// Lemon Square Bars
		{ "2 cups of flour", "1 cup of sugar", "1 cup of butter", "4 large eggs", "5/8 cup of lemon juice" },
		// Biscotti
		{ "3 1/2 cup of flour", "1/2 cup of vegetable oil", "1 cup of sugar", "3 eggs", "1 tbsp of almonds" },
		//Nutella Brownies
		{ "1 cup of Nutella", "1/2 cup of flour", "1 tsp of vanilla", "1/2 cup of chocolate chips" },
		//Butter Snow Flakes
		{  "1/4 tsp of cinnamon", "1 cup of butter", "2 cups of flour", "3 oz of cream cheese", "1 cup of sugar", "1 egg yolk", "1 tsp of vanilla" },
		//Chocolate Chip Cookies
		{ "1 cup of butter", "1 cup of sugar", "2 eggs", "1 tbsp of applesauce", "2 tsp of vanilla", "3 cups of flour", "1/2 tsp of cinnamon" },
		//Oatmeal Cookies
		{  "1 cup of butter", "1 cup of sugar", "2 eggs", "1 tsp of vanilla", "2 cups of flour", "3 cups of oats chips" },
		//Walnut Tassies
		{ "1 1/2 cup of brown sugar", "1 cup of walnuts", "3/4 lb of butter", "3 eggs", "2 tsp of vanilla", "6 oz of cream cheese", "2 cups of flour" },
		//Jam Thumbprints
		{  "1/2 cup of butter", "1/4 cup of sugar", "1 egg", "1/2 tsp of vanilla", "1 cup of flour", "1/4 cup of walnuts", "2/3 cup of strawberry jam" },
		//Gingersnap Cookies
		{ "2 cups of flour", "1 tbsp of ginger", "1 tsp of cinnamon", "1/3 cup of sugar", "1/4 cup of molasses", "2 tsp of baking soda" },
		//Meringue Cookies
		{ "2 egg whites", "3/4 cup sugar", "1 tsp vanilla", "1 cup semisweet chocolate chips", "1/8 tsp cream tartar", "1/3 cup peanuts" },
		//Pizzelles
		{  "3/4 cup of sugar", "1 tbsp vanilla extract", "1/2 cup butter", "1 3/4 cup flour", "2 tsp baking powder" },
		//Snickerdoodle
		{ "1 1/2 cup sugar", "1/2 cup butter", "2 3/4 cup flour", "2 tsp cream of tartar", "2 tsp ground cinnamon" },
	};

	vector<size_t> servings = {
		32, 36, 16, 36,
		16, 36, 36, 24,
		30, 36, 24, 36,
	};

	newName = names[idx];
	newCalories = calories[idx];
	newIngredients = ingredients[idx];
	newServings = servings[idx];
}

//cookie database
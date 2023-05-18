#include <iostream>
#include "PizzaClass.h"
using namespace std;

int main() {
    // Create an instance of PizzaBoom
    PizzaBoom pizzeria;

    // Add pizzas to the menu
    pizzeria.addPizzaToMenu("Mexican", "12 inch");
    pizzeria.addPizzaToMenu("Mexican", "6 inch");
    pizzeria.addPizzaToMenu("Vegetarian", "5 inch");

    // Sell pizzas
    pizzeria.sellPizza("Mexican", "12 inch", 345);
    pizzeria.sellPizza("Mexican", "6 inch", 187);
    pizzeria.sellPizza("Vegetarian", "5 inch", 59);

    // Log sales to a file
    pizzeria.logSales();

    // Display sales from the file
    pizzeria.displaySalesFromFile();

    // Store menu in an object file
    pizzeria.storeInObjectFile();

    // Display pizzas from the object file with size greater than 5
    pizzeria.displayMenuBySizeFromFile(5);

    return 0;
}

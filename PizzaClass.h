#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class PizzaBoom {
private:
    class Pizza {
    private:
        string variety;
        string size;

    public:
        Pizza(const string& var, const string& sze) : variety(var), size(sze) {}

        string getVariety() const {
            return variety;
        }

        string getSize() const {
            return size;
        }
    };

    vector<Pizza> menu;
    vector<int> quantitySold;

public:
    void addPizzaToMenu(const string& var, const string& sze) {
        Pizza pizza(var, sze);
        menu.push_back(pizza);
        quantitySold.push_back(0);
    }

    void sellPizza(const string& var, const string& sze, int nbSold) {
        int index = findPizzaIndex(var, sze);
        if (index != -1) {
            quantitySold[index] += nbSold;
        }
    }

    void logSales() {
        ofstream file("sales.txt");
        if (file.is_open()) {
            for (size_t i = 0; i < menu.size(); ++i) {
                file << menu[i].getVariety() << " " << menu[i].getSize() << " "
                     << quantitySold[i] << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file for logging sales." << endl;
        }
    }

    void displaySalesFromFile() {
        ifstream file("sales.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open sales file for display." << endl;
        }
    }

    void storeInObjectFile() {
        ofstream file("menu.dat", ios::binary);
        if (file.is_open()) {
            for (const Pizza& pizza : menu) {
                file.write(reinterpret_cast<const char*>(&pizza), sizeof(Pizza));
            }
            file.close();
        } else {
            cout << "Unable to open file for storing menu objects." << endl;
        }
    }

    void displayMenuBySizeFromFile(int minSize) {
        ifstream file("menu.dat", ios::binary);
        if (file.is_open()) {
            while (!file.eof()) {
                Pizza pizza("", "");
                file.read(reinterpret_cast<char*>(&pizza), sizeof(Pizza));
                if (pizza.getSize() > to_string(minSize)) {
                    cout << pizza.getVariety() << " " << pizza.getSize() << endl;
                }
            }
            file.close();
        } else {
            cout << "Unable to open menu file for display." << endl;
        }
    }

    int findPizzaIndex(const string& var, const string& sze) const {
        for (size_t i = 0; i < menu.size(); ++i) {
            if (menu[i].getVariety() == var && menu[i].getSize() == sze) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
};

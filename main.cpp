//
// Created by Maikol Guzman on 9/29/20.
//
#include <iostream>

/**
 * Building
 * Base class to construct buildings
 */
class Building
{
public:
    // Factory Method
    static Building *MakeBuilding(int choice);
    virtual std::string processMethod() = 0;
};

/**
 * Derive class for House
 * Inherited from Building
 */
class House: public Building {
public:
    std::string processMethod() override {
        return "Create a beautiful House";
    }
};

/**
 * Derive class for Castle
 * Inherited from Building
 */
class Castle: public Building {
public:
    std::string processMethod() override {
        return "Create a huge Castle";
    }
};

/**
 * Derive class for Farm
 * Inherited from Building
 */
class Farm: public Building {
public:
    std::string processMethod() override {
        return "Create a amazing Farm";
    }
};

/**
 * Definition of the Factory
 * @param choice of build
 * @return the corresponding instance
 */
Building *Building::MakeBuilding(int choice) {
    if (choice == 1)
        return new House;
    else if (choice == 2)
        return new Castle;
    else
        return new Farm;
}

/**
 * Main Class
 * @return
 */
int main() {
    std::cout << "Hello, Universidad Nacional!" << std::endl;

    Building* newHouse = Building::MakeBuilding(1);
    Building* newCastle = Building::MakeBuilding(2);
    Building* newFarm = Building::MakeBuilding(3);

    std::cout << newHouse->processMethod() << std::endl;
    std::cout << newCastle->processMethod() << std::endl;
    std::cout << newFarm->processMethod() << std::endl;

    return 0;
}


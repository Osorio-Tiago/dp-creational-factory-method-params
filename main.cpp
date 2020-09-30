//
// Created by Maikol Guzman on 9/29/20.
//
#include <iostream>
#include <utility>

/**
 * Enum with the type of element
 */
enum Buildings {
    HOUSE, CASTLE, FARM
};

/**
 * Base Spec Building
 */
struct BuildingSpec {
    virtual Buildings buildingType() const = 0;
};

/**
 * House Spec
 */
struct HouseSpec : public BuildingSpec {
    Buildings buildingType() const override { return HOUSE; }

    std::string houseName;

    explicit HouseSpec(std::string houseName) : houseName(std::move(houseName)) {}
};

/**
 * Farm Spec
 */
struct FarmSpec : public BuildingSpec {
    Buildings buildingType() const { return FARM; }

    bool withPasture;
    int numberOfStalls;

    FarmSpec(bool withPasture, int numberOfStalls) : withPasture(withPasture), numberOfStalls(numberOfStalls) {}
};

/**
 * Castle Spec
 */
struct CastleSpec : public BuildingSpec {
    Buildings buildingType() const { return CASTLE; }

    int size;

    explicit CastleSpec(int size) : size(size) {}
};

/**
 * Building
 * Base class to construct buildings
 */
class Building {
public:
    // Factory Method
    static Building *MakeBuilding(const BuildingSpec *buildingSpec);

    virtual std::string processMethod() = 0;
};

/**
 * Derive class for House
 * Inherited from Building
 */
class House : public Building {
private:
    std::string houseName;
public:
    explicit House(const HouseSpec *houseSpec) : houseName(houseSpec->houseName) {}

    std::string processMethod() override {
        return "Create a beautiful House NAME: " + houseName;
    }
};

/**
 * Derive class for Castle
 * Inherited from Building
 */
class Castle : public Building {
private:
    int size;

public:
    explicit Castle(const CastleSpec *castleSpec) : size(castleSpec->size) {}

    std::string processMethod() override {
        return "Create a huge Castle SIZE: " + std::to_string(size);
    }
};

/**
 * Derive class for Farm
 * Inherited from Building
 */
class Farm : public Building {
private:
    bool withPasture;
    int numberOfStalls;

public:
    explicit Farm(const FarmSpec *farmSpec) {
        withPasture = farmSpec->withPasture;
        numberOfStalls = farmSpec->numberOfStalls;
    }

    std::string processMethod() override {
        return "Create a amazing Farm WITH PASTURE: " + std::to_string(withPasture) +
               " NUMBER OF STALLS: " + std::to_string(numberOfStalls);
    }
};

/**
 * Definition of the Factory
 * @param choice of build
 * @return the corresponding instance
 */
Building *Building::MakeBuilding(const BuildingSpec *buildingSpec) {
    switch (buildingSpec->buildingType()) {
        case HOUSE:
            return new House(dynamic_cast<const HouseSpec *>(buildingSpec));
        case CASTLE:
            return new Castle(dynamic_cast<const CastleSpec *>(buildingSpec));
        case FARM:
            return new Farm(dynamic_cast<const FarmSpec *>(buildingSpec));
    }
}

/**
 * Main Class
 * @return
 */
int main() {
    std::cout << "Hello, Universidad Nacional!" << std::endl;

    BuildingSpec *houseSpec = new HouseSpec("Super House");
    BuildingSpec *castleSpec = new CastleSpec(100);
    BuildingSpec *farmSpec = new FarmSpec(true, 5);

    Building *newHouse = Building::MakeBuilding(houseSpec);
    Building *newCastle = Building::MakeBuilding(castleSpec);
    Building *newFarm = Building::MakeBuilding(farmSpec);

    std::cout << newHouse->processMethod() << std::endl;
    std::cout << newCastle->processMethod() << std::endl;
    std::cout << newFarm->processMethod() << std::endl;

    return 0;
}


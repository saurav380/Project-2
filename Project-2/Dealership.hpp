#ifndef DEALERSHIP_HPP
#define DEALRESHIP_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// Enumeration for car transmission types
enum class Transmission { AUTOMATIC, MANUAL };

//Structure representing a car;
struct Car {
	string make;
	string model;
	int year;
	double price;
	double mileage;
	Transmission transmission;
	bool isAvailable;
	string buyer;

	// Overload operator for easy printing of car details
	friend ostream& operator<<(ostream& os, const Car& car);

};

//Dealreship class that manages the car inventory

class Dealership {
private:
	vector<Car> inventory; //Vectors holding the lists of cars in inventory

public:
	void addCar(const Car& car);
	Car* getCarByIndex(int index);
	void sellCar(int carIndex, const string& name);
	void displayInventory() const;
	void saveInventory() const;
	void loadInventory();


};
#endif

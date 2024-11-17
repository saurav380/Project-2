#include "Dealership.hpp"
#include < fstream >
#include <algorithm>

// Overload operator for easy printing car details
ostream& operator <<(ostream& os, const Car& car) {
	os << "Make: " << car.make << ", Model: " << car.model << ", Year: " << car.year << ", Price: $" << car.price << "m Mileage: " << car.mileage << ", Transmission: " << (car.transmission == Transmission::AUTOMATIC ? "Automatic" : "Manual") << " , Available: " << (car.isAvailable ? "Yes" : "No");
	if (!car.buyer.empty()) {

	}
	return os;
}

//Adds a car to the dealership inventory 
void Dealership::addCar(const Car& car) {
	inventory.push_back(car);

}
// Retrieves a car by its index in the inventory
Car* Dealership::getCarByIndex(int index) {
	if (index >= 0 && index < inventory.size()) {
		return &inventory[index];
	}

		return nullptr;

	
}

// Sells a car to customer and marks it as unavailable
void Dealership::sellCar(int carIndex, const string& customerName) {
	if (carIndex < 0 || carIndex >= inventory.size()) {
		cout << "Invsslid car index.\n";
		return;
	}
	
	Car* car = &inventory[carIndex];
	if (car->isAvailable) {
		car->isAvailable = false;
		car->buyer = customerName;
		cout << "Car sold to " << customerName << ":\n" << *car << "\n";
	}
	else {
		cout << "Car is not available for sale. \n";

	}
}
// Dispalys all cars in the inventory, including availability status 
void Dealership::displayInventory() const {
	cout << "\nCurrent Inventory: \n";
	for (size_t i = 0; i < inventory.size(); i++) {
		cout << i + 1 << " . " << inventory[i].make << " " << inventory[i].model << "(" << (inventory[i].isAvailable ? "Available" : "Sold") << ")\n";
	}
}
//Saves the current inventory to a binary file
void Dealership::saveInventory() const {
	ofstream file("inventory.dat", ios::binary); 
	if (!file) {
		cerr << "Error opening filr for saving.\n";
		return;

	}
	for (const auto& car : inventory) {
		file.write(reinterpret_cast<const char*>(&car), sizeof(Car));

	}
	file.close();
}
//Loads the inventory from a binary file
void Dealership::loadInventory() {
	ifstream file("inventory.dat", ios::binary);
	if (!file) {
		cerr << "Error opening file for loading.\n";
		return;
	}
	Car car;
	while (file.read(reinterpret_cast<char*>(&car), sizeof(car))) {
		inventory.push_back(car);
	}
	file.close();
}


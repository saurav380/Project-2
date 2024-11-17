#include <iostream>
#include "Dealership.hpp"

using namespace std;

int main() {
	Dealership dealership;

	// Load inventory from file if ir exists

	dealership.loadInventory();

	// Add initial cars to the dealership inventory
	dealership.addCar({ "Toyota", "Camry", 2022, 30000, 15000, Transmission::AUTOMATIC, true, "" });
	dealership.addCar({ "Honda", "Civic", 2021, 25000, 12000, Transmission::MANUAL, true, "" });
	dealership.addCar({ "Ford", "Mustang", 2020, 45000, 5000, Transmission::AUTOMATIC, true, "" });
	dealership.addCar({ "Chevrolet", "Malibu", 2023, 27000, 1000, Transmission::MANUAL, true, "" });
	dealership.addCar({ "Nissan", "Altima", 2022, 32000, 8000, Transmission::AUTOMATIC, true, "" });

	string choice;

	while (true) {
		dealership.displayInventory();

		// Promp the user to either view details, sell, or exit
		cout << "\n Enter car number to view details, type 'sell' to sell the car, or exit to quit: ";
		getline(cin, choice);

		if (choice == "exit") {
			break;
		}
		else if (choice == "sell") {
			// If user wants tp sell a car, prompt for the car number
			cout << " Enter car number to sell: ";
			getline(cin, choice);
			try {
				int carNumber = stoi(choice) - 1;
				Car* car = dealership.getCarByIndex(carNumber);

				if (car && car->isAvailable) {
					// If the car is available, prompt for customer name and sell the car 
					cout << "Enter customer name to sell the car: ";
					string customerName;
					getline(cin, customerName);
					dealership.sellCar(carNumber, customerName);

				}
				else {
					cout << "Invalid or unavailable car.\n";

				}
			}
			catch (const exception& e) {
					cout << "Invalid car number. \n";
				}
			}
		else{
			// If the user wants to view car details, prompt for car number 
			try {
				int carNumber = stoi(choice) - 1;
				Car* car = dealership.getCarByIndex(carNumber);

				if (car) {
					cout << "\n Car details:\n" << *car << "\n";

				}
				else {
					cout << "Invalid car number.\n";
				}
			}
			catch (const exception& e) {
				cout << "Invalid input. Please enter a valid car number. \n";
			}

		}

		}
		// Save the inventory to a file before exiting
		dealership.saveInventory();

		return 0;
	}

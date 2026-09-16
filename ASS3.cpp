#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string vehicleNumber;
    string vehicleName;
    double distance;
    double fuelConsumed;
    double lastServiceKm;

public:
    Vehicle() {
        vehicleNumber = "";
        vehicleName = "";
        distance = 0;
        fuelConsumed = 0;
        lastServiceKm = 0;
    }

    void accept() {
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNumber;
        cout << "Enter Vehicle Name: ";
        cin >> vehicleName;
        cout << "Enter Distance Travelled (km): ";
        cin >> distance;
        cout << "Enter Fuel Consumed (litres): ";
        cin >> fuelConsumed;
        cout << "Enter Last Service Distance (km): ";
        cin >> lastServiceKm;
    }

    void display() const {
        cout << "\n--- Vehicle Details ---\n";
        cout << "Vehicle Number: " << vehicleNumber << endl;
        cout << "Vehicle Name: " << vehicleName << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Fuel Consumed: " << fuelConsumed << " litres" << endl;
        cout << "Fuel Efficiency: " << calculateEfficiency() << " km/l" << endl;
    }

    double calculateEfficiency() const {
        if (fuelConsumed == 0)
            return 0;
        return distance / fuelConsumed;
    }

    void updateDistance(double extraDistance) {
        distance += extraDistance;
    }

    void updateFuel(double extraFuel) {
        fuelConsumed += extraFuel;
    }

    void checkMaintenance() const {
        if (distance - lastServiceKm >= 5000)
            cout << "Maintenance Required." << endl;
        else
            cout << "Maintenance Not Required." << endl;
    }

    void compare(const Vehicle &v) const {
        double e1 = calculateEfficiency();
        double e2 = v.calculateEfficiency();

        if (e1 > e2)
            cout << vehicleName << " has better fuel efficiency." << endl;
        else if (e2 > e1)
            cout << v.vehicleName << " has better fuel efficiency." << endl;
        else
            cout << "Both vehicles have the same fuel efficiency." << endl;
    }
};

int main() {
    Vehicle v1, v2;

    cout << "Enter details of Vehicle 1:\n";
    v1.accept();

    cout << "\nEnter details of Vehicle 2:\n";
    v2.accept();

    cout << "\nVehicle 1:" << endl;
    v1.display();
    v1.checkMaintenance();

    cout << "\nVehicle 2:" << endl;
    v2.display();
    v2.checkMaintenance();

    cout << "\nComparison:\n";
    v1.compare(v2);

    return 0;
}

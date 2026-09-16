#include <iostream>
using namespace std;

class Hotel {
private:
    int rooms[5][5];

public:
    Hotel() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                rooms[i][j] = 0;
            }
        }
    }

    void displayRooms() const {
        cout << "\nRoom Status (0 = Available, 1 = Booked)\n";
        for (int i = 0; i < 5; i++) {
            cout << "Floor " << i + 1 << ": ";
            for (int j = 0; j < 5; j++) {
                cout << "Room " << j + 1 << "=" << rooms[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void bookRoom() {
        int floor, room;
        cout << "Enter floor number (1-5): ";
        cin >> floor;
        cout << "Enter room number (1-5): ";
        cin >> room;

        if (floor < 1 || floor > 5 || room < 1 || room > 5) {
            cout << "Invalid floor or room number." << endl;
            return;
        }

        if (rooms[floor - 1][room - 1] == 0) {
            rooms[floor - 1][room - 1] = 1;
            cout << "Room booked successfully." << endl;
        } else {
            cout << "Room is already booked." << endl;
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n--- Hotel Room Booking ---\n";
            cout << "1. View Rooms\n";
            cout << "2. Book Room\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                displayRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
            }
        } while (choice != 3);
    }
};

int main() {
    Hotel hotel;
    hotel.menu();
    return 0;
}

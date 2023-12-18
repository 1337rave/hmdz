#include "Header.h"

int main() {
    int choice;

    do {
        std::cout << "Menu:\n"
            << "1. Add Reservoir\n"
            << "2. Remove Reservoir\n"
            << "3. Display All Reservoirs\n"
            << "4. Write to Text File\n"
            << "5. Write to Binary File\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addObject();
            break;
        case 2:
            removeObject();
            break;
        case 3:
            displayAll();
            break;
        case 4:
            writeToFileText("reservoirs.txt");
            break;
        case 5:
            writeToFileBinary("reservoirs.bin");
            break;
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

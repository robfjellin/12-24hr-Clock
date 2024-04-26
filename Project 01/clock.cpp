#include <iostream>
#include "time_functions.h"

using namespace std;

// Display menu options
void displayMenu() {
    cout << "1- Add One Hour" << endl;
    cout << "2- Add One Minute" << endl;
    cout << "3- Add One Second" << endl;
    cout << "4- Exit Program" << endl;
}

// Main program loop and user interactions
void mainMenu() {
    int userChoice;
    bool continueLoop = true; // Controls if loop is active
    
    while (continueLoop) {
        displayMenu(); // Show menu
        cin >> userChoice; // Take users input
        
        // Processes users input
        switch (userChoice) {
            case 1:
                cout << "hour" << endl;
                addOneHour(); // Increment hour
                printTime(); // Prints updated time
                break;
            case 2:
                cout << "minute" << endl;
                addOneMinute(); // Increment minute
                printTime();
                break;
            case 3:
                cout << "second" << endl;
                addOneSecond(); // Increment second
                printTime();
                break;
            case 4:
                continueLoop = false; // Exits loop if user opts to exit program
                cout << "Goodbye." << endl;
                break;
        }
    }
    
}

int main() {
    timeInTake(); // Get initial time from users input
    mainMenu(); // Initiate main menu loop
    return 0; 
}

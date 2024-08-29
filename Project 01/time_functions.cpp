#include "time_functions.h"

// Global variables to hold users time
int currentHour;
int currentMilHour;
int currentMinute;
int currentSecond;

int validateUserInput(int max, string prompt) {
    int value;
    while (true) {
        cout << prompt << endl;
        cin >> value;
        if (cin.fail() || value < 0 || value > max) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');2
        } else {
            break;
        }
    }
    return value;
}

// Formats number as 2 digits if it isn't already
string twoDigitString(const unsigned int n) {
    string twoDigit;
    if (n >= 0 && n <= 9) {
        twoDigit = "0" + to_string(n);
    }
    else {
        twoDigit = to_string(n);
    }
    return twoDigit;
}

// Format to military time
string formatTime24(int h, int m, int s) {
    string militaryTime = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
    return militaryTime;
}

// Format to 12-hour time
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    int hour;
    string amOrPm;

    if (h > 11) {
        hour = h - 12;
        amOrPm = " P M";
    }
    else {
        hour = h;
        amOrPm = " A M";
    }
    if (hour == 0) {
        hour = 12;
    }
    return (twoDigitString(hour) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + amOrPm);
}

// Displays both 12-hour and military time
void printTime() {
    cout << "**************************************" << endl;
    cout << "* 12-Hour Clock" << "   |   " << "24-Hour Clock  *" << endl;
    cout << "*------------------------------------*" << endl;
    cout << "* " << formatTime12(currentHour, currentMinute, currentSecond) << "    |   " << formatTime24(currentHour, currentMinute, currentSecond) << "       *" << endl;
    cout << "**************************************" << endl;
}

// Takes initial time from user
void timeInTake() {

    currentHour = validateUserInput(23, "Please enter an hour (0-23).");
    currentMinute = validateUserInput(59, "Please enter a minute (0-59).");
    currentSecond = validateUserInput(59, "Please enter a second (0-59).");

    printTime();
}

// Adds one hour to current time
void addOneHour() {
    currentHour += 1;
    if (currentHour > 23) {
        currentHour -= 24;
    }
    currentMilHour = currentHour;
}

// Adds one minute to current time
void addOneMinute() {
    currentMinute += 1;
    if (currentMinute > 59) {
        currentMinute -= 60;
        addOneHour();
    }
}

// Adds one second to current time
void addOneSecond() {
    currentSecond += 1;
    if (currentSecond > 59) {
        currentSecond -= 60;
        addOneMinute();
    }
}


#include "time_functions.h"

// Global variables to hold users time
int globalHour;
int globalMilHour;
int globalMinute;
int globalSecond;

// Formats number as 2 digits if it isn't already
string twoDigitString(unsigned int n) {
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
    string militaryTime;

    militaryTime = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
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
    cout << "* " << formatTime12(globalHour, globalMinute, globalSecond) << "    |   " << formatTime24(globalHour, globalMinute, globalSecond) << "       *" << endl;
    cout << "**************************************" << endl;
}

// Takes initial time from user
void timeInTake() {
    cout << "Please enter an hour (0-23)." << endl;
    cin >> globalHour;
    cout << "Please enter a minute (0-59)." << endl;
    cin >> globalMinute;
    cout << "Please enter a second (0-59)." << endl;
    cin >> globalSecond;
    cout << "";

    printTime();
}

// Adds one hour to current time
void addOneHour() {
    globalHour += 1;
    if (globalHour > 23) {
        globalHour -= 24;
    }
    globalMilHour = globalHour;
}

// Adds one minute to current time
void addOneMinute() {
    globalMinute += 1;
    if (globalMinute > 59) {
        globalMinute -= 60;
        addOneHour();
    }
}

// Adds one second to current time
void addOneSecond() {
    globalSecond += 1;
    if (globalSecond > 59) {
        globalSecond -= 60;
        addOneMinute();
    }
}


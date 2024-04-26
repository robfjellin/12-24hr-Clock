#ifndef TIME_FUNCTIONS_H  // Header guard
#define TIME_FUNCTIONS_H
#include <string>
#include <iostream>

using namespace std;

// Created by: Robert Fjellin

// Formats number to 2 digits
string twoDigitString(unsigned int n);

// Formats time to military time
string formatTime24(int h, int m, int s);

//Formats time to 12-hour time with AM or PM
string formatTime12(unsigned int h, unsigned int m, unsigned int s);

// Takes current time from user
void timeInTake();

// Prints both 12-hour and military time
void printTime();

// Respectively increments time by 1
void addOneHour();
void addOneSecond();
void addOneMinute();

#endif
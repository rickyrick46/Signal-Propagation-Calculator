// Signal Propagation Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SPC_1.h"

int main()
{
    int selector = 0;       // create main menu function

    cout << "1: Change Ground Station Position\n"
        << "2: View Ground Station Position\n"
        << "Enter: ";

    cin >> selector;
    cin.ignore();

    if (selector == 1) {
        changeStation();

    }
}



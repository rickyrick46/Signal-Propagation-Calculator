#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;

//Prototypes
void mainMenu();
void changeStation();
void viewStation();
bool isNoAlpha(const string& str, int size);
void azimuthTx(short initialAzimuth = 0);


void azimuthTx(short initialAzimuth) {
	short azimuth = initialAzimuth;

	cout << "Antenna Azimuth (Use UP and DOWN arrow keys): \n";		

	while (true) {

		if (_kbhit()) {
			int ch = _getch();
			if (ch == 0 || ch == 224) {
				int arrow = _getch();
				if (arrow == 72) {
					azimuth += 5;
				}
				else if (arrow == 80) {
					azimuth -= 5;
				}

				if (azimuth >= 360)
					azimuth -= 360;

				if (azimuth < 0)
					azimuth += 360;

				cout << "\rAzimuth: " << azimuth << "   " << flush;
			}

		else if (ch == '\r')
				break;

		}

		


	}

}





void viewStation() {
	string latLongiAlt;
	

	ifstream file("ground_station.csv");

	if (!file.is_open())
		cout << "ERROR - FILE NOT FOUND";
	
	getline(file, latLongiAlt);

	getline(file, latLongiAlt, ',');
		cout << "Latitude: " << latLongiAlt << endl;
		
	getline(file, latLongiAlt, ',');
		cout << "Longitude: " << latLongiAlt << endl;

	getline(file, latLongiAlt);
		cout << "Altitude: " << latLongiAlt << endl;

		

	file.close();

	mainMenu();

}


bool isNoAlpha(const string& str, int size) {

	for (int i = 0; i < size; i++) {
		if (isalpha(str[i]))
			return false;
	}

	return true;
}


void changeStation() {
	string lat;
	string longi;
	string alt;
	ofstream file("ground_station.csv");
		
	if (!file.is_open()) 
		"ERROR - FILE NOT FOUND";

	while (true) {
		cout << "Enter Latitude: ";
		getline(cin, lat);

		if (isNoAlpha(lat, lat.size()) == true) {
			break;
		}
		else {
			cout << "USE NUMERICAL DIGITS\n";
		}
	}
		
		
	
	while (true) {
		cout << "Enter Longitude: ";
		getline(cin, longi);

		if (isNoAlpha(longi, longi.size()) == true) {
			break;
		}
		else {
			cout << "USE NUMERICAL DIGITS\n";
		}

	}

	while (true) {
		cout << "Enter Altitude: ";
		getline(cin, alt);

		if (isNoAlpha(alt, alt.size()) == true) {			
			break;
		}
		else {
			cout << "USE NUMERICAL DIGITS\n";
		}

	}

		file << "latitude,longitude,altitude\n" <<
		 lat << ',' << longi << ',' << alt;
									 
	

		file.close();

		cout << "Ground Station Changed!\n"				
			<< "Latitude: " << lat << endl
			<< "Longitude: " << longi << endl
			<< "Altitude: " << alt;
			
		
		mainMenu();
		
			
}


void mainMenu() {
	cout << endl << endl << setw(15) << setfill('*') << "*\n\n";

	int selector = 0;       

	cout << "1: Change Ground Station Position\n"
		<< "2: View Ground Station Position\n"
		<< "3: Azimuth / Tx Controller\n"
		<< "Enter: ";

	cin >> selector;
	cin.ignore();

	if (selector == 1)
		changeStation();

	if (selector == 2)
		viewStation();

	if (selector == 3)
		azimuthTx();
		
}



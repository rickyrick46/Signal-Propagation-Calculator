#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//PROTOTYPES
bool isNoNumber(string str, int size);


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

		if (isNoNumber(lat, lat.size()) == true) {
			break;
		}
		else {
			cout << "USE NUMERICAL DIGITS\n";
		}
	}
		
		
	
	while (true) {
		cout << "Enter Longitude: ";
		getline(cin, longi);

		if (isNoNumber(longi, longi.size()) == true) {
			break;
		}
		else {
			cout << "USE NUMERICAL DIGITS\n";
		}

	}

	while (true) {
		cout << "Enter Altitude: ";
		getline(cin, alt);

		if (isNoNumber(alt, alt.size()) == true) {
			break;
		}
		else {
			cout << "USE NUMERICAL DIGITS\n";
		}

	}

		file << "latitude,longitude,altitude\n" <<
		 lat << longi << alt;
									 
	

		file.close();

		cout << "Ground Station Changed!\n"
			 << "Latitude: " << lat << endl
			 << "Longitude: " << longi << endl
			 << "Altitude: " << alt;

}



bool isNoNumber(string str, int size ) {

	for (int i = 0; i < size; i++) {
		if (isalpha(str[i]))
			return false;
	}

	return true;

}
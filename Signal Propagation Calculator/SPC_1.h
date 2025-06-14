#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
using namespace std;

short az = 0;

//Prototypes
void mainMenu();
void changeStation();
void viewStation();
bool isNoAlpha(const string& str, size_t size);
short azimuth(short initialAzimuth = 0);
void establishLink(short az, bool initialTxPwr = 0);
void centerText(const string& text, int width);







struct Aircraft {
	string acftName = "";
	short azimuth = 0;



};


extern Aircraft rq4;
extern Aircraft mq9;





void centerText(const string& text, int width) {
	
	

	cout << "\n";
	int pad = (width - text.size()) / 2;
		
		if (pad < 0)
			pad = 0;

		cout << string(pad, ' ') << text << endl;

		



}


void establishLink(short az, bool initialTxPwr) {
	bool txPwr = initialTxPwr;
	
	cout << "Press 1 to turn on Tx Power\n";
	
	cout << "Tx Power: " << boolalpha << txPwr;		//maybe use a terneary operator to make this say "ON" or "OFF"

	while (true) {
		if (_kbhit()) {
			int ch = _getch();
			
			if (ch == '1')
				txPwr = true;

			else if (ch == '0')
				txPwr = false;

			else if (ch == '\r')
				break;

			cout << "\rTx Power: " << boolalpha << txPwr << " " << flush;
		}


	}



	if (txPwr == true)
		cout << "\nPress '/' To Send Command Link\n"; 
	
	while (true) {
		
		if (_kbhit()) {
			int ch = _getch();
			if (ch == '/')
				if (az == rq4.azimuth || az == mq9.azimuth) {
					centerText("LINK AQUIRED", 55);

				}

			}
	}

}


short azimuth(short initialAzimuth) {
	short azimuth = initialAzimuth;

	cout << "Antenna Azimuth (Use UP and DOWN arrow keys): " << setw(3) << azimuth << flush;	//need to adjust "*"	

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

				cout << "\rAntenna Azimuth (Use UP and DOWN arrow keys): " << setw(3) << azimuth << flush;
			}

		else if (ch == '\r')
				break;

		}

	}

	cout << "\n";
	centerText("AZIMUTH CHANGED", 55);
	return azimuth;

	

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


bool isNoAlpha(const string& str, size_t size) {

	for (int i = 0; i < size; i++) {
		if (isalpha(str[i]))
			return false;
	}

	return true;
}


void changeStation() {
	
	
	cout << "\n";
	
	
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

		centerText("GROUND STATION CHANGED", 55);
			
		
		mainMenu();
		
			
}


void mainMenu() {
	
	centerText("Main Menu", 55);


	int selector = 0;       
	
	cout << "\n1: Change Ground Station Position\n"
		<< "2: View Ground Station Position\n"
		<< "3: Azimuth Controller\n"
		<< "4: Establish Link\n\n"
		<< "Enter: ";

	cin >> selector;
	cin.ignore();

	if (selector == 1)
		changeStation();

	else if (selector == 2)
		viewStation();

	else if (selector == 3) {
		az = azimuth();
		mainMenu();
	}

	else if (selector == 4)
		establishLink(az, 0);


}



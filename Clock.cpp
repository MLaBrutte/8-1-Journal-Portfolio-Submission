//Michael LaBrutte
//CS-210
//Project One
//28 Jan 2024

#include <iostream>

using namespace std;

int sec = 0;
int minute = 0;
int hr = 12;
int hr24 = 0;
int menuInput;
bool exitChecker = true;
int i = 0;

//Displays time for 12-hr & 24-hr.
void printTime() {
	cout << "***************************  ***************************" << endl;
	cout << "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
	cout << "*       "; if (hr < 10) cout << "0"; cout << hr << ":"; if (minute < 10) cout << "0"; cout << minute << ":"; if (sec < 10) cout << "0"; cout << sec << " "; if (i == 0)cout << "AM"; else if (i == 1)cout << "PM"; cout << "       *  *        "; if (hr24 < 10) cout << "0"; cout << hr24 << ":"; if (minute < 10) cout << "0"; cout << minute << ":"; if (sec < 10) cout << "0"; cout << sec << " "; if (i == 0)cout << "AM"; else if (i == 1)cout << "PM"; cout << "      *" << endl;
	cout << "***************************  ***************************" << endl;
}

//Provides prompt for inputs.
void displayMenu() {

	cout << "***************************\n";
	cout << "* 1 - Add One Hour        *\n";
	cout << "* 2 - Add One Minute      *\n";
	cout << "* 3 - Add One Second      *\n";
	cout << "* 4 - Exit Program        *\n";
	cout << "***************************\n";
}

//Setting the cases for the input to display for hr and hr24.
void menuAction() {
	switch (menuInput) {
	case 1:
		hr24++;
		hr++;
		if (hr24 == 24) {
			hr24 = 0;
		}
		if (hr24 < 12) {
			i = 0;
		}
		if (hr == 13) {
			hr = 1;
		}
		if (hr24 >= 12) {
			i = 1;
		}
		break;
	case 2:
		minute++;
		if (minute == 60) {
			hr++;
			hr24++;
			minute = 0;
			if (hr24 < 12) {
				i = 0;
			}
			if (hr24 >= 12) {
				i = 1;
			}
			if (hr == 13) {
				hr = 1;
			}
			if (hr24 == 24) {
				hr24 = 0;
			}
		}
		break;
	case 3:
		sec++;
		if (sec == 60) {
			minute++;
			sec = 0;
			if (minute == 60) {
				hr++;
				hr24++;
				minute = 0;
				if (hr24 < 12) {
					i = 0;
				}
				if (hr == 13) {
					hr = 1;
				}
				if (hr24 >= 12) {
					i = 1;
				}
				if (hr24 == 24) {
					hr24 = 0;
				}
			}
		}
		break;
	case 4:
		cout << "GoodBye!!" << endl;
		exitChecker = false;
		break;
	default:
		cout << "Invalid Input. Please Enter From 1 Through 4." << endl;
	}

}

//Takes the input from the user for hours, minutes, seconds and time period.
int main() {

	cout << "Enter initial hour (1-12): ";
	cin >> hr;
	hr24 = hr; //Stores input for hrs into hr24.

	cout << "Enter initial minute (0-59): ";
	cin >> minute;

	cout << "Enter initial second (0-59): ";
	cin >> sec;

	cout << "Enter initial time period (0 for AM, 1 for PM): ";
	cin >> i;

//Displays information.
	while (exitChecker) {

		printTime();
		displayMenu();
		cin >> menuInput;
		menuAction();
	}
	return 0;
}
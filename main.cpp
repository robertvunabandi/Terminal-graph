#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h> //for sleep
#include <unistd.h> //for sleep
#include <sys/ioctl.h>
// #include <windows.h> //for colors
using namespace std;

int isNumber(string str){
	/*
	INPUT TYPE: string
	OUTPUT:
	1 // returns 1 is str is a number
	0 // returns 0 is str is not a number
	*/
	bool result = true;
	char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for (int x = 0; x < str.length(); x++){
		if (str[x] == '.' || str[x] == '-') continue; //in case decimal numbers.
		for (int y = 0; y < 10; y++){
			if (digits[y] == str[x]) break;
			else if (y == 9) {
				result = false;
			}
		}
	}
	return result;
} //if str is number, returns 1, else returns 0
long double maximum(long double array[]){
	/*
	INPUT: array of numbers
	OUTPUT: highest value of array
	*/
	int length = 40; //for our purposes, the length of array is 40
	long double result = 0;
	for (int x = 0; x < length; x++){
		if (array[x] > result) result = array[x];
	}
	return result;
} //returns highest value in array

int main(){
	cout << "================================================================================" << endl; 
	cout << "WELCOME TO TERMINAL GRAPH V1.2.5" << endl; 
	cout << "================================================================================" << endl << endl;
	cout << "PLEASE, expand the width of your console/terminal window so that the lines (the equal signs) above take each only one line." << endl;
	usleep(750000);
	struct winsize w;
	while (w.ws_col < 80){
		ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);
		// string out = "\033[1;44mwidth of "+&w.ws_col+" is too low.\033[0m";
		// else cout << out << endl;
		if (w.ws_col > 80) break;
		else cout << "\033[1;44mERROR:\033[0m width of " << w.ws_col << " is too low." << endl;
		usleep(750000);
	}
	cout << endl;
	bool response = true;
	while (response == true){
		string typeOfGraph;
		char type;
		cout << "What would you like to graph, a linear, quadratic, or cubic function?" << endl;
		while (typeOfGraph != "linear" || typeOfGraph != "quadratic" || typeOfGraph != "cubic") {
			cout << "Please respond with 'l' or 'linear', 'q' or 'quadratic', or 'c' or 'cubic'." << endl;
			cin >> typeOfGraph;
			if (typeOfGraph == "linear" || typeOfGraph == "l" || typeOfGraph == "L"){
				type = 'L';
				break;
			}
			if (typeOfGraph == "quadratic" || typeOfGraph == "q" || typeOfGraph == "Q"){
				type = 'Q';
				break;
			}
			if (typeOfGraph == "cubic" || typeOfGraph == "c" || typeOfGraph == "C") {
				type = 'C';
				break;
			}
		}
		usleep(500000);
		cout << endl;
		long double a = 0, b = 0, c = 0, d = 0;
		string input;
		switch (type){
			/*
			Since a,b,c,d are set to 0, it'll be easy to just use the same functions
			and not have different functions for linear, quadratic, or cubic.
			*/
			case 'L':
				cout << "LINEAR, aX + b" << endl;
				usleep(250000);
				cout << "type a:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				c = stof(input);
				usleep(250000);
				cout << "type b:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				d = stof(input);
				break;
			case 'Q':
				cout << "QUADRATIC, aX^2 + bX + c" << endl;
				usleep(250000);
				cout << "type a:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				b = stof(input);
				usleep(250000);
				cout << "type b:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				c = stof(input);
				usleep(250000);
				cout << "type c:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				d = stof(input);
				usleep(250000);
				break;
			case 'C':
				cout << "CUBIC, aX^3 + bX^2 + cX + d" << endl;
				usleep(250000);
				cout << "type a:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				a = stof(input);
				usleep(250000);
				cout << "type b:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				b = stof(input);
				usleep(250000);
				cout << "type c:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				c = stof(input);
				usleep(250000);
				cout << "type d:";
				cin >> input; while (isNumber(input) == 0){cout << "Please type a valid number: "; cin >> input;}
				d = stof(input);
				usleep(250000);
				break;
		}
		long double xValues[40], yValues[40];
		for (int i = 0; i < 40; i++){
			xValues[i] = i;
			yValues[i] = a*(i*i*i) + b*(i*i) + c*(i) + d;
		}
		cout << endl;
		cout << "The graph will be shown on a 40x40 grid showing the positive values of the graph. Would you like to see the graph in proportion to see all positive y- and x-values?" << endl;
		input = "ds"; //resets the input
		sleep(1);
		while (input != "Y" || input != "y" || input != "N" || input != "n"){
			cout << "Please respond with Y for \"YES\" or N for \"NO\""; 
			cin >> input;
			if (input == "Y" || input == "y" || input == "N" || input == "n") break;
		}
		int divider;
		if (input == "Y"){
			/*
			Takes the highest value and divides it by 40 as divider.
			If divider is > 1, then the highest value is lower than 40. therefore,
			no need to do anything.
			*/
			divider = maximum(yValues)/40;
			if (divider > 1){
				for (int i = 0; i < 40; i++){
					yValues[i] = yValues[i]/divider;
				}
			} else divider = 1;
		}
		cout << endl;
		// for (int x = 0; x < 39; x++){
		// 	cout << "XVAL:" << xValues[x] << "|YVAL:" << yValues[x] << endl;
		// }
		cout << "YOUR GRAPH WILL BE SHOWN IN 3 seconds." << endl;
		
		usleep(3000000);
		cout << endl << endl << endl;
		for (int x = 0; x < 41; x++){
			cout << "--";
		}
		cout << endl;
		usleep(70000);
		for (int y = 39; y >= 0; y--){
			/*
			Now here is the graphing part. SIMPLE CONCEPT.
			*/
			if (y < 10) cout << " " << y << " ";
			else cout << y << " ";
			for (int x = 0; x < 40; x++){
				bool yes = false;
				if (xValues[x] == x && (unsigned long long int)(yValues[x]) == y){
					yes = true;
				} else yes = false;
				if (yes){
					cout << "* ";
				}
				else cout << "  ";
			}
			cout << endl;
			usleep(70000);
		}
		for (int x = 0; x < 41; x++){
			if (x < 10) cout << " " << x;
			else cout << x;
		}
		cout << endl;
		for (int x = 0; x < 41; x++){
			cout << "--";
		}
		cout << endl;
		usleep(500000);
		cout << endl << endl << endl;
		cout << "Would you like to graph something else?" << endl;
		input = "fds"; //reset input
		while (input != "Y" || input != "y" || input != "N" || input != "n"){
			cout << "Please respond with Y for \"YES\" or N for \"NO\"" << endl; 
			cin >> input;
			if (input == "Y" || input == "y" || input == "N" || input == "n") break;
		}
		if (input == "Y" || input == "y") response = true;
		else break;
		cout << endl;
	}
	usleep(100000);
	cout << endl;
	usleep(250000);
	cout << "================================================================================" << endl;
	cout << "THANK YOU FOR USING TERMINAL GRAPH V1.2.5" << endl;
	cout << "================================================================================" << endl << endl;
	usleep(250000);
	return 0;
}

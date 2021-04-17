#include<iostream>
#include<stdio.h>
#include <string> 
using namespace std;

int roundd(double number)
{
	return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

string And(int s1 , int s2 , int s3 , int s4 , int l1 , int l2 , int l3 , int l4) {	
	string s = to_string(s1 && l1) + to_string(s2 && l2) + to_string(s3 && l3) + to_string(s4 && l4);
	return s;
}

string concat(int a, int b , int c , int d)
{
	string s1 = to_string(a);
	string s2 = to_string(b);
	string s3 = to_string(c);
	string s4 = to_string(d);
	string s = s1 + s2 + s3 + s4; 
	return s;
}

int* check_Coordinates(int xmin, int xmax, int ymin, int ymax , int x , int y) {
	int* arr = new int[4];
	if (y > ymax)
		arr[0] = 1;
	else 
		arr[0] = 0;
	if (y < ymin)
		arr[1] = 1;
	else 
		arr[1] = 0;
	if (x > xmax)
		arr[2] = 1;
	else
		arr[2] = 0;
	if (x < xmin)
		arr[3] = 1;
	else
		arr[3] = 0;
	return arr;
}

void Find_Ones(string s , int posx, int posy, int xmin, int xmax, int ymin, int ymax , double slope) {
	string *position = new string[2];
	double x=0, y=0;
	if (s[0] == '1')
		position[0] = "Top";
	else if (s[1] == '1')
		position[0] = "Bottom";
	if (s[2] == '1')
		position[1] = "Right";
	else if (s[3] == '1')
		position[1] = "Left";

	if (position[0] == "Bottom") {
		x = posx + (double)(1 /slope)*((double)ymin - (double)posy);
		cout << "With Round : ( " << roundd(x) << " , " << ymin << " )" << endl;
		cout << "Without Round : ( " << x << " , " << ymin << " )" << endl;
	}
	else if (position[0] == "Top") {
		x = posx + (double)(1 / slope) *((double)ymax - (double)posy);
		cout << "With Round : ( " << roundd(x) << " , " << ymax << " )" << endl;
		cout << "Without Round : ( " << x << " , " << ymax << " )" << endl;
	}
	else if (position[1] == "Right") {
		y = posy + (slope) *((double)xmax - (double)posx);
		cout << "With Round : ( " << xmax << " , " << roundd(y) << " )" << endl;
		cout << "Without Round : ( " << xmax << " , " << y << " )" << endl;
	}
	else if (position[1] == "Left") {
		y = posy + (slope) *((double)xmin - (double)posx);
		cout << "With Round : ( " << xmin << " , " << roundd(y) << " )" << endl;
		cout << "Without Round : ( " << xmin << " , " << y << " )" << endl;
	}
}


void main() {
	int startx, starty, endx, endy, xmin, xmax, ymin, ymax, choice = 0;
	double slope;
	int number1, number2;
	string Result, point1, point2;
	string *position;
	while (choice != 1) {
		cout << "Enter the window coordinates --> ";
		cin >> xmin >> xmax >> ymin >> ymax;
		cout << "Enter the starting point --> ";
		cin >> startx >> starty;
		cout << "Enter the ending point --> ";
		cin >> endx >> endy;

		int* arr1 = check_Coordinates(xmin, xmax, ymin, ymax, startx, starty);
		int* arr2 = check_Coordinates(xmin, xmax, ymin, ymax, endx, endy);
		point1 = concat(arr1[0], arr1[1], arr1[2], arr1[3]);
		point2 = concat(arr2[0], arr2[1], arr2[2], arr2[3]);
		if (point1 == "0000" && point2 == "0000") {
			cout << "Accepted";
		}
		else {
			Result = And(arr1[0], arr1[1], arr1[2], arr1[3], arr2[0], arr2[1], arr2[2], arr2[3]);
			if (Result != "0000") {
				cout << "Rejected";
			}
			else {
				slope = ((double)endy - (double)starty) / ((double)endx - (double)startx);
				if (point1 == "0000") {
					cout << "One Intersection" << endl << "Accepted ( " << startx << " , " << starty << " ) and " << endl;
					Find_Ones(point2, startx, starty, xmin, xmax, ymin, ymax, slope);
				}
				else if (point2 == "0000") {
					cout << "One Intersection" << "Accepted ( " << endx << " , " << endy << " ) and " << endl;
					Find_Ones(point1, startx, starty, xmin, xmax, ymin, ymax, slope);
				}
				else if (point1 != "0000" && point2 != "0000") {
					cout << "Two Intersections" << endl << "The first point : ";
					Find_Ones(point1, startx, starty, xmin, xmax, ymin, ymax, slope);
					cout << "The second point : ";
					Find_Ones(point2, startx, starty, xmin, xmax, ymin, ymax, slope);
				}
			}
		}
		cout << endl << "Enter 1 if you want to exit, 0 to continue --> ";
		cin >> choice;
	}
}

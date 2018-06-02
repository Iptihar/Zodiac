#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

bool validInput(string dob) {
	//	string month = dob[0] + dob[1];
	int month = stoi(dob.substr(0, 2));
	//	cout << month << endl;
	int day = stoi(dob.substr(3, 2));

	int year = stoi(dob.substr(6, 4));

	//	cout << month << " " << day << " "  << year << endl;
	if (month > 12) {
		return false;
	}
	if (month < 1) {
		return false;
	}
	if (month == 2 && day > 28){
		return false;
	}
	else if (month == 4 && day > 30) {
		return false;
	}
	else if (month == 6 && day > 30) {
		return false;
	}
	else if (month == 9 && day > 30) {
		return false;
	}
	else if (month == 11 && day > 30) {
		return false;
	}
	else if (day > 31){
		return false;
	}

	if (year > 3000 || year < 1970) {
		return false;
	}

	return true;
}

string getDay(int month, int day, int year) {

	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;
	mktime(timeinfo);

	string dayofweek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int dow = timeinfo->tm_wday;


	return dayofweek[dow];
}

string getZodiac(int month, int day) {
	if (month == 3 && day >= 21) {
		return "Aries";
	}
	if (month == 4 && day <= 19) {
		return "Aries";
	}
	if (month == 4 && day >= 20) {
		return "Taurus";
	}
	if (month == 5 && day <= 20) {
		return "Taurus";
	}
	if (month == 5 && day >= 21) {
		return "Gemini";
	}
	if (month == 6 && day <= 20) {
		return "Gemini";
	}
	if (month == 6 && day >= 21) {
		return "Cancer";
	}
	if (month == 7 && day <= 22) {
		return "Cancer";
	}
	if (month == 7 && day >= 23) {
		return "Leo";
	}
	if (month == 8 && day <= 22) {
		return "Leo";
	}
	if (month == 8 && day >= 23) {
		return "Virgo";
	}
	if (month == 9 && day <= 22) {
		return "Virgo";
	}
	if (month == 9 && day >= 23) {
		return "Libra";
	}
	if (month == 10 && day <= 22) {
		return "Libra";
	}
	if (month == 10 && day >= 23) {
		return "Scorpio";
	}
	if (month == 11 && day <= 21) {
		return "Scorpio";
	}
	if (month == 11 && day >= 22) {
		return "Sagittarius";
	}
	if (month == 12 && day <= 21) {
		return "Sagittarius";
	}
	if (month == 12 && day >= 22) {
		return "Capricorn";
	}
	if (month == 1 && day <= 19) {
		return "Capricorn";
	}
	if (month == 1 && day >= 20) {
		return "Aquarius";
	}
	if (month == 2 && day <= 18) {
		return "Aquarius";
	}
	if (month == 2 && day >= 19) {
		return "Pisces";
	}
	if (month == 3 && day <= 20) {
		return "Pisces";
	}
}

bool runTest() {

	// these should return properly, cause every input is valid.
	if (getZodiac(3, 30) != "Aries") {
		return false;
	}
	if (getZodiac(5, 5) != "Taurus") {
		return false;
	}
	if (getZodiac(5, 29) != "Gemini") {
		return false;
	}
	if (getZodiac(6, 22) != "Cancer") {
		return false;
	}
	if (getZodiac(7, 30) != "Leo") {
		return false;
	}
	if (getZodiac(8, 30) != "Virgo") {
		return false;
	}
	if (getZodiac(9, 30) != "Libra") {
		return false;
	}
	if (getZodiac(10, 30) != "Scorpio") {
		return false;
	}
	if (getZodiac(11, 30) != "Sagittarius") {
		return false;
	}
	if (getZodiac(12, 30) != "Capricorn") {
		return false;
	}
	if (getZodiac(1, 30) != "Aquarius") {
		return false;
	}
	if (getZodiac(2, 20) != "Pisces") {
		return false;
	}

	if (getDay(2, 5, 2018) != "Monday") {
		return false;
	}
	if (getDay(7, 20, 1972) != "Thursday") {
		return false;
	}
	if (getDay(11, 18, 2028) != "Saturday") {
		return false;
	}

	// this is invalid input and function is gonna return false and rejected;
	//if this accepted there is problem, otherwise no problem.

	if (validInput("13/20/2020")){
		return false;
	}

	//this should also failed cause month is not valid.
	if (validInput("00/20/2020")) {
		return false;
	}

	//this should also failed cause day is not valid.
	if (validInput("12/32/2020")) {
		return false;
	}

	//this should also failed cause day is not valid.
	if (validInput("11/31/2020")) {
		return false;
	}

	//this should also failed cause day is not valid.
	if (validInput("02/29/2020")) {
		return false;
	}

	//this should also failed cause year is not valid.
	if (validInput("02/27/1960")) {
		return false;
	}

	//this should also failed cause year is not valid.
	if (validInput("02/27/3018")) {
		return false;
	}


	return true;


	/*
	test case #1 user enter invalid data 13, 20, 2020, the month out of range.
	
	*/
}



int main() {

	if (runTest()){
		cout << "sucess" << endl;
	}
	else {
		cout << "failed" << endl;
		exit(1);
	}
	int counter = 0;
	string input = "";
	bool success = false;
	while (counter < 3) {
		cout << "please enter date of birth in (mm/dd/yyyy) format." << endl;
		cin >> input;
		if (validInput(input)){
			int month = stoi(input.substr(0, 2));
			//	cout << month << endl;
			int day = stoi(input.substr(3, 2));

			int year = stoi(input.substr(6, 4));
			success = true;
			cout << "day of week is " << getDay(month, day, year) << endl;
			cout << "Zodiac is " << getZodiac(month, day) << endl;
			break;
		}
		cout << "invalid input, expecting (mm/dd/yyyy) format." << endl;
		counter++;

	}
	if (!success) {
		cout << "input failed after 3 attemps, system exit.";
	}
	system("pause");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int time_in_second;
	int speed;
	// Define input variables

	int year;
	int day;
	int hour;
	int minute;
	int second;
	// Declare the unit conversion variables

	const int seconds_per_year = 31536000;
	const int seconds_per_day = 86400;
	const int seconds_per_hour = 3600;
	const int seconds_per_minute = 60;
	const int days_per_year = 365;
	const int hours_per_day = 24;
	const int hours_per_year = 8760;
	const int minutes_per_year = 525600;
	const int minutes_per_day = 1440;
	const int minutes_per_hour = 60;
	// Declare constants

	double distance;

	cout << "Please give me the time of travel in seconds. ";
	cin >> time_in_second;

	cout << "Please give me your speed in miles per hour. ";
	cin >> speed;
	// Get inputs from the user

	year = time_in_second / seconds_per_year;
	day = time_in_second / seconds_per_day - year * days_per_year;
	hour = time_in_second / seconds_per_hour - year * hours_per_year - day * hours_per_day;
	minute = time_in_second / seconds_per_minute - year * minutes_per_year - day * minutes_per_day - hour * minutes_per_hour;
	second = time_in_second - year * seconds_per_year - day * seconds_per_day - hour * seconds_per_hour - minute * seconds_per_minute;
	// Output calculations

	cout << "You have been travelling for: " << year << " years " << day << " days "
		<< hour << " hours " << minute << " minutes " << second << " seconds." << "\n";
	// Unit conversion output

	distance = (double)(time_in_second) / seconds_per_hour * speed;

	cout << "Your distance traveled is: " << distance << " miles." << "\n";

	system("pause");
	return 0;
}


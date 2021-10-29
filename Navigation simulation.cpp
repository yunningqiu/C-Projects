#include "ccc_win.h"
#include <string>

class House
{
public:
	House();
	House(int new_number, Point new_location);
	int get_number() const;
	Point get_location() const;
	void draw() const;

private:
	int number; 
	Point location;

};

House::House()
{
	number = 0;
	location = Point(0, 0);
}

House::House(int new_number, Point new_location)
{
	number = new_number;
	location = new_location;
}

int House::get_number() const
{
	return number;
}

Point House::get_location() const
{
	return location;
}

void House::draw() const
{
	Point start = location;
	
	Point topleft = start;
	topleft.move(0, 0.8);

	Point topright = topleft;
	topright.move(0.8, 0);
	
	Point bottomright = topright;
	bottomright.move(0, -0.8);
	
	Point roof = topleft;
	roof.move(0.4, 0.6);

	Line line1(start, topleft), line2(topleft, topright), line3(topright, bottomright), line4(bottomright, start),
		line5(topleft, roof), line6(roof, topright);

	cwin << line1 << line2 << line3 << line4 << line5 << line6 << Message(topleft, number);

	return;
}

// House class declaration



class Street
{
public:
	Street();
	Street(House new_first, House new_last, int new_num_houses);
	void plot();

private:
	House first, last;
	int num_houses;
};

Street::Street()
{
	first = House(0, Point(0, 0));
	last = House(0, Point(0, 0));
	num_houses = 2;
}

Street::Street(House new_first, House new_last, int new_num_houses)
{
	first = new_first;
	last = new_last;
	num_houses = new_num_houses;
}

void Street::plot() 
{
	Point firstlocation = first.get_location();
	Point lastlocation = last.get_location();
	const double x_distance = lastlocation.get_x() - firstlocation.get_x();
	const double y_distance = lastlocation.get_y() - firstlocation.get_y();
	const double dx = x_distance / (num_houses - 1);
	const double dy = y_distance / (num_houses - 1);
	int firstnumber = first.get_number();
	int lastnumber = last.get_number();

	for (int i = 0; i < num_houses -1; i++)
	{
		Point firstlocation = first.get_location();
		Point newlocation((firstlocation.get_x() + dx),(firstlocation.get_y() + dy));
		// Calculate the new house location point
		
		int newaddress = (int)(firstnumber + (i+1) * 
			((double)(lastnumber - firstnumber) / (num_houses - 1)));
		// Compute new address

		House H(newaddress, newlocation);
		H.draw();
		first = H;
	}
}

//Stret class declaration

int ccc_win_main()
{
	string response;
	int number1, number2;
	int num_houses;

	do 
	{
		number1 = cwin.get_int("Enter the address of the first house.");
		Point location1 = cwin.get_mouse("Click on the first house location.");
		cwin << location1;
		House first(number1, location1);

		number2 = cwin.get_int("Enter the address of the last house.");
		Point location2 = cwin.get_mouse("Click on the last house location.");
		cwin << location2;
		House last(number2, location2);

		num_houses = cwin.get_int("Enter the total number of houses.");

		first.draw();

		//input first house last house and number of house

		Street my_street(first, last, num_houses);
		my_street.plot();
	
		response = cwin.get_string("Want to draw another street? [y/n]");
	} 
	while (response == "Y" || response == "y");

	return 0;
}
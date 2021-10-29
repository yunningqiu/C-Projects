#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int quantity_one;
	string variable_one;
	int quantity_two;
	string variable_two;
	double ratio_one;
	double ratio_two;
	int length_one;
	int length_two;
	int digits;

	// Define variables

	cout << "How many in the first category? ";
	cin >> quantity_one >> variable_one;

	cout << "How many in the second category? ";
	cin >> quantity_two >> variable_two;

	// Get inputs from the user

	cout << "\n";

	length_one = variable_one.length();
	length_two = variable_two.length();
	digits = length_one + length_two;

	// Calculate spaces

	cout << setw(digits + 8) << variable_one << setw(10) << quantity_one << endl;
	cout << setw(digits + 8) << variable_two << setw(10) << quantity_two << endl;

	ratio_one = (double)quantity_one / quantity_two;
	ratio_two = (double)quantity_two / quantity_one;

	// Calculate ratio

	cout << variable_one.erase((length_one - 1), 1) << "-to-" << variable_two.erase((length_two - 1), 1) << " ratio";
	cout << fixed << setprecision(2) << setw(10) << ratio_one << endl;

	cout << variable_two.erase((length_two - 1), 1) << "-to-" << variable_one.erase((length_one - 1), 1) << " ratio";
	cout << fixed << setprecision(2) << setw(10) << ratio_two << endl;
	cout << "\n";

	system("pause");
	return 0;
}

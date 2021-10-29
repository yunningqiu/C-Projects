#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string draw_card(int &total_point, string &card)
{
	int value_num = rand() % 13 + 1;
	int suite_num = rand() % 4 + 1;
	string value;
	string suite;

	if (value_num == 1)
	{
		value = "Ace";
		if (total_point + 11 <= 21)
			value_num = 11;
		else
			value_num = 1;
	}

	else if (value_num == 2)
		value = "Two";
	else if (value_num == 3)
		value = "Three";
	else if (value_num == 4)
		value = "Four";
	else if (value_num == 5)
		value = "Five";
	else if (value_num == 6)
		value = "Six";
	else if (value_num == 7)
		value = "Seven";
	else if (value_num == 8)
		value = "Eight";
	else if (value_num == 9)
		value = "Nine";
	else if (value_num == 10)
		value = "Ten";
	else if (value_num == 11)
	{
		value = "Jack";
		value_num = 10;
	}
	else if (value_num == 12)
	{
		value = "Queen";
		value_num = 10;
	}
	else if (value_num == 13)
	{
		value = "Queen";
		value_num = 10;
	}
	// Give the random integer from 1-13 a rank value of card.


	if (suite_num == 1)
		suite = " of Hearts";
	else if (suite_num == 2)
		suite = " of Diamonds";
	else if (suite_num == 3)
		suite = " of Spades";
	else if (suite_num == 4)
		suite = " of Clubs";
	// Give the random integer from 1-4 a suite value of heart, diamond, spade or club.

	card = value + suite;
	total_point += value_num;
	return card;
}
// Define the draw_card function.

int main()
{
	srand((int)(time(0)));
	int total_point = 0;
	int current_money = 100;
	int bet;
	int user_point = 0;
	int dealer_point = 0;
	string card;
	string yes_or_no;
	bool draw_again;
	bool user_bust = false;
	bool dealer_bust = false;

	// declare variables

	while (current_money > 0 && current_money <= 1000)
	{
		total_point = 0;
		cout << "You have $" << current_money << ".  Enter bet: ";
		cin >> bet;
		while (bet > current_money)
		{
			cout << "You only have $" << current_money << " to bet.  Enter bet: ";
			cin >> bet;
		}
		cout << endl;
		// ask user for the amount of money they wanna bet


		cout << "Your cards are: \n" << " " << draw_card(total_point, card) << endl
			<< " " << draw_card(total_point, card) << endl;
		cout << "Your total is " << total_point << ".  " << "Do you want another card (y/n)? ";
		cin >> yes_or_no;
		cout << endl;
		// output the first two random cards the user gets and ask if he wanna continue

		if (yes_or_no == "y" || yes_or_no == "Y")
			draw_again = true;
		else
		{
			draw_again = false;
			user_point = total_point;
		}

		while (draw_again)
		{
			cout << "You draw a: \n";
			cout << " " << draw_card(total_point, card) << endl;

			if (total_point <= 21)
			{
				cout << "Your total is " << total_point << ".  " << "Do you want another card (y/n)? ";
				cin >> yes_or_no;
				if (yes_or_no == "n" || yes_or_no == "N")
					draw_again = false;
				cout << endl;
				user_point = total_point;
			}

			else
			{
				cout << "Your total is " << total_point << ".  You busted!" << endl;
				user_bust = true;
				user_point = 0;
				draw_again = false;
			}
		}

		// ask the user to draw cards until response is negative, add up the user's total point.

		total_point = 0;
		cout << endl << "The dealer's cards are: \n" << " " << draw_card(total_point, card) << endl
			<< " " << draw_card(total_point, card) << endl;
		cout << "The dealer's total is " << total_point << ". \n\n";
		dealer_point = total_point;
		// output the first two random cards the dealer gets.

		while (total_point <= 16)
		{
			cout << "The dealer draws a card. \n" << " " << draw_card(total_point, card) << endl;
			cout << "The dealer's total is " << total_point << ". \n\n";
			dealer_point = total_point;
		}

		if (total_point > 21)
		{
			dealer_bust = true;
			dealer_point = 0;
		}
		// Dealer's action based on if current point exceeds 16.


		if (user_point > dealer_point)
		{
			current_money += bet;
			cout << "You win $" << bet << "!\n\n";
		}

		else if (user_point < dealer_point || (user_bust && dealer_bust))
		{
			current_money -= bet;
			cout << "Too bad. You lose $" << bet << ".\n\n";
		}

		else
			cout << "A draw! You get back your $" << bet << ". \n\n";

		// Win or lose: Calculate current money left.
	}

	cout << "You have $" << current_money << ".  GAME OVER." << endl;

	system("pause");
	return 0;
}

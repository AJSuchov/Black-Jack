#pragma once
//This classes purpose is to clean up some lines from the main function and print all the results in a seperate .h

#include <iostream>

using namespace std;

class printInfo{
private:
	bool win;
public:
	void printCard(int);
	void tellWinner(int, int, int, int);
	bool compareWinLose(int, int);
};

void printInfo::printCard(int card) { //Prints the cards
	if (card == 11){
		cout << "You drew a Jack!" << endl;
		cout << "The value is 10" << endl;
	}
	else if (card == 12){
		cout << "You drew a Queen!" << endl;
		cout << "The value is 10" << endl;
	}
	else if (card == 13){
		cout << "You drew a King!" << endl;
		cout << "The value is 10" << endl;
	}
	else if (card == 14) {
		cout << "You drew and Ace!" << endl;
		cout << "The value is 11" << endl;
	}
	else {
		cout << "Your card was " << card << endl;;
	}
}

void printInfo::tellWinner(int Player1, int Player2, int Player3, int Player4){  //Displays the winner 
	if (Player1 > Player2 && Player1 > Player3 && Player1 > Player4){
		cout << "Player 1 wins with " << Player1 << " wins over against the dealer" << endl;
	}
	else if (Player2 > Player1 && Player2 > Player3 && Player2 > Player4){
		cout << "Player 2 wins with " << Player2 << " wins over against the dealer" << endl;
	}
	else if (Player3 > Player1 && Player3 > Player2 && Player1 > Player4){
		cout << "Player 3 wins with " << Player3 << " wins over against the dealer" << endl;
	}
	else if (Player4 > Player2 && Player4 > Player3 && Player4 > Player1){
		cout << "Player 4 wins with " << Player4 << " wins over against the dealer" << endl;
	}
	else {
		cout << "There has been a tie." << endl;
	}

	cout << "Player 1 score: " << Player1 << endl;
	cout << "Player 2 score: " << Player2 << endl;
	cout << "Player 3 score: " << Player3 << endl;
	cout << "Player 4 score: " << Player4 << endl;
}

bool printInfo::compareWinLose(int sum, int dealerSum){
	if (dealerSum > sum && dealerSum <= 21) {
		cout << "You Lose" << endl;
		win = false;
	}else if (sum > dealerSum && sum > 21) {
		cout << "You Lose" << endl;
		win = false;
	}else if (sum == dealerSum) {
		cout << "It is a tie. You Lose" << endl;
		win = false;
	}else {
		cout << "You WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		win = true;
	}
	cout << "-------------------------------------------------" << endl;
	return win;
}
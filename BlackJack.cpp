//AJ Suchovsky
//Project:  Black Jack
//Credit to Josh Aylor for idea of game


#include "StackClass.h"
#include "Game.h"
#include "PrintInfo.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctime>


BlackJack Deck;
game Player;
printInfo Print;
void shuffleDeck(int[52]); //Shuffles the deck of values
void createDeck(int[52]); //Creates a deck to be modified i.e. creates a stack
void reDeck(); //Checks to see if the deck is empty or not, if it is, then recreates the deck

int deck[52] = { 14, 14, 14, 14, //The deck values for the cards inside of an array to pull from
				2, 2, 2, 2,
				3, 3, 3, 3,
				4, 4, 4, 4, 
				5, 5, 5, 5,
				6, 6, 6, 6,
				7, 7, 7, 7,
				8, 8, 8, 8,
				9, 9, 9, 9,
				10, 10, 10, 10,
				11, 11, 11, 11,
				12, 12, 12, 12,
				13, 13, 13, 13 };

using namespace std;

int main()
{
	//////////////////////Outside Variables that need to be first ////////////////////////
	int scores[4] = { 0, 0, 0, 0 }; //Keeps scores of each player
	srand(time(NULL)); //Used for generating a random shuffled array every time
	int numplayers; //Cin value from user
	int numrounds; //Cin value from user

	///////////////////////Get game information from user. /////////////////////////////
	do{
		cout << "How many players do you want, 4 is the max number of players, 1 is the lowest amount." << endl;
		cin >> numplayers;
	} while (numplayers > 4 || numplayers < 1);

	cout << "How many rounds would you like?" << endl;
	cin >> numrounds;

	//////////////////////Game initalizing variables//////////////////////////
	int dealerSum; //Sum of the dealers cards
	int card1; //Value holder of card 1
	int card2; //Value holder of card 2
	int sum = 0; //Sum of the cards
	int card3; //Value for a third card
	bool hit = true; //If the user decides to hit or not
	int hitval; //Input from user to trigger the hit
	bool score; //Used to see if the player won or not

	////////////////////////////////////////////////////Game starts running ////////////////////////////////////////////////////
	createDeck(deck); //Creates the deck to use and call from the Stack Class.

	for (int rounds = 0; rounds < numrounds; rounds++) { //Runs the game for 10 rounds
		
		///////////Creates Dealer//////////////
		card1 = Deck.pop(); //Sets the card value to the top card in the deck from deck object.
		reDeck(); //Checks if deck is empty
		card2 = Deck.pop(); //Sets the card value to the top card in the deck from deck object.
		reDeck(); //Checks if deck is empty
		dealerSum = Player.sumCards(card1); //Dealers summ is the sum of card 1
		dealerSum = Player.sumCards(card2); //Dealers sum is the sum of card 2 added to card 1

		while (dealerSum < 17) { //If the sum of the two cards is less than 17
			card3 = Deck.pop(); //Sets the card value to the top card in the deck from deck object.
			dealerSum = Player.sumCards(card3); //Add the card to the dealers sum
			reDeck(); //Checks if deck is empty
		}

		Player.resetSum(); //Resets the sum in the player object

		///////////Each players card info for the round/////////////
		for (int numPlay = 0; numPlay < numplayers; numPlay++) {
			cout << "Player " << numPlay + 1 << "'s turn." << endl;
			//Player Deals
			card1 = Deck.pop(); //Sets the card value to the top card in the deck from deck object.
			reDeck(); //Checks if deck is empty
			card2 = Deck.pop(); //Sets the card value to the top card in the deck from deck object.
			reDeck(); //Checks if deck is empty
			Print.printCard(card1); //Prints the value of the card
			Print.printCard(card2); //Prints the value of the card

			sum = Player.sumCards(card1); //Adds the card to the players sum
			sum = Player.sumCards(card2); //Adds the card to the players sum

			hit = true;

			while (hit == true) {
				cout << "Your sum is " << sum << endl;
				cout << "Do you want to hit, 1 for yes 0 for no" << endl;
				cin >> hitval;

				if (hitval == 1) {
					card3 = Deck.pop(); //Sets the card value to the top card in the deck from deck object.
					reDeck(); //Checks if deck is empty
					Print.printCard(card3); //Prints the value of the card
					sum = Player.sumCards(card3); //Adds the card to the players sum
					if (sum > 21) {
						cout << "You BUST" << endl;
						hit = false; //Stops from drawing another card
					}
				}
				else {
					hit = false; //Stops from drawing another card
				}
			}

			cout << "The dealers sum is " << dealerSum << endl;
			
			///////Figures out if won or not/////////////
			score = Print.compareWinLose(sum, dealerSum);//Comparison of whether win or lose
			if (score == true){ //If score is true then add 1 to the players score of wins.
				scores[numPlay] += 1;
			}

			reDeck(); //Checks if deck is empty
			Player.resetSum();//Resets the sum in the player object
		}
		reDeck(); //Checks if deck is empty
		dealerSum = 0; //Sets the dealers sum back to zero
	}

	cout << endl;
	Print.tellWinner(scores[0], scores[1], scores[2], scores[3]);//Prints the winner of the game

	return 0;
}

//////////////////////////////////////// Function Code ////////////////////////////////////////////////////
void createDeck(int deck[52]) {
	shuffleDeck(deck); //Shuffles the array of given card values
	//Creates the deck of cards
	for (int i = 0; i < 52; i++) {
		Deck.push(&deck[i]); //Pushes the pointer value to the stack of cards
	}
}

void shuffleDeck(int deck[52]) {  //Shuffles the deck
	random_shuffle(&deck[0], &deck[52]); //Randomizes the array
}

void reDeck() { //Recreates deck when it is empty
	if (Deck.isEmpty() == true) { //Checks if the deck stack is empty
		createDeck(deck); //If it is, create the deck again
	}
}



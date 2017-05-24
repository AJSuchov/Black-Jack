#pragma once
//A class to configue how to deal with face card values.
class game {
private:
	int sum = 0; //Sum of the cards holder
public:
	void resetSum(); //Sets sum of cards back to zero for the game
	int sumCards(int &); //Figures out the sum of the cards 
};

int game::sumCards(int &cardVal) { //Gets the card value and determines if it remains its value or sets it equal to 10 or 11 i.e. face cards to 10 and ACE to 11
	if (cardVal > 10 && cardVal < 14) { //If the card value is less than 14 but greater than 10
		sum = sum + 10; //Add 10 to the sum
	}else if (cardVal == 14){ //If the value is equal to 14
		sum = sum + 11; //Add 11 to the sum
	}else { //If neither
		sum = sum + cardVal; //Add the original value
	}
	return sum; //Returns the sum value
}

void game::resetSum() { //Resets the sum to zero for another use.
	sum = 0;
}
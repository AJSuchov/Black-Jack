//The stack/deck class where the cards will be pushed and popped from.
#include <algorithm>
#include <iostream>
using namespace std;

class BlackJack {
private:
	int length = 0; // keeps track of where you are in the array
	int *list[52];//Creates an array of pointers

public:
	BlackJack(); //Default constructor takes a parameter that indicates the size of the array.
	~BlackJack(); //Destructor
	void push(int *); //Function that accepts a pointer and adds that pointer to the top of the stack: //Doesn't create any memory
	int pop(); // returns a pointer doesn’t delete any memory
	int top(); // returns a pointer to the item on the top of the stack doesn’t remove it
	bool isEmpty();
	int findLength();

};

BlackJack::BlackJack() { //Default Constructor s is the size of the array
}

BlackJack::~BlackJack() { //Destructor
}

void BlackJack::push(int *c) { //Adds item to the top of the stack
	int i = 0; //New int value to to compare to length
	while (i < length) { //While i is less than length
		i++; //Add 1 to i
	}
	list[i] = c; //The spot i spot in the array, set equal to the value of c that is being added in from main function
	length++; //Add 1 to length for next spot in array.
};

int BlackJack::pop() { //Returns pointer from the top of the stack
	int val;
	val = *list[length - 1]; //Sets the int val to the dereferenced item in the stack (The last item added/top item)
	list[length - 1] = NULL; //Sets the spot in the stack to Null
	length--; //Subtracts 1 from the length/variable keeping track of where you are in the array.
	return val;
};

int BlackJack::top() {
	return *list[length - 1]; //Retruns the dereferenced array item that is "On the top" (Last item in the array/stack)
}

bool BlackJack::isEmpty() { //Checks to see if the stack is empty or not
	return length == 0; //Bool if the length is equal to 0 or not if not then the stack is not empty.
}

int BlackJack::findLength() { //returns the number of items in the stack
	return length;
};


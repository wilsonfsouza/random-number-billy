/*******************************************************************************
 * Program Name: Guessing Game 
 * Created Date: 2/19/2024
 * Created By: Billy Soksoda
 * Purpose: Have user make a guess 
 * Acknowledgements:
 *******************************************************************************/

/*******************************************************************************
	 * Function Name: main()
	 * Parameters: None
	 * Return Value: int
	 * Purpose:
	 *******************************************************************************/

#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int MAX_NUMBER = 100;
const int INITIAL_GUESSES = 5;

bool isValidGuess(int guess) {
    return guess >= 1 && guess <= MAX_NUMBER;
}

void printUserWinCondition(bool isFirstGuess) {
  if (isFirstGuess) {
    cout << "You Win on your first guess! Good JOb!" << endl;
  } else {
    cout << "You WIN! Awesome Job!" << endl;
  }
}

int main()
{
	// intialize and declare varaibles 
	int randNum; //computer generate random number
	int useNum; //user entered number
	bool win = false; //boolean to determiune winner turns to true if winner

	int guesses = INITIAL_GUESSES; // number of user guesses initalize to 5 (give users 5 guesses)
	// seed number of random number
	unsigned seed = time(0);
		srand(seed); //seeded random number
	randNum = 1 + rand() % MAX_NUMBER; //computer random number 1-100
	cout << setw(30) << fixed << "Number guesing game:\n";
	cout << setw(5) << fixed << "I am thinking of a number. Ca you guess the number?:\n";
	cout << setw(16) << fixed << "You have" << guesses << "guess(es) left:\n";
	cout << endl;
	
	cout << endl;
	//loop to determine if user is winner
	while (!win && guesses > 0)
	{
    cin >> useNum; //user entered number

		if (!isValidGuess(useNum))
		{
			cout << "The number: " << useNum << " you enter is out of the range. Please re-enter a number between 1 and " << MAX_NUMBER << ": \n";
			continue;
		}
		
    if (useNum < randNum)
		{
			cout << "Too low. Try again, " << endl;
		}
		else if (useNum > randNum)
		{
			cout << "Too High. Try again." << endl;
		}
		else // user wins aka winner
		{
      printUserWinCondition(guesses == 5);
      win = true;
		}

    guesses = guesses - 1;
		cout << "You have " << guesses << " guess(es) left. \n";
  }

  if (!win) {
    cout << "The number the computer chose was: " << randNum << endl;
  }

  //close program and exit gracefully
	return 0;
}
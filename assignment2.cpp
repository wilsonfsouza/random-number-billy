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
int main()
{
	// intialize and declare varaibles 
	int randNum; //computer generate random number
	int useNum; //user entered number
	bool win = false; //boolean to determiune winner turns to true if winner

	int guesses = 5; // number of user guesses initalize to 5 (give users 5 guesses)
	// seed number of random number
	unsigned seed = time(0);
		srand(seed); //seeded random number
	randNum = 1 + rand() % 100; //computer random number 1-100
	cout << setw(30) << fixed << "Number guesing game:\n";
	cout << setw(5) << fixed << "I am thinking of a number. Ca you guess the number?:\n";
	cout << setw(16) << fixed << "You have" << guesses << "guess(es) left:\n";
	cout << endl;
	cin >> useNum; //user entered number
	cout << endl;
	//loop to determine if user is winner
	while (!win && guesses > 0)
	{
		if (useNum > 100)
		{
			cout << "The numer: " << useNum << "you enter is out of the range. Please re-enter a number:\n";
			cin >> useNum;
			continue;
		}
		else if (useNum < randNum)
		{
			cout << "Too low. Try again, " << endl;
			cin >> useNum;
				if (guesses < 1)
				{
				cout << "The numner the computer chose was " << randNum << endl;
				break;
				}
		}
		else if (useNum > randNum)
		{
			cout << "Too High. Try again." << endl;
			cin >> useNum;
				// Print computer guess on last turn
				if (guesses > 5)
				{
				cout << "The number the computer chose was" << randNum << endl;
				break;
				}

		}
		else // user wins aka winner
		{
			if (guesses >= 5)  //winner wins on first guess
			{
				cout << "You Win on your first guess! Good JOb!" << endl;
				win = true;
			{
				//user wins on any other guess
				cout << "You WIN! Awesome Job!" << endl;
				win = true;
				}
			}
		}

    guesses = guesses - 1;
		cout << "You have " << guesses << " guess(es) left. \n";
  }
//close program and exit gracefully
	return 0;
}
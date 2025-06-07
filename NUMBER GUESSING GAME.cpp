/*  Developer : Saikat Acharjee
   * Project: NUMBER GUESSING GAME
* Description:This Is a program that generates a random number and asks the
              user to guess it. Provide feedback on whether the guess is too
                high or too low until the user guesses the correct number.
*/
#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Initialize random seed
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    cout << "\t\t\t\t\t Welcome to the Unique Number Guessing Game! \n";
    cout << "\t\t\t\t\t--------------------------------------------\n";
    cout << "I'm thinking of a number between 1 and 100. Can you guess it?\n";

    // Loop until the user guesses the correct number
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }

    } while (userGuess != secretNumber);

    return 0;
}


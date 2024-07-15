#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    
    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;
    int userGuess = 0;
    int numberOfAttempts = 0;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Loop until the user guesses the correct number
    while (userGuess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        numberOfAttempts++;

        if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << numberOfAttempts << " attempts." << endl;
        }
    }

    return 0;
}
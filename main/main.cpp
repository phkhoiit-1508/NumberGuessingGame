#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Classic();
void LimitAttempts();
void ComputerGuess();

int main() {
	srand(time(0));
	while (1) {
		cout << "\n\n=== Number Guessing Game ===\n\n";
		cout << "1. Classic\n";
		cout << "2. Limit Attempts\n";
		cout << "3. Computer Guessing\n";
		cout << "0. Exit\n\n";

		cout << "Please choose a mode before play: ";

		int op; cin >> op;
		
		if (op == 1) Classic();
		else if (op == 2) LimitAttempts();
		else if (op == 3) ComputerGuess();
		else if (op == 0) {
			cout << "Thank you for enjoying it. See you later!!!";
			break;
		}
		else cout << "Please choose a number from 0 to 3.";
	}
	return 0;
}

void Classic() {
	int num, guess, tries = 0;

	num = rand() % 100 + 1;
	cout << "\n\n=========== Start ===========\n\n";

	do {
		cout << "Enter a guess between 1 and 100: ";
		cin >> guess;
		tries++;
		if (guess > num) cout << "\nToo high! Try again\n\n";
		else if (guess < num) cout << "\nToo low! One more...\n\n";
		else {
			cout << "\nCorrect!\n";
			cout << "You got it in " << tries << " guesses! Good job!\n";
		}
	} while (guess != num);

	return;
}

void LimitAttempts() {
	cout << "==== Limit Attempts Mode ====\n";
	cout << "\n1. Easy:          Range: 1 - 50          Tries: 10\n";
	cout << "2. Medium:        Range: 1 - 100         Tries: 7\n";
	cout << "3. Hard:          Range: 1 - 500         Tries: 9\n\n";

	cout << "Please choose the difficulty before play: ";
	int select; cin >> select;

	if (select == 1) {
		int tries = 10;
		int num = rand() % 50 + 1;
		int guess;
		do {
			if (tries == 10) cout << "\n\n=========== Start ===========\n\n";

			cout << "You currently have " << tries << " attempt(s).\n";

			cout << "Enter a guess between 1 and 50: ";
			cin >> guess;
			tries--;

			if (tries == 0 && guess != num) {
				cout << "Game over!!! The number is " << num << ".\n";
				break;
			}

			if (guess > num) cout << "\nToo high! Try again\n\n";
			else if (guess < num) cout << "\nToo low! One more...\n\n";
			else {
				cout << "\nCorrect! You did it!!!\n";
				break;
			}
		} while (guess != num && tries > 0);
	}

	else if (select == 2) {
		int tries = 7;
		int num = rand() % 100 + 1;
		int guess;
		do {
			if (tries == 7) cout << "\n\n=========== Start ===========\n\n";
			cout << "You currently have " << tries << " attempt(s).\n";

			cout << "Enter a guess between 1 and 100: ";
			cin >> guess;
			tries--;

			if (tries == 0 && guess != num) {
				cout << "Game over!!! The number is " << num << ".\n";
				break;
			}

			if (guess > num) cout << "\nToo high! Try again\n\n";
			else if (guess < num) cout << "\nToo low! One more...\n\n";
			else {
				cout << "\nCorrect! You did it!!!\n";
				break;
			}
		} while (guess != num && tries > 0);
	}

	else if (select == 3) {
		int tries = 9;
		int num = rand() % 500 + 1;
		int guess;
		do {
			if (tries == 9) cout << "\n\n=========== Start ===========\n\n";

			cout << "You currently have " << tries << " attempt(s).\n";

			cout << "Enter a guess between 1 and 500: ";
			cin >> guess;
			tries--;

			if (tries == 0 && guess != num) {
				cout << "Game over!!! The number is " << num << ".\n";
				break;
			}

			if (guess > num) cout << "\nToo high! Try again\n\n";
			else if (guess < num) cout << "\nToo low! One more...\n\n";
			else {
				cout << "\nCorrect! You did it!!!\n";
				break;
			}
		} while (guess != num && tries > 0);
	}
}


void ComputerGuess() {
	cout << "\n\n==== Computer Guessing Mode ====\n\n";
	cout << "Think of a number from 1 to 100.\n";
	cout << "Enter:\n";
	cout << ">  if your number is greater than my guess\n";
	cout << "<  if your number is less than my guess\n";
	cout << "=  if my guess is correct\n\n";

	cout << "When you are ready, enter 'R': ";
	char c;
	cin >> c;

	if (c != 'R' && c != 'r') return;

	cout << "\n\n=========== Start ===========\n\n";

	int low = 1, high = 100;
	int tries = 0;
	char feedback;

	while (low <= high) {
		int mid = (low + high) / 2;
		tries++;

		cout << "My guess is: " << mid << endl;
		cout << "Enter your response (>, <, =): ";
		cin >> feedback;

		if (feedback == '=') {
			cout << "\nYeah! I got it in " << tries << " attempt(s)!\n";
			return;
		}
		else if (feedback == '>') low = mid + 1;
		else if (feedback == '<') high = mid - 1;
		else {
			cout << "Invalid input. Please enter only >, <, or =.\n";
			tries--;
		}
	}

	cout << "\nSomething went wrong. Are you sure your answers were consistent?\n";
}
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


int GuessConversion(string Guess) {
	int aNum = NULL;
	try {
		aNum = stoi(Guess);
	} catch (out_of_range) {
		cout << "number is too big" << endl;
	} catch (invalid_argument) {
		cerr << "please enter a valid number" << endl;
	} catch (...) {
		cerr << "error has occurred" << endl;
	}
	return aNum;
}

int main() {
	const int max = 3; const int min = 1;
	unsigned seed = time(0); srand(seed);

	int GameNumber = (rand() % (max - min + 1)) + min;

	string guess = "0";
	int iCounter = NULL;
	int PastArr[200] = {};
	// an array storage of all int guess values
	cout << "enter a valid number >";
	while (GuessConversion(guess) != GameNumber) {
		if (iCounter == 0) {
			cout << "enter a valid number >";
		}
		else {
			if (iCounter > 1) {
				if (abs(PastArr[iCounter - 1] - GameNumber) < abs(PastArr[iCounter - 2] - GameNumber)) {
					cout << "closer" << endl;
				}
				else {
					cout << "further" << endl;
				}
			}
			cout << "try again >";
		}
		getline(cin, guess);
		
		try {
			PastArr[iCounter] = stoi(guess);
		} catch (...) {}
		iCounter++;
	}
	cout << "You Win!" << endl;
}

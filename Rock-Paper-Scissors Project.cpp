#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>

enum enChoice { rock = 1, paper, scissors };

int randomNum(int from, int to)
{
	int ranNum = rand() % (to - from + 1) + from;
	return ranNum;
}

int readNumber(string message)
{
	int num;
	cout << message << endl;
	cin >> num;

	return num;
}

int HowManyRounds()
{
	int rounds = readNumber("How many rounds do you want to play?");
	return rounds;
}

enChoice getPlayerChoice()
{
	int playerChoice;

	cout << "\nWhat is your choice? [1]:Rock , [2]:Paper , [3]:Scissors\n";

	cin >> playerChoice;

	return (enChoice)playerChoice;
}

enChoice getComputerChoice()
{
	int ComputerChoice = randomNum(1, 3);

	return (enChoice)ComputerChoice;
}

string choiceToString(enChoice choice)
{
	switch (choice)
	{
	case rock:
		return "Rock\n";
	case paper:
		return "Paper\n";
	case scissors:
		return "Scissors\n";
	}
}

void WhoWins(int& PlayerWins, int& PlayerLoses, int& Draws)
{
	int rounds = HowManyRounds();
	for (int i = 1; i <= rounds; i++)
	{
		enChoice playerChoice = getPlayerChoice();
		enChoice computerChoice = getComputerChoice();

		string playerStr = choiceToString(playerChoice);
		string computerStr = choiceToString(computerChoice);

		if (
			(playerChoice == rock && computerChoice == scissors) ||
			(playerChoice == scissors && computerChoice == paper) ||
			(playerChoice == paper && computerChoice == rock)
			)
		{
			PlayerWins++;
			system("color 2F");
			cout << "\n\n----------Round[" << i << "]----------\n\n";
			cout << "Player Choice : " << playerStr;
			cout << "Computer Choice : " << computerStr;
			cout << "Round Winner : " << "Player\n\n";
			cout << "----------------------------\n\n";
		}
		
		else if (playerChoice == computerChoice)
		{
			Draws++;
			system("color 6F");
			cout << "\n\n----------Round[" << i << "]----------\n\n";
			cout << "Player Choice : " << playerStr;
			cout << "Computer Choice : " << computerStr;
			cout << "Round Winner : " << "No winner\n\n";
			cout << "----------------------------\n\n";
		}
		else
		{
			PlayerLoses++;
			cout << "\a";
			system("color 4F");
			cout << "\n\n----------Round[" << i << "]----------\n\n";
			cout << "Player Choice : " << playerStr;
			cout << "Computer Choice : " << computerStr;
			cout << "Round Winner : " << "Computer\n\n";
			cout << "----------------------------\n\n";
		}
	}
}

void finalResult(int PlayerWins, int PlayerLoses, int Draws)
{
	cout << "\n\n-------------------------------------------------------------------\n\n";
	cout << "\t\t\t+++Game Over+++\t\t";
	cout << "\n\n-------------------------------------------------------------------\n\n";
	cout << "---------------------------[Game Result]---------------------------\n\n";
	cout << "Game rounds: " << PlayerLoses + PlayerWins + Draws;
	cout << "\nPlayer won times : " << PlayerWins;
	cout << "\nComputer won times : " << PlayerLoses;
	cout << "\nDraws times : " << Draws;
	cout << "\nFinal winner : ";
	if (PlayerWins > PlayerLoses) cout << "Player";
	else if (PlayerWins < PlayerLoses) cout << "Computer";
	else cout << "No winner";
	cout << "\n\n-------------------------------------------------------------------\n\n";


}

int main()
{
	srand((unsigned)time(NULL));

	bool again = 1;
	char agree;

	while (again)
	{
		int playerWins = 0, PlayerLoses = 0, Draws = 0;
		WhoWins(playerWins, PlayerLoses, Draws);

		finalResult(playerWins, PlayerLoses, Draws);

		cout << "\n\nDo you want to play again? Y/N?";
		cin >> agree;
		agree = tolower(agree);

		if (agree == 'y')
		{
			system("cls");
			system("color 0F");
			again = 1;
		}
		else again = 0;
	}
}


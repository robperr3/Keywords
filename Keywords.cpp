// CIA_program.cpp : Defines the entry point for the console application.
//This is a Training Simulation program for the CIA to help recuits learn 
//how to decypher the enemy's coded messages


#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	char again;
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{ "wall", "Do you feel youre banging your head against something?" },
		{ "rendezvous", "Why does this word sound French?" },
		{ "treason", "Does Eric Snowden ring a bell?" },
		{ "persistant", "If you cant guess this one just give up newb!" },
		{ "jumble", "Its what this game is about" },
		{ "spy", "Its what you are, dummy!" },
		{ "hell", "its where you are now!HAHAHA" },
		{ "KIA", "Lets hope you dont end up as this, rookie!" },
		{"classified", "This means its above your paygrade" },
		{"KGB", "if you cant figure this one out, youre an idiot"},

	};
	enum difficulty { EASY, MEDIUM, HARD, NUM_DIFF_LEVELS };
	cout << "There are " << NUM_DIFF_LEVELS << "dificulty levels";
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);

	string theWord = WORDS[choice][WORD];// word to guess
	string theHint = WORDS[choice][HINT];//hint for word
	string jumble = theWord; //jumble version of word
	int length = jumble.size();
	int attempts = 0;

	do
	{
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		cout << "\t\t\tWelcome to Word Jumble!\n\n";
		cout << "Unscramble the letters to make a word\n";
		cout << "enter'hint' for a hint";
		cout << "Enter 'quit' to quit thew game\n\n";
		cout << "The jumble is:" << jumble;
		string guess;
		++attempts;
		cout << "\n\nYour guess: ";
		cin >> guess;

		if ((guess != theWord) && (guess != "quit"))
		{
			cout << theHint;
		}

		else if (guess == "hint")
		{
			cout << theHint;
		}

		else if(guess != theWord)
		{
			cout << "\n\nyour guess: ";
			cout << "sorry, thats not right";
			cin >> guess;
		}

		else if (guess == theWord)
		{
			cout << "\nThats it!You guesed right! And it only took you "<< attempts << " tries!\n";
			cout << "\nThanks for playing\n";
			cout << "\nDo you wanna play again? y or n?\n";
			cin >> again;
		}
	} while (again == 'y');

	system("pause");
	return 0;

}	
	
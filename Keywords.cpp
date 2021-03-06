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
	char again;//labeling again as a variable
	enum fields { WORD, HINT, NUM_FIELDS };//differnt types of strings i.e. words, hints, etc.
	const int NUM_WORDS = 10;//i have 10 possible words to jumble
	const string WORDS[NUM_WORDS][NUM_FIELDS] //all the possible words with associated hints as an array
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
	srand(static_cast<unsigned int>(time(0)));//generating the random function
	int choice = (rand() % NUM_WORDS);//using random function to choose random word from array

	string theWord = WORDS[choice][WORD];// word to guess
	string theHint = WORDS[choice][HINT];//hint for word
	string jumble = theWord; //jumble version of word
	int length = jumble.size();//tracks the length of jumble word
	int attempts = 0;//variable for incrementing

	do//yes, im using a do while loop for this one
	{
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);//these two lines are indexing random letters in the word
			int index2 = (rand() % length);
			char temp = jumble[index1];//These lines are mixing up the indexed letters
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		cout << "\t\t\tWelcome to Word Jumble!\n\n";
		cout << "Unscramble the letters to make a word\n";
		cout << "enter'hint' for a hint";
		cout << "Enter 'quit' to quit thew game\n\n";
		cout << "The jumble is:" << jumble;
		string guess;//recording your guess as a string
		++attempts;//counting how many times you guessed
		cout << "\n\nYour guess: ";
		cin >> guess;//your guess, duh!

		if ((guess != theWord) && (guess != "quit"))//this is if you get mad for being wrong & you give up
		{
			cout << theHint;
		}

		else if (guess == "hint")
		{
			cout << theHint;
		}

		else if(guess != theWord)//if you play but your guess is wrong, you get to try again
		{
			cout << "\n\nyour guess: ";
			cout << "sorry, thats not right";
			cin >> guess;
		}

		else if (guess == theWord)//if your guess is right, you get congrats & asked to play again
		{
			cout << "\nThats it!You guesed right! And it only took you "<< attempts << " tries!\n";
			cout << "\nThanks for playing\n";
			cout << "\nDo you wanna play again? y or n?\n";
			cin >> again;//your answer to the play again question
		}
	} while (again == 'y');//if your answer is equal to yes, the code loops

	system("pause");
	return 0;

}	
	
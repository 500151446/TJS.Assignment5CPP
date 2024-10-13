#include <conio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// tried researching how to include the text file with the solution and reference it 
// spent like an hour on it but couldn't figure it out
// so this just reads it from my local machine but that wouldn't be on github?

int main()
{
	string filepath = "C:\\Temp\\QuizQuestions.txt";
	string line;
	ifstream ifs(filepath);

	vector<string> questions;

	while (getline(ifs, line))
	{
		questions.push_back(line);
	}

	ifs.close();

	cout << "Welcome to the Math Quiz!\n";

	srand(time(NULL));
	
	filepath = "C:\\Temp\\QuizResults.txt";
	ofstream ofs(filepath);

	for (int i = 0; i < 3; i++)
	{
		int randomNumber = rand() % 10;
		string question = questions[randomNumber] + " = ";

		cout << "\nQuestion " << (i + 1) << " : " << question << "\n";

		string input;
		cout << "Enter your answer: ";
		cin >> input;
		ofs << question + input << "\n";
	}

	ofs.close();

	return 0;
}

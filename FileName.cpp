#include "std_lib_facilities.h"

void sort_print(string x, vector<string> y) {
	sort(y);
	for (string x : y) {
		cout << x << endl;
	}
}
string compare(string try_string, string answer_string) {
	string code;

	for (int i = 0; i < 5; i++) {
		if (try_string[i] == answer_string[i]) {
			code += "*";//자리+알파벳 정답
		}
		else {
			bool a =  false;
			for (int j = 0; j < 5; j++) {
				if (try_string[i] == answer_string[j]) {
					a = true;
					break;
				}
			}
			if (a) {
				code += "#";
			}
			else {
				code += "@";
			}
		}
			
	}
	return code;
}



int main()
{
	ifstream infile("words.txt");
	string word;
	vector<string> vec_word;

	while (infile >> word) {
		vec_word.push_back(word);
	}

	int num_choice;

	do {
		num_choice = 0;
		cout << "<<< WORDLE >>>" << endl
			<< "1. Dictionary" << endl
			<< "2. Game" << endl
			<< "3. Exit" << endl << endl;
			
		while (num_choice < 1 || num_choice>3) {
			cout << "Choose an option (1-3) :";
			cin >> num_choice;
		}

		if (num_choice == 1) {//사전
			while (1) {
				cout << endl << "[ DICTIONARY ]" << endl << "1. Print" << endl << "2. Return" << endl << endl;;
				int num_choice_dictionary = 0;

				while (num_choice_dictionary < 1 || num_choice_dictionary>2) {
					cout << "Choose an option (1-2) :";
					cin >> num_choice_dictionary;
				}

				if (num_choice_dictionary == 2) {
					break;
				}
				sort_print(word, vec_word);
				cout << "A total of " << size(vec_word) << "words are available" << endl;

			}
		}
		else if (num_choice == 2) {//게임실행
			string string_try;
			int ran_num = randint(size(vec_word));
			string answer = vec_word[ran_num];//답 정해짐
			
			for (int i = 0; i < 6; i++) {
				cout << "[" << i + 1 << "/6] Guess the word :";
				cin >> string_try;
				cout << "==> ";
				cout << compare(string_try, answer) << endl;

				if (string_try == answer) {
					break;
				}
			}
			if (string_try == answer) {
				cout << "Congratulation!!! Your guess is correct" << endl;
			}
			else {
				cout << "Oops!!! You lost all your chances. The correct answer is \"" << answer << "\"." << endl;
			}
		}
	} while (num_choice != 3);
	cout << "Good Bye!!!";

}
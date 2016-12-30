#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "error" << endl;
		return 1;
	}

	// makes an array to hold count of length of words
	int count[101];
	for (int i = 0; i < 101; i++) {
		count[i] = 0;
	}

	ifstream fin(argv[1]);
	string word;
	if (!fin) {
		cout << "file did not open correctly." << endl;
		return 1;
	}
	int num_words[2] = { 0, 0 };   // tracks number of words in the file
	while (fin >> word) {          // keeps going until end of file is reached
		count[word.length()]++;    // keeps count of number times a length appears
		num_words[0]++;
	}
	fin.close();
	for (int i = 0; i < 101; i++) {
		if (count[i] != 0) {   // print if word this size was recorded
			cout << i << " letters: " << " " << count[i] << endl;
			num_words[1]++;
			if (num_words[0] == num_words[1]) {   // once everything is printed, exit loop
				return 0;
			}
		}
	}
}

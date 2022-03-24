#include <cctype>
#include <string>
#include <iostream>

using namespace std;


void encrypt(char * input, unsigned int offset) {
	for (int i = 0; input[i] != 0; i++) {
		//	Skip spaces...
		if (input[i] == ' ')
			continue;

		char firstLetter = islower(input[i]) ? 'a' : 'A';
		unsigned int
			alphaOffset = input[i] - firstLetter,
			newAlphaOffset = alphaOffset+offset;
		input[i] = firstLetter + newAlphaOffset % 26;
	}
}

void decrypt(char * input, unsigned int offset) {
	for (int i = 0; input[i] != 0; i++) {
		//	Skip spaces...
		if (input[i] == ' ')
			continue;

		char firstLetter = islower(input[i]) ? 'a' : 'A';
		unsigned int alphaOffset = input[i] - firstLetter;
		int newAlphaOffset = alphaOffset - offset;

		if (newAlphaOffset < 0) {
			newAlphaOffset += 26;
		}

		input[i] = firstLetter + (newAlphaOffset % 26);
	}
}

int main() {
	std::string alphabeticalString = "abcdefghijklmnopqrstuvwxyz";
	unsigned int encryptionOffset;

	cout << "please enter an alphabetical string to encrypt...\n\t> ";
	getline(cin, alphabeticalString);
	cout << "please enter the encryption key (a number between 0 and 25)\n\t> ";
	cin >> encryptionOffset;

	cout << "Encrypted from: \"" << alphabeticalString.c_str();
	encrypt(const_cast<char*>(alphabeticalString.c_str()), encryptionOffset);
	cout << "\" in: \"" << alphabeticalString << "\"" << endl;

	cout << "Decrypted back from: \"" << alphabeticalString.c_str();
	decrypt(const_cast<char*>(alphabeticalString.c_str()), encryptionOffset);
	cout << "\" in: \"" << alphabeticalString << "\"" << endl;
	return 0;
}










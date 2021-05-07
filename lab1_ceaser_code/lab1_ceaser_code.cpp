#include <iostream>
using namespace std;
#define SIZE 512
#define ENG 26

void encoderCeaser(int key, char* message, char* code) {
	while (*message) { 
		if (*message >= 65 && *message <= 90) {
			if ((*message + key) > 90) {
				*code = *message + key - ENG;
			}
			else {
				*code = *message + key;
			}
			
		}
		else if(*message >= 97 && *message <= 122){
			if ((*message + key) > 122) {
				*code = *message + key - ENG;
			}
			else {
				*code = *message + key;
			}
		}
		else {
			*code = *message;
		}
		message++;
		code++;
	}
}

void decoderCeaser(int key, char* code, char* message) {
	while (*code) {
		if (*code >= 65 && *code <= 90) {
			if ((*code - key) < 65) {

				*message = *code - key + ENG;
			}
			else {
				*message = *code - key;
			}

		}
		else if (*code >= 97 && *code <= 122) {
			if ((*code - key) < 97) {
				*message = *code - key + ENG;
			}
			else {
				*message = *code - key;
			}
		}
		else {
			*message = *code;
		}
		message++;
		code++;
	}
}


int main() {
	while (1) {
		int command = 0;
		cout << "Select: 1 - encoding, 2 - decoding. ";
		cin >> command;
		while (command != 1 && command != 2) {
			cin.clear();
			cin.ignore();
			cout << "Error! You can enter 1 or 2" << endl;
			cout << "Select: 1 - encoding, 2 - decoding. ";
			cin >> command;
		}
		switch (command) {
		case 1: {
			char* message = new char[SIZE] {};
			char* code = new char[SIZE] {};
			int key = 0;
			cout << "Enter key for Ceasar's code from 1 to 25: ";
			//cin.ignore('\n');
			cin >> key;
			while (key < 1 || key > 25) {
				cin.clear();
				cin.ignore();
				cout << "Error! You entered an invalid key. " << endl;
				cout << "Enter key for Ceasar's code from 1 to 25: ";
				cin >> key;
			}
			cin.ignore();
			cout << "Enter your message: ";
			cin.getline(message, SIZE);
			encoderCeaser(5, message, code);
			cout << "Your encoded massege: " << code << endl;
			break;
		}
		case 2: {
			char* message = new char[SIZE] {};
			char* code = new char[SIZE] {};
			int key = 0;
			cout << "Enter key for Ceasar's code: ";
			cin >> key;
			while (key < 1 || key > 25) {
				cin.clear();
				cin.ignore();
				cout << "Error! You entered an invalid key. " << endl;
				cout << "Enter key for Ceasar's code from 1 to 25: ";
				cin >> key;
			}
			cin.ignore();
			cout << "Enter your code: ";
			cin.getline(code, SIZE);
			decoderCeaser(5, code, message);
			cout << "Your decoded massege: " << message << endl;
			break;
		}
		default:
			break;
		}
		
	}
	

}


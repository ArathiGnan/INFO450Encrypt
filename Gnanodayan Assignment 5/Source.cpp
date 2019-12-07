#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main()
{
	int i, options, key;
	char str[100];
	string filePath, readData;

	//main Menu
	cout << "\nPlease choose following options:\n";
	cout << "1 = Encrypt.\n";
	cout << "2 = Decrypt.\n";
	cout << "3 = Exit.\n";
	cin >> options;


	switch (options)
	{

	case 1: {


		cout << "\nPlease enter a txt file path:\n";
		cin >> filePath;


		ifstream myfile((filePath).c_str());
		if (myfile.is_open()) { //check If file exist


			//reading From txt file
			stringstream toAppend;
			toAppend << myfile.rdbuf();
			readData = toAppend.str();
			cout << "\nRead string from file:\n" << readData << "\n";
			myfile.close();


			//str to Char conversion
			str[readData.length()];

			for (i = 0; i < sizeof(str); i++) {
				str[i] = readData[i];

			}


			cout << "\nPlease enter a key for encryption (Numbers only):\n";
			cin >> key;


			//the Encryption
			for (i = 0; (i < 100 && str[i] != '\0'); i++) {
				str[i] = str[i] + key; //the key that is added to ASCII value for encryption

			}

			cout << "\nEncrypted string:\n" << str;



			//writing back to the txt file
			ofstream myfile((filePath).c_str());

			if (myfile.is_open()) {
				myfile << str;
				myfile.close();


				return main();

			}
			else {
				cout << "\nUnable to open file!\n";
				return main();

			}



		}
		else {
			cout << "\nUnable to open file!\n";
			return main();

		}


		break;
	}

	case 2: {


		cout << "\nPlease enter a txt file path:\n";
		cin >> filePath;


		ifstream myfile((filePath).c_str());
		if (myfile.is_open()) { //check if file exist


			//reading from txt file
			stringstream toAppend;
			toAppend << myfile.rdbuf();
			readData = toAppend.str();
			cout << "\nRead string from file:\n" << readData << "\n";
			myfile.close();


			//str to Char conversion
			str[readData.length()];

			for (i = 0; i < sizeof(str); i++) {
				str[i] = readData[i];

			}


			cout << "\nPlease enter a key for decryption (Numbers only):\n";
			cin >> key;


			//the Decryption
			for (i = 0; (i < 100 && str[i] != '\0'); i++) {
				str[i] = str[i] - key; //the key that is added to ASCII value for encryption

			}

			cout << "\nDecrypted string:\n" << str;



			//writing Back to the txt file
			ofstream myfile((filePath).c_str());

			if (myfile.is_open()) {
				myfile << str;
				myfile.close();


				return main();

			}
			else {
				cout << "\nUnable to open file!\n";
				return main();

			}
			 


		}
		else {
			cout << "\nUnable to open file!\n";
			return main();

		}


		break;
	}


	case 3: {
		exit(0);
		break;
	}


	default: {

		cout << "\nInvalid Input !!\n";
		break;
	}


	}
	return 0;
}
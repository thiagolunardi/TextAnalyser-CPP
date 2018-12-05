/* test.cpp
Test 6: Dateien und Zeichenketten
Loose, 06.12.2017
*/

#include <stdio.h>#include <iostream>
#include <iostream>
#include "Funktionen.h"
using namespace std;

int main(int argc, char * argv[])
{
	int counter = 0;

	// Kommandozeilen - Abfrage
	char * fname, buffer[80];
	if (argc == 2)
		fname = argv[1];
	else
	// Eingabe über die Tastatur
	{
		//cout << endl;
		//cout << "Geben Sie den Dateinamen ein: ";
		//cin >> buffer;
		printf("\nGeben Sie den Dateinamen ein: ");
		scanf_s("%s", buffer, 80);
		fname = buffer;
	}

	// Test 6
	cout << "\n Test 6" << endl << endl;
	counter = fileHandling1(fname);
	if (counter)
		cout << endl << "Anzahl der '.,?!': " << counter << endl;
	cout << endl;

	// Test 6d
	cout << "\n Test 6d Zählen der .,?!" << endl << endl;
	counter = fileHandling1(fname, countChars);
	if (counter)
		cout << endl << "Anzahl der '.,?!': " << counter << endl;
	cout << endl;

	// Test 6c
	cout << "\n Test 6c Zählen der Ziffern" << endl << endl;
	counter = fileHandling1(fname, countNumbers);
	if (counter)
		cout << endl << "Anzahl der Ziffern: " << counter << endl;
	cout << endl;

	// Test 6b
	cout << "\n Test 6b Zählen der Buchstaben" << endl << endl;
	counter = fileHandling1(fname, countABC);
	if (counter)
		cout << endl << "Anzahl der Buchstaben: " << counter << endl;
	cout << endl;

	// Test 6a
	cout << "\n Test 6a Zählen der Worte" << endl << endl;
	counter = fileHandling1(fname, countWords);
	if (counter)
		cout << endl << "Anzahl der Worte: " << counter << endl;
	cout << endl;

	cout << "\n Test 6a Zählen der Worte - C" << endl << endl;
	counter = fileHandling2(fname, countWords);
	if (counter)
		cout << endl << "Anzahl der Worte: " << counter << endl;
	cout << endl;

	cout << "\n Test 6a Zählen der LowerCase - C" << endl << endl;
	counter = fileHandling2(fname, countLowerCases);
	if (counter)
		cout << endl << "Anzahl der LowerCase: " << counter << endl;
	cout << endl;

	system("pause");
	return 0;
}
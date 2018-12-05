/* Funktionen.cpp
Test 6: Dateien und Zeichenketten
Loose, 06.12.2017
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include "Funktionen.h"
using namespace std;


int fileHandling2(char * fname, int(*function) (char *))
{
	FILE * f1 = NULL;
	fopen_s(&f1,fname,"rt");
	if (f1 == NULL)
	{
		printf("\nDie Datei %s kann nicht geoeffnet werden.",fname);
		return -1;
	}
	else
	{
		int nr = 0, cnt = 0;
		{
			char   buffer[128];
			size_t bytes = 0;
			printf("\n");
			do
			{
				nr += 10;
				fgets(buffer, 128, f1);
				printf("%3d \t %s",nr,buffer);
				cnt += function(buffer);
			} while (!feof(f1));
		}
		fclose(f1);
		return cnt;
	}
}

int fileHandling1(char * fname, pF function)
{
	ifstream f1(fname, ios::in);
	if (!f1.is_open())
	{
		cerr << "\nDie Datei " << fname << " kann nicht geoeffnet werden.";
		return -1;
	}
	else
	{
		int nr = 0, cnt = 0;
		{
			char   buffer[128];
			size_t bytes = 0;
			cout << endl;
			do
			{
				nr += 10;
				f1.getline(buffer, 128);
				cout << nr << '\t' << buffer << endl;
				if (function) cnt += function(buffer);
			} while (!f1.eof());
		}
		f1.close();
		return cnt;
	}
}

int countWords(char * txt)
{
	int cnt = 0;
	char c;
	while (c = *txt++)
	{
		if (c == 32) cnt++;
	}
	//if (cnt > 0) cnt++;
	return cnt;
}

int countABC(char * txt)
{
	int cnt = 0;
	char c;
	while (c = *txt++)
	{
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') 
			|| 'ä' == c || 'ö' == c || 'ü' == c 
			|| 'Ä' == c || 'Ö' == c || 'Ü' == c) cnt++;
	}
	//if (cnt > 0) cnt++;
	return cnt;
}

int countNumbers(char * txt)
{
	int cnt = 0;
	char c;
	while (c = *txt++)
	{
		if ('0' <= c && c <= '9') cnt++;
	}
	//if (cnt > 0) cnt++;
	return cnt;
}

int countChars(char * txt)
{
	int cnt = 0;
	char c;
	while (c = *txt++)
	{
		if ('.' == c || ',' == c || '?' == c || '!' == c ) cnt++;
	}
	//if (cnt > 0) cnt++;
	return cnt;
}

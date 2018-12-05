#pragma once
/* Funktionen.h
Test 6: Dateien und Zeichenketten
Loose, 06.12.2017
*/
typedef int (*pF) (char *);

int fileHandling2(char * fname, int(*function) (char *) = NULL);
int fileHandling1(char * fname, pF function = NULL);
int countWords(char * txt);
int countABC(char * txt);
int countNumbers(char * txt);
int countChars(char * txt);
int countLowerCases(char * txt);

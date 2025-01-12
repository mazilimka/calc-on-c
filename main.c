#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int compareStrings(char *userStr, char *myStr);
float calc();
int chooseProgram();
int repeatMenu();

int main(int argc, char *argv[]) {
	chooseProgram();
	return 0;
}

int repeatMenu() {
	char inputChoice;
	printf("Repeat it: y or n \n");

//	_flushall();
	while (getchar() != '\n');
	scanf("%c", &inputChoice);
	if (inputChoice == 'y')
		chooseProgram();
	else if (inputChoice == 'n')
		exit(0);
	else {
		printf("Only y or n.\n");
		repeatMenu();
	}
	return 0;
}

int chooseProgram() {
	char program1[] = "calc";
	char inputProgram[100];
	printf("Available programs: calc, ...\n");
	printf("Input needs program: ");
	
	_flushall();
	scanf("%99[^\n]", inputProgram);
	if (compareStrings(inputProgram, program1) == 1) {
		printf("You choose: %s\n", inputProgram);
		calc();
	}
	else {
		printf("Such program is not exist, choose a another program.");
		chooseProgram();
	}
	repeatMenu();
	return 0;
}

float calc() {
	float res = 0;
	float n1;
	float n2;
	char sign;
	printf("Input two numbers and sign between numbers: \n");
	_flushall();
	scanf("%f %c %f", &n1, &sign, &n2);
	if (sign == '+') res = res = n1 + n2;
	if (sign == '-') res = res = n1 - n2;
	if (sign == '*') res = res = n1 * n2;
	if (sign == '/') res = res = n1 / n2;
	printf("%f\n", res);
	return 0.0f;
}

int compareStrings(char *userStr, char myStr[]) {
	int sizeUserStr = 0;
	for (int i = 0; i < 100; i++) {
		if (userStr[i] == '\0') 
			break;
		sizeUserStr++;
	}
	int sizeMyStr = strlen(myStr);
	if ((sizeMyStr < sizeUserStr) || (strlen(myStr) > sizeUserStr))
		return -1;
	for (int i = 0; i < sizeMyStr; i++) {
		if (userStr[i] == myStr[i]) 
			continue;
		else
			return -1;
	}
	return 1;
}
#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
int XOR(int a, int gamm)
{
    return (a ^ gamm);
}
int Cyclic_shift(int a_gamm)
{
	return ((a_gamm << 2 ) | (a_gamm >> 6));
}
int Reverse_Cyclic_Shift(int a_res)
{
	return ((a_res >> 2) | (a_res << 6));
}
int Reverse_XOR(int a_pre_gamm, int gamm) {
	return (a_pre_gamm ^ gamm);
}
int main()
{
	char inpt[256];
	int key;
	cout << "Input: " << endl;
	cin.getline(inpt, 256);
	cout << "Input key: " << endl;
	cin >> key;
	cin.clear();
	srand(key);
	int bff = rand();
	int gamm = bff % 128;
	int n = 0;
	for (int i = 0; inpt[i] != '\0'; i++)
		n++;
	char *fraza = (char *)malloc(n * sizeof(char));
	for (int i = 0; i < n; i++)
		fraza[i] = inpt[i];
	int *buffer = (int *)malloc(n * sizeof(int));
	cout << endl << "XOR: ";
	for (int i = 0; i < n; i++) {
		buffer[i] = XOR(fraza[i], gamm);
		putchar(buffer[i]);
	}
	cout << endl << "Cyclic shift: ";
	for (int i = 0; i < n; i++) {
		buffer[i] = Cyclic_shift(buffer[i]);
		putchar(buffer[i]);
	}
	cout << endl << "Reverse cyclic shift: ";
	for (int i = 0; i < n; i++) {
		buffer[i] = Reverse_Cyclic_Shift(buffer[i]);
		putchar(buffer[i]);
	}
	cout << endl << "Reverse XOR: ";
	for (int i = 0; i < n; i++){
		buffer[i] = Reverse_XOR(buffer[i],gamm);
		putchar(buffer[i]);
	}
	cout << "\n";
	system("pause"); 
	return 0;
}


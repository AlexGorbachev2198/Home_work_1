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
	cout << endl << "XOR: ";
	for (int i = 0; i <n; i++)
		putchar(XOR((int)fraza[i],gamm));
	cout << endl << "Cyclic shift: ";
	for (int i = 0; i < n; i++)
		putchar(Cyclic_shift(XOR((int)fraza[i], gamm)));
	int key1 = key+1;
	while (key1 != key)
	{
		cout << "\nInput key: " << endl;
		cin >> key1;
	}
	cout << endl << "Reverse cyclic shift: ";
	for (int i = 0; i < n; i++)
		putchar(Reverse_Cyclic_Shift(Cyclic_shift(XOR((int)fraza[i], gamm))));
	cout << endl << "Reverse XOR: ";
	for (int i = 0; i < n; i++) 
		putchar(Reverse_XOR(Reverse_Cyclic_Shift(Cyclic_shift(XOR((int)fraza[i], gamm))), gamm));
	free(fraza);
	cout << "\n";
	system("pause"); 
	return 0;
}


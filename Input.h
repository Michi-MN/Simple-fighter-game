#pragma once //Gör så att kompilatorn inte läser filen med fighter klassen mer än en gång
#include <iostream> //Ger tillgång till input och output till skärmen
#include <ctime> //Ger tillgång till rand och srand
//#include "Fighter.h" //Inkludering av header filen Fighter med fighter klassen
using namespace std;

int felinput(int min, int max)
{
	int tal;
	cin >> tal;
	while (!cin || tal<min || tal>max)/*För att den ska säga att något är fel
										om ett ogiltigt tal skrivs in*/
	{
		cin.clear();//Rensar/nollställer objektet cin
		cin.ignore(1024, '\n');//Ignorerar allt fram till att någon tryckt enter
		cout << "Invalid input, enter a new number please" << endl;
		cin >> tal;
	}
	//cin.ignore(1024, '\n');//ignorerar tal som inte kan skrivas ut
	return tal;//Skickar tillbaka värdet som kan användas när funktionen input används
}

int felinput2()//har inga parametrar, returnerar ett godkänt tal
{
	int gissning;
	cin >> gissning;
	while (!cin)//kollar om gissningen är ett nummer, utför satsen om det är något annat
	{
		cin.clear();//Rensar/nollställer objektet cin
		cin.ignore(1024, '\n'); // ignorerar tal som inte kan skrivas ut
		cout << "Invalid input, enter a new number please" << endl;
		cin >> gissning;

	}
	cin.ignore(1024, '\n');//ignorerar tal som inte kan skrivas ut
	return gissning;//returnerar ett värde som är godkänt
}

int felinput3(int min)// söker efter tal mindre än det angivna och bokstäver
{
	int tal;
	cin >> tal;
	while (!cin || tal<min )/*För att den ska säga att något är fel
										om ett ogiltigt tal skrivs in*/
	{
		cin.clear();//Rensar/nollställer objektet cin
		cin.ignore(1024, '\n');//Ignorerar allt fram till att någon tryckt enter
		cout << "Invalid input, enter a new number please" << endl;
		cin >> tal;
	}
	//cin.ignore(1024, '\n');//ignorerar tal som inte kan skrivas ut
	return tal;//Skickar tillbaka värdet som kan användas när funktionen input används
}

bool answer(char a, char b)
{
	char c;
	cin >> c;
	if (c == 'Y' || c == 'y')
		return c;
	else
		return 0;
}

bool dubblett(int* i, int loop)//tar emot pekare till ett fält och ett värde
{
	for (int k = 0; k < loop; ++k)
		if (i[loop] == i[k])/*kollar om det angivna värdet på den nuvarande platsen
							i fältet är samma som något som angivits tidigare*/
		{
			cout << "It's a copy" << endl;
			return true;//returnerar true om det är en dubblett
		}
	return false;//returnerar false om det är ett nytt värde
}

int Dice(int ggr, int die) //Tar emot antalet gånger den ska ta fram ett tal och mellan vilka tal talet får vara
{
	int summa = 0; //Deklaration och definition av summa med startvärde 0
	int* nummer = new int[ggr]; //Dynamisk minnesallokering
	srand(unsigned int(time(nullptr))); //Sätter ett frö som är så många sekunder sedan det var midnatt 1 januari 1970
	for (int k = 0; k < ggr; ++k) //Upprepar loopen så många gånger som funktionen fått med sig
	{
		nummer[k] = 1+rand()%die; //Tar fram ett random nummer mellan 1 och det nummer funktionen fått med sig
		summa += nummer[k]; //Lägger till det framtagna nummret i summa
	}
	return summa; //returnerar summan
}

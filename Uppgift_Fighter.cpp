#pragma once //Gör så att kompilatorn inte läser filen med fighter klassen mer än en gång
#include <iostream> //Ger tillgång till input och output till skärmen
#include "Fighter.h" //Inkludering av header filen Fighter med fighter klassen
using namespace std;

int felinput(int min, int max); //Rad 6 är deklaration av funktion som finns i en annan fil men ska användas i denna fil

int main()
{
	int antal, fiende, handling, k = 0; //Deklaration av variabler
	cout << "How many players?" << endl;
	antal = felinput(2, 5); /*Använder funktionen input för att sätta gränser på hur många
						spelare man får vara och kollar efter inmatnings fel*/
	Fighter* spelare[] = { nullptr,nullptr,nullptr,nullptr,nullptr }; /*Skapar ett fält med fem spelare med datatypen pekare
																		till Fighter och sätter alla platser till nullptr*/
	for (int i = 0; i < antal; ++i)
	{
		cout << "Player " << i + 1 << endl;
		spelare[i] = new Fighter; /*Dynamiskt minnesallokerar varje spelare separat, detta gör att man kan ta
									bort ett objekt utan att ta bort alla i fältet*/
	}
	int* död = new int[antal]; //Dynamiskt minnesallokerar ett fält för döda spelare
	while (Fighter::levande > 1) //Kollar om antalet levande spelare är större än 1
	{
		k %= antal; //Spelarindexen blir den nuvarande indexen modulus antalet spelare och blir 0 när indexet är samma som antalet spelare
		if (död[k] == k)//Kollar om spelaren finns i fältet med döda spelare
		{
			++k;
			continue; //Hoppar till nästa runda om spelarens index finns i det döda fältet
		}
		cout << "Player "<< k+1 << " what would you like to do? " << endl << "1. Attack" << endl
			<< "2. Heal" << endl << "3. Commit suicide" << endl;
		handling = felinput(1, 3); /*Använder funktionen input för att sätta gränser på vilka handlingar
									 man får utföra och kollar efter inmatnings fel*/
		switch (handling) //Kollar vilket av kraven nedan som handling klarar
		{
		case(3): //Om handling=3
		{
			död[k] = k; //Sätter spelarens index till samma plats i det döda fältet
			spelare[k]->~Fighter(); //Anropar destruktorn
			++k; //Läger till ett på indexen
			break; //Avslutar switch satsen om detta har utförs
		}
		case(2): //Om handling=2
		{
			spelare[k]->Heal(k + 1); //Åkallar funktionen Heal för den nuvarande spelaren
			++k; //Läger till ett på indexen
			break; //Avslutar switch satsen om detta har utförs
		}
		case(1): //Om handling=1
		{
			cout << "Who would you like to attack?" << endl << "Player: ";
			fiende = felinput(1, antal);  /*Använder funktionen input för att sätta gränser på vilka
										spelare man får attackera och kollar efter inmatnings fel*/
			while (!spelare[k]->attack(spelare[fiende - 1], fiende)) //Kollar om man har skrivit in en ogiltig motståndare
				fiende = felinput(1, antal); /*Använder funktionen input för att sätta gränser på hur många
												spelare man får vara och kollar efter inmatnings fel*/
			if (spelare[fiende - 1]->getHP() <= 0) //Kollar om motståndarens hp är 0 eller mindre med funktionen getHP
			{
				spelare[fiende - 1]->~Fighter(); //Anropar destruktorn för motståndren
				död[fiende - 1] = (fiende - 1); //Sätter motståndarens index på samma plats i det döda fältet
			}
			++k; //Läger till ett på indexen
			break; //Avslutar switch satsen om detta har utförs
		}
		}
	}
	cout << "The game has ended" << endl << "The winner is Player " << (k %= antal)+1 << endl
		<< "Congratulations!"; //Skriver it vinnarens namn med hjälp av funktionen getName
}
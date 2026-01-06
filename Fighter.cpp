#pragma once //Gör så att kompilatorn inte läser filen med fighter klassen mer än en gång
#include "Fighter.h" //Inkludering av header filen Fighter med fighter klassen
#include <iostream> //Ger tillgång till input och output till skärmen
using namespace std;

int felinput(int min, int max); /*Rad 6 - 7 är deklarationer av funktioner som finns i en annan 
								fil men ska användas i denna fil*/
int Dice(int ggr,int die);
int Fighter::levande = 0; //Definition av den statiska datamedlemmen levande med startvärde 0

Fighter::Fighter() //Definition av konstruktorn
{
	++levande; //Lägger till ett på den statiska datamedlemmen levande
	int type;
	cout << "what would you like to play as?" << endl << "1. Warrior" << endl
		<< "2. Wizard" << endl << "3. Monk" << endl;
	type = felinput(1, 3); /*Använder funktionen input för att sätta gränser på vilka alternativ
						 man får välja och kollar efter inmatnings fel*/
	cout << endl;
	switch (type) //Kollar vilket av kraven nedan som type klarar
	{
	case(3): //Om type=3
	{
		health = 70; /*Sätter startvärden för de olika variabler som är deklarerade i 
						klassen för detta specifika objekt baserat på vad type har för värde
						rad 24-32, 37-43 och 48-54*/
		AC = 10;
		healing = 25;
		damage_die = 10;
		rolls = 1;
		damage_bonus = 1;
		max_health = 70;
		break; //Avslutar switch satsen om detta har utförs
	}
	case(2): //Om type=2
	{
		health = 65;
		AC = 10;
		healing = 20;
		damage_die = 6;
		rolls = 3;
		damage_bonus = 0;
		max_health = 55;
		break; //Avslutar switch satsen om detta har utförs
	}
	case(1): //Om type=1
	{
		health = 80;
		AC = 13;
		healing = 20;
		damage_die = 8;
		rolls = 1;
		damage_bonus = 2;
		max_health = 100;
		break; //Avslutar switch satsen om detta har utförs
	}
	}
}

Fighter::~Fighter() //Definition av destruktorn
{	
	--levande; //Tar bort ett från levande
	cout << "This player is now dead" << endl << endl;
}

int Fighter::attack(Fighter* opponent, int fiende) //Definition av medlemmsfunktionen attack
{
	if ((opponent == this)||(opponent->health<1)) //Kollar om motståndaren är spelaren själv eller en död spelare
	{
		cout << "You cannot attack this person!" << endl;
		return 0; //Returnerar 0 om ovanstående är sant
	}
	int skada, anfall = Dice(1,20); /*Deklarerar variablerna skada och anfall där anfall får ett värde 
									från funktionen Dice med parametrarna 1 och 20*/
	cout << "Attack roll was: " << anfall<<endl;
	if (anfall == 20)
	{
		cout << "Attack succeeded" << endl << "Critical hit" << endl;
		skada = (Dice((2*rolls), damage_die) + (2*damage_bonus));
		opponent->health -= skada; //Tar bort skadan från motståndarens hälsa
		cout << "Total damage is: " << skada << endl;
	}
	else if(anfall >= opponent->AC) //Jämför anfall med motståndarens AC
	{
		cout << "Attack succeeded" << endl;
		skada = (Dice(rolls, damage_die) + damage_bonus); /*Definierar skada och ger värde med hjälp av funktionen Dice
															plus en skadebonus. Dice använder objektets 
															variabler rolls och damage_die för att ta reda på
															vilken typ av tärning som används och hur många gånger*/
		opponent->health -= skada; //Tar bort skadan från motståndarens hälsa
		cout << "Total damage is: " << skada << endl;
	}
	else
		cout << "Attack failed" << endl;
	cout << "Player " << fiende << " has " << opponent->health << " HP left." << endl << endl;
	return 1;
}

void Fighter::Heal(int spelare) //Definition av medlemmsfunktionen Heal
{
	health += healing; //Lägger till objektets healing till dess hälsa
	if (health > max_health) //Kollar om objektets hälsa går över maxhälsan
		health = max_health; //Sätter hälsan till maxhälsan
	cout << "Player " << spelare << "'s health is now at " << health << endl << endl;
}

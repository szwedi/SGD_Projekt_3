// Othello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char plansza[7][7];

	vector <int> x;
	vector <int> y;

/*
 |0|1|2|3|4|5|6|7|
0| | | | | | | | |
1| | | | | | | | |
2| | | | | | | | |
3| | | |W|B| | | |
4| | | |B|W| | | |
5| | | | | | | | |
6| | | | | | | | |
7| | | | | | | | |
*/
	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0 ; j<8 ; j++)
		{
			plansza[j][i] = 'E';
		}
	}

//E - empty
//W - white
//B - black

	plansza[3][3] = 'W';
	plansza[4][3] = 'B';
	plansza[3][4] = 'B';
	plansza[4][4] = 'W';

//--------------------------
// zaczyna bia³y

	for (int kolejka=0 ; kolejka<60 ; kolejka++)
	{
		if (kolejka%2 == 0) // bia³y
		{
		//--------------------------
			for (int i=0 ; i<8 ; i++)
			{
				for (int j=0 ; j<8 ; j++)
				{
					if (plansza[j][i] == 'B')
					{
						//sprawdzanie gora
						if (i>0 && plansza[j][i-1] == 'E')
						{
							for (int ile=0 ; ile<7-i ; ile++)
							{
								if (plansza[j][i+1+ile] == 'W')
								{
									x.push_back(j);
									y.push_back(i-1);
								}
							}
						}
						//sprawdzanie dol
						if (i<7 && plansza[j][i+1] == 'E')
						{
							for (int ile=0 ; ile<i ; ile++)
							{
								if (plansza[j][i-1-ile] == 'W')
								{
									x.push_back(j);
									y.push_back(i+1);
								}
							}
						}
						//sprawdzanie lewo
						if (j>0 && plansza[j-1][i] == 'E')
						{
							for (int ile=0 ; ile<7-i ; ile++)
							{
								if (plansza[j+1+ile][i] == 'W')
								{
									x.push_back(j-1);
									y.push_back(i);
								}
							}
						}
						//sprawdzanie prawo
						if (j<7 && plansza[j+1][i] == 'E')
						{
							for (int ile=0 ; ile<i ; ile++)
							{
								if (plansza[j-1-ile][i] == 'W')
								{
									x.push_back(j+1);
									y.push_back(i);
								}
							}
						}
					}
				}
			}
			cout << "White can play:" << endl;
		//--------------------------
		}
		if (kolejka%2 == 1) // czarny
		{
		//--------------------------
			for (int i=0 ; i<8 ; i++)
			{
				for (int j=0 ; j<8 ; j++)
				{
					if (plansza[j][i] == 'W')
					{
						//sprawdzanie gora
						if (i>0 && plansza[j][i-1] == 'E')
						{
							for (int ile=0 ; ile<7-i ; ile++)
							{
								if (plansza[j][i+1+ile] == 'B')
								{
									x.push_back(j);
									y.push_back(i-1);
								}
							}
						}
						//sprawdzanie dol
						if (i<7 && plansza[j][i+1] == 'E')
						{
							for (int ile=0 ; ile<i ; ile++)
							{
								if (plansza[j][i-1-ile] == 'B')
								{
									x.push_back(j);
									y.push_back(i+1);
								}
							}
						}
						//sprawdzanie lewo
						if (j>0 && plansza[j-1][i] == 'E')
						{
							for (int ile=0 ; ile<7-i ; ile++)
							{
								if (plansza[j+1+ile][i] == 'B')
								{
									x.push_back(j-1);
									y.push_back(i);
								}
							}
						}
						//sprawdzanie prawo
						if (j<7 && plansza[j+1][i] == 'E')
						{
							for (int ile=0 ; ile<i ; ile++)
							{
								if (plansza[j-1-ile][i] == 'B')
								{
									x.push_back(j+1);
									y.push_back(i);
								}
							}
						}
					}
				}
			}
			cout << "Black can play:" << endl;
		//--------------------------
		}
		for (int mozliwosci=0 ; mozliwosci<x.size() ; mozliwosci++)
			cout << "x[" << mozliwosci << "] = " << x[mozliwosci] << "  " << "y[" << mozliwosci << "] = " << y[mozliwosci] << endl;
		cout << endl;
		x.clear();
		y.clear();
	}



//-------------------------- wyswietlanie koncowego wyniku

	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0 ; j<8 ; j++)
		{
			cout << plansza[j][i] << " ";
		}
		cout << endl;
	}

//-------------------------------

	getch();
	return 0;
}


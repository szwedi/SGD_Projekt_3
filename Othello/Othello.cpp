// Othello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512   //domyslnty bufor
#define DEFAULT_PORT "27015"  // domyslny port

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
/*	
	WSADATA wsaData;
	int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket1 = INVALID_SOCKET;  //dklaracja socketow
	SOCKET ClientSocket2 = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result); // podaje port na jakim dziala
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

	cout << "Wait for ClientSocket1 and ClientSocket2" << endl;

    // Accept a client socket 1
    ClientSocket1 = accept(ListenSocket, NULL, NULL);
    if (ClientSocket1 == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

	// Accept a client socket 2
    ClientSocket2 = accept(ListenSocket, NULL, NULL);
    if (ClientSocket2 == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
*/
//-------------------------------------------------------------------------------------------

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

	boolean wpisano;
	int tmpX;
	int tmpY;
	int tmpXX;
	int tmpYY;

	int ile_ruchow;
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
							wpisano = false;
							for (int ile=0 ; ile<7-i ; ile++)
							{
								if (plansza[j][i+1+ile] == 'W' && wpisano == false)
								{
									x.push_back(j);
									y.push_back(i-1);
									wpisano = true;
								}
							}
						}
						//sprawdzanie dol
						if (i<7 && plansza[j][i+1] == 'E')
						{
							wpisano = false;
							for (int ile=0 ; ile<i ; ile++)
							{
								if (plansza[j][i-1-ile] == 'W' && wpisano == false)
								{
									x.push_back(j);
									y.push_back(i+1);
									wpisano = true;
								}
							}
						}
						//sprawdzanie lewo
						if (j>0 && plansza[j-1][i] == 'E')
						{
							wpisano = false;
							for (int ile=0 ; ile<7-i ; ile++)
							{
								if (plansza[j+1+ile][i] == 'W' && wpisano == false)
								{
									x.push_back(j-1);
									y.push_back(i);
									wpisano = true;
								}
							}
						}
						//sprawdzanie prawo
						if (j<7 && plansza[j+1][i] == 'E')
						{
							wpisano = false;
							for (int ile=0 ; ile<i ; ile++)
							{
								if (plansza[j-1-ile][i] == 'W' && wpisano == false)
								{
									x.push_back(j+1);
									y.push_back(i);
									wpisano = true;
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
							wpisano = false;
							for (int ile=0 ; ile<7-i ; ile++)
							{
								if (plansza[j][i+1+ile] == 'B' && wpisano == false)
								{
									x.push_back(j);
									y.push_back(i-1);
									wpisano = true;
								}
							}
						}
						//sprawdzanie dol
						if (i<7 && plansza[j][i+1] == 'E')
						{
							wpisano = false;
							for (int ile=0 ; ile<i ; ile++)
							{
								if (plansza[j][i-1-ile] == 'B' && wpisano == false)
								{
									x.push_back(j);
									y.push_back(i+1);
									wpisano = true;
								}
							}
						}
						//sprawdzanie lewo
						if (j>0 && plansza[j-1][i] == 'E')
						{
							wpisano = false;
							for (int ile=0 ; ile<7-i ; ile++)
							{
								if (plansza[j+1+ile][i] == 'B' && wpisano == false)
								{
									x.push_back(j-1);
									y.push_back(i);
									wpisano = false;
								}
							}
						}
						//sprawdzanie prawo
						if (j<7 && plansza[j+1][i] == 'E')
						{
							wpisano = false;
							for (int ile=0 ; ile<i ; ile++)
							{
								if (plansza[j-1-ile][i] == 'B' && wpisano == false)
								{
									x.push_back(j+1);
									y.push_back(i);
									wpisano = true;
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

		//******************************************************************************//
		if (kolejka%2 == 0) // bia³y
		{
			int  losowanie = rand()%x.size();
			plansza [x[losowanie]][y[losowanie]] = 'W';
			cout << "Gralem " << "X= " << x[losowanie] << " Y= " << y[losowanie] << endl;
			tmpX = x[losowanie];
			tmpY = y[losowanie];

			//do gory
			while (plansza[tmpX][tmpY-1] == 'B')
			{
				if (plansza[tmpX][tmpY-2] == 'W')
				{
					tmpXX = tmpX;
					tmpYY = tmpY-2;
				}
				ile_ruchow = tmpY - tmpYY;
				for (int graj = 0 ; graj < ile_ruchow ; graj++)
				{
					plansza[tmpXX][tmpYY] = 'W';
					tmpYY++;
				}

			}
			//na dol
			while (plansza[tmpX][tmpY+1] == 'B')
			{
				if (plansza[tmpX][tmpY+2] == 'W')
				{
					tmpXX = tmpX;
					tmpYY = tmpY+2;
				}
				ile_ruchow = tmpYY - tmpY;
				for (int graj = 0 ; graj < ile_ruchow ; graj++)
				{
					plansza[tmpXX][tmpYY] = 'W';
					tmpYY--;
				}
			}
			//na lewo
			while (plansza[tmpX-1][tmpY] == 'B')
			{
				if (plansza[tmpX-2][tmpY] == 'W')
				{
					tmpXX = tmpX-2;
					tmpYY = tmpY;
				}
				ile_ruchow = tmpX - tmpXX;
				for (int graj = 0 ; graj < ile_ruchow ; graj++)
				{
					plansza[tmpXX][tmpYY] = 'W';
					tmpXX++;
				}
			}
			//na prawo
			while (plansza[tmpX+1][tmpY] == 'B')
			{
				if (plansza[tmpX+2][tmpY] == 'W')
				{
					tmpXX = tmpX+2;
					tmpYY = tmpY;
				}
				ile_ruchow = tmpXX - tmpX;
				for (int graj = 0 ; graj < ile_ruchow ; graj++)
				{
					plansza[tmpXX][tmpYY] = 'W';
					tmpXX--;
				}
			}
		}
		if (kolejka%2 == 1) // czarny
		{
			int  losowanie = rand()%x.size();
			plansza [x[losowanie]][y[losowanie]] = 'B';
			cout << "Gralem " << "X= " << x[losowanie] << " Y= " << y[losowanie] << endl;
			tmpX = x[losowanie];
			tmpY = y[losowanie];

			//do gory
			while (plansza[tmpX][tmpY-1] == 'W')
			{
				if (plansza[tmpX][tmpY-2] == 'B')
				{
					tmpXX = tmpX;
					tmpYY = tmpY-2;
				}
				ile_ruchow = tmpY - tmpYY;
				for (int graj = 0 ; graj < ile_ruchow ; graj++)
				{
					plansza[tmpXX][tmpYY] = 'B';
					tmpYY++;
				}

			}
			//na dol
			while (plansza[tmpX][tmpY+1] == 'W')
			{
				if (plansza[tmpX][tmpY+2] == 'B')
				{
					tmpXX = tmpX;
					tmpYY = tmpY+2;
				}
				ile_ruchow = tmpYY - tmpY;
				for (int graj = 0 ; graj < ile_ruchow ; graj++)
				{
					plansza[tmpXX][tmpYY] = 'B';
					tmpYY--;
				}
			}
			//na lewo
			while (plansza[tmpX-1][tmpY] == 'W')
			{
				if (plansza[tmpX-2][tmpY] == 'B')
				{
					tmpXX = tmpX-2;
					tmpYY = tmpY;
				}
				ile_ruchow = tmpX - tmpXX;
				for (int graj = 0 ; graj < ile_ruchow ; graj++)
				{
					plansza[tmpXX][tmpYY] = 'B';
					tmpXX++;
				}
			}
			//na prawo
			while (plansza[tmpX+1][tmpY] == 'W')
			{
				if (plansza[tmpX+2][tmpY] == 'B')
				{
					tmpXX = tmpX+2;
					tmpYY = tmpY;
				}
				ile_ruchow = tmpXX - tmpX;
				for (int graj = 0 ; graj < ile_ruchow ; graj++)
				{
					plansza[tmpXX][tmpYY] = 'B';
					tmpXX--;
				}
			}
		}

		for (int i=0 ; i<8 ; i++)
		{
			for (int j=0 ; j<8 ; j++)
			{
				cout << plansza[j][i] << " ";
			}
			cout << endl;
		}

		x.clear();
		y.clear();
		getch();
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

//------------------------------------------------------------------------
/*	
    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket1, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket1);
        WSACleanup();
        return 1;
    }
	iResult = shutdown(ClientSocket2, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket2);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ClientSocket1);
	closesocket(ClientSocket2);
    WSACleanup();

*/

	getch();
	return 0;
}


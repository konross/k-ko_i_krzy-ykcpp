// K�ko i krzy�yk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h> // zawiera funkcje sleep()
#include <conio.h> // conio.h bo tam jest funkcja getch() ktora nie wymaga wcisniecia ENTER`a po wlasciwym klawiszu
#include <ctime> // losowanie licz, time(NULL)
using namespace std;


void start(int komunikat);
void czysc_ekran(); // czy�ci ekran, zostaje tylko tekst pocz�tkowy
void wybor_znaku_i_dane(int opcja);
void rozpocznij_gre(int kogo_ruch); // w tej funkcji rozgrywa si� gra
void rysuj_pola(); // wypisuje pole gry
void sprawdzanie(); // sprawdza czy kto� wygra�


string tab[3][3]={" "," "," "," "," "," "," "," "," "};
string imie;
int gramy_dalej=1;
string zwycieski_znak;
string znak_g="x";
string znak_k="o";
int puste_pola = 0;
string krok;
string pomoc;
int pierwszy_ruch;
int licznik_ruchow=0;

//#################################################################################
int _tmain(int argc, _TCHAR* argv[])
{
	start(0);
	system("pause");
	return 0;
}

//#################################################################################
void start(int komunikat)
{ 
    czysc_ekran();

	cout<<"Wybierz gracza zaczynajacego:\n"
		<<"1) Czlowiek\n"
		<<"2) Komputer\n"
		<<"3) Wyjscie\n\n";

	cout<<"Aby dokonac wyboru wpisz cyfre 1-3 i zatwierdz enterem: ";
	int wybor; 
    cin>>wybor;
 
    if(wybor == 1) 
	{ // gre zaczyna cz�owiek
		pierwszy_ruch=0;
            wybor_znaku_i_dane(0);
    } 
	else if(wybor == 2) 
	{ // gre zaczyna komp
		pierwszy_ruch=1;
            wybor_znaku_i_dane(1);
    } 
	else if (wybor == 3) ; //wyjscie
		
	
}
//#################################################################################
void czysc_ekran() // czy�ci ekran, zostaje tylko tekst poczatkowy
{ 
    system("cls"); 
    cout<<"Witaj w mojej pierwszej grze!\n"
		<<"	Kolko i krzyzyk\n\n";
}
//#################################################################################
void wybor_znaku_i_dane(int opcja) // wartosc opcji przypisywana jest we wczesniejszej funkcji start 
{
	czysc_ekran();
	switch(opcja)
	{
		case 0:
			cout<<"Podaj swoje imie: ";
			cin>>imie;
			cout<<"Witaj: "<<imie<<"\n";
			
			cout<<"\nWybierz znak (X/O): ";
			cin>>znak_g;
			
			if (znak_g=="x" || znak_g=="X")
			 {znak_k="O";}
			else if(znak_g=="o" || znak_g=="O")
			 {znak_k="X";}
			else
			 {
				 cout<<"Wpisales zly znak, dlatego zostanie Ci on przypisany z gory.\n\n";
				 znak_g="X";
				 znak_k="O";
			 }
			
			cout<<"Twoj znak to: "<<znak_g<<"\n\n";
			Sleep(2400);
			rozpocznij_gre(0); // 0-rozpoczyna cz�owiek
			break;
		
		case 1:
			cout<<"Podaj swoje imie: ";
			cin>>imie;
			cout<<"Witaj: "<<imie<<"\n";
			
			cout<<"\nWybierz znak (X/O): ";
			cin>>znak_g;
			
			if (znak_g=="x" || znak_g=="X")
			 {znak_k="O";}
			else if(znak_g=="o" || znak_g=="O")
			 {znak_k="X";}
			else
			 {
				 cout<<"Wpisales zly znak, dlatego zostanie Ci on przypisany z gory.\n\n";
				 znak_g="X";
				 znak_k="O";
			 }
			
			cout<<"Twoj znak to: "<<znak_g<<"\n\n";
			Sleep(2400);
			rozpocznij_gre(1); // 1-rozpoczyna cz�owiek
			break;
	}
}
//#################################################################################
void rozpocznij_gre(int kogo_ruch) // kogo ruch- 0=gracz, 1=komp
{
	rysuj_pola();
	Sleep(800);
	sprawdzanie(); // sprawdza czy kto� wygra� lub wzystkie pola zosta�y zajete. Jesli tak to przerywa gre. jesli nie gra si� zaczyna lub toczy si� dalej
	

	if(kogo_ruch == 0) 
	{ // zaczyna gracz
		krok=35; // 35=#, znak sygnalizuj�cy obecn� pozycje na planszy
		pomoc=tab[0][0]; // zmienna pomocnicza w kt�rej tymczasowo przechowywany jest znak z tanej kom�rki tablicy
		int i=0, j=0;
			tab[i][j]=krok; 
			rysuj_pola(); // wy�wietlana jest tablica z znakiem poruszania si�

			int ruch=0;
			while ((ruch=_getch())!=13)  // dop�ki nie naci�nie si� entera to b�dziemy porusza� si� po planszy
			{
			ruch=_getch();
			switch (ruch)
			  {
			  case 77 :   // ruch w prawo
				  if(j<2) // blokada �eby znak poruszania si� nie wyszed� poza pole gry
				  {
						 tab[i][j]=pomoc; //przypisuje polu w kt�rym sie znajdowalismy jego poprzedni znak, zanim by� tam #
						 j++;
						 pomoc=tab[i][j]; // tymczasowe przechowanie znaku spod kolejnego pola gdzie si� przemie�cili�my
						 tab[i][j]=krok; // wyrysowanie w tym polu znaku poruszania si�
						 rysuj_pola();  
						 break;
				  }
				  else
				  {
						break;
				  }

			  case 75 :   // ruch w lewo
				  if(j>0)
				  {
						 tab[i][j]=pomoc;
						 j--;
						 pomoc=tab[i][j];
						 tab[i][j]=krok;
						 rysuj_pola();
						 break;
				  }
				  else
				  {
					  break;
				  }

			  case 72 :   // ruch w gore
				  if(i>0)
				  {
						 tab[i][j]=pomoc;
						 i--;
						 pomoc=tab[i][j];
						 tab[i][j]=krok;
						 rysuj_pola();
						 break;
				  }
				  else
				  {
					  break;
				  }

			  case 80 :   // ruch w dol
				  if(i<2)
				  {
						 tab[i][j]=pomoc;
						 i++;
						 pomoc=tab[i][j];
						 tab[i][j]=krok;
						 rysuj_pola();
						 break; 
				  }
				  else
				  {
					  break;
				  }
			  }
			}
			// po wci�ni�ciu entera	
			if((pomoc=="X" || pomoc=="x" || pomoc=="O" || pomoc=="o") && licznik_ruchow!=9)
			{
				cout<<"Pole zaj�te! wybierz inne.";
				tab[i][j]=pomoc;
				Sleep(2500);
				rozpocznij_gre(0); // wybranie zaj�tego pola powoduje wywo�anie funkcji jeszcze raz
			}
			else
			{
				tab[i][j]=znak_g; // przypisanie wybranemu polu naszego znaku
				licznik_ruchow++;
				rozpocznij_gre(1); // przekazanie gry do kompa
				
			}
		}
  

         else if(kogo_ruch == 1) 
		 { // zaczyna komp
            if(pierwszy_ruch==1) // czy to pierwszy czy nast�pny ruch kompa. atak
			{ 
				if(licznik_ruchow == 0) // pierwszy ruch kompa
				{
					srand(time(NULL));
					int naroznik = rand()%4;
 
					switch(naroznik) 
					{
						case 0:
							tab[0][0] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 1:
							tab[0][2] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 2:
							tab[2][0] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 3:
							tab[2][2] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
					}
				}

				else if (licznik_ruchow == 2) // drugi ruch kompa
				{
					if (tab[0][0]==znak_k && (tab[0][2]==znak_g || tab[2][0]==znak_g)) // daje swoj drugi znak po przekatnej ;) r�ne znaki w s�siednich naro�nikach
					{
						tab[2][2]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0; // powoduje wykonywanie nast�pnych ruch�w przez kod obrony
						rozpocznij_gre(0);
					}
					else if (tab[0][2] == znak_k && (tab[0][0]==znak_g || tab[2][2]==znak_g)) // daje swoj drugi znak po przekatnej ;)  r�ne znaki w s�siednich naro�nikach
					{
						tab[2][0]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0; // powoduje wykonywanie nast�pnych ruch�w przez kod obrony
						rozpocznij_gre(0);
					}
					else if (tab[2][2] == znak_k && (tab[0][2]==znak_g || tab[2][0]==znak_g)) // daje swoj drugi znak po przekatnej ;)  r�ne znaki w s�siednich naro�nikach
					{
						tab[0][0]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0; // powoduje wykonywanie nast�pnych ruch�w przez kod obrony
						rozpocznij_gre(0);
					}
					else if (tab[2][0] == znak_k && (tab[0][0]==znak_g || tab[2][2]==znak_g)) // daje swoj drugi znak po przekatnej ;)  r�ne znaki w s�siednich naro�nikach
					{
						tab[0][2]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0; // powoduje wykonywanie nast�pnych ruch�w przez kod obrony
						rozpocznij_gre(0);
					}

					else if(tab[0][0] == znak_k && (tab[0][1] == znak_g || tab[2][2] == znak_g || tab[1][2] == znak_g || tab[2][1] == znak_g))
					{ //ten i kolejny if znak kompa w naro�niku, znak gracza w pozosta�ych polach opr�cz �rodka i s�siednich naroznik�w
						tab[2][0]=znak_k;
						licznik_ruchow++;
						if(tab[1][2] == znak_g) pierwszy_ruch=0;
						rozpocznij_gre(0);
					} 
					else if(tab[0][0] == znak_k && tab[1][0] == znak_g)
					{
						tab[0][2]=znak_k;
						licznik_ruchow++;
						rozpocznij_gre(0);
					}
					else if(tab[0][2] == znak_k && (tab[1][2] == znak_g || tab[2][0] == znak_g || tab[2][1] == znak_g || tab[1][0] == znak_g))
					{ //ten i kolejny if znak kompa w naro�niku, znak gracza w pozosta�ych polach opr�cz �rodka i s�siednich naroznik�w
						tab[0][0]=znak_k;
						licznik_ruchow++;
						if(tab[2][1] == znak_g) pierwszy_ruch=0;
						rozpocznij_gre(0);
					}
					else if(tab[0][2] == znak_k && tab[0][1] == znak_g)
					{
						tab[2][2]=znak_k;
						licznik_ruchow++;
						rozpocznij_gre(0);
					}
					else if(tab[2][2] == znak_k && (tab[2][1] == znak_g || tab[0][0] == znak_g || tab[1][0] == znak_g || tab[0][1] == znak_g))
					{ //ten i kolejny if znak kompa w naro�niku, znak gracza w pozosta�ych polach opr�cz �rodka i s�siednich naroznik�w
						tab[0][2]=znak_k;
						licznik_ruchow++;
						if(tab[1][0] == znak_g) pierwszy_ruch=0;
						rozpocznij_gre(0);
					}
					else if(tab[2][2] == znak_k && tab[1][2] == znak_g)
					{
						tab[2][0]=znak_k;
						licznik_ruchow++;
						rozpocznij_gre(0);
					}
					else if(tab[2][0] == znak_k && (tab[1][0] == znak_g || tab[0][2] == znak_g || tab[0][1] == znak_g || tab[1][2] == znak_g))
					{ //ten i kolejny if znak kompa w naro�niku, znak gracza w pozosta�ych polach opr�cz �rodka i s�siednich naroznik�w
						tab[2][2]=znak_k;
						licznik_ruchow++;
						if(tab[0][1] == znak_g) pierwszy_ruch=0;
						rozpocznij_gre(0);
					}
					else if(tab[2][0] == znak_k && tab[2][1] == znak_g)
					{
						tab[0][0]=znak_k;
						licznik_ruchow++;
						rozpocznij_gre(0);
					}
					else if(tab[0][0] == znak_k && tab[1][1] == znak_g) // wstawianie znaku po skosie k g k
					{
						tab[2][2]=znak_k;
						licznik_ruchow++;
						rozpocznij_gre(0);
					}
					else if(tab[0][2] == znak_k && tab[1][1] == znak_g)
					{
						tab[2][0]=znak_k;
						licznik_ruchow++;
						rozpocznij_gre(0);
					}
					else if(tab[2][2] == znak_k && tab[1][1] == znak_g)
					{
						tab[0][0]=znak_k;
						licznik_ruchow++;
						rozpocznij_gre(0);
					}
					else if(tab[2][0] == znak_k && tab[1][1] == znak_g)
					{
						tab[0][2]=znak_k;
						licznik_ruchow++;
						rozpocznij_gre(0);
					}
				} 
				else if(licznik_ruchow == 4) // 3 ruch kompa
				{
					if(tab[0][0] == znak_k && tab[0][1] == znak_g && tab[0][2] == znak_k) // g�rna pozioma linia zaj�ta k g k
					{
						if(tab[1][0]==znak_g || tab[2][0]==znak_g) 
						{
						tab[2][2]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
						}
						else if(tab[1][2]==znak_g || tab[2][2]==znak_g)
						{
						tab[2][0]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
						}
					}
					else if(tab[0][2] == znak_k && tab[1][2] == znak_g && tab[2][2] == znak_k) // prawa pionowa linia zaj�ta k g k
					{
						if(tab[0][1]==znak_g || tab[0][0]==znak_g)
						{
						tab[2][0]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
						}
						else if(tab[2][1]==znak_g || tab[2][0]==znak_g)
						{
						tab[0][0]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
						}
					}
					else if(tab[2][0] == znak_k && tab[2][1] == znak_g && tab[2][2] == znak_k) // dolna pozioma linia zaj�ta k g k
					{
						if(tab[1][0]==znak_g || tab[0][0]==znak_g)
						{
						tab[0][2]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
						}
						else if(tab[1][2]==znak_g || tab[0][2]==znak_g)
						{
						tab[0][0]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
						}
					}
					else if(tab[0][0] == znak_k && tab[1][0] == znak_g && tab[2][0] == znak_k) // lewa pionowa linia zaj�ta k g k
					{
						if(tab[0][1]==znak_g || tab[0][2]==znak_g)
						{
						tab[2][2]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
						}
						else if(tab[2][1]==znak_g || tab[2][2]==znak_g)
						{
						tab[0][2]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
						}
					}
					else if(tab[0][0] == znak_k && tab[1][1] == znak_g && tab[0][2] == znak_g && tab[2][2] == znak_k)
					{
						tab[2][0]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
					}
					else if(tab[0][0] == znak_k && tab[1][1] == znak_g && tab[2][0] == znak_g && tab[2][2] == znak_k)
					{
						tab[0][2]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
					}
					else if(tab[0][2] == znak_k && tab[1][1] == znak_g && tab[0][0] == znak_g && tab[2][0] == znak_k)
					{
						tab[2][2]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
					}
					else if(tab[0][2] == znak_k && tab[1][1] == znak_g && tab[2][2] == znak_g && tab[2][0] == znak_k)
					{
						tab[0][0]=znak_k;
						licznik_ruchow++;
						pierwszy_ruch=0;
						rozpocznij_gre(0);
					}
					else
					{
						pierwszy_ruch=0;
						rozpocznij_gre(1);
					}
				}
			} // koniec kodu ataku
			
			else 
			{   // pierwszy_ruch=0
				// komputer wykonuje ruch po graczu, obrona.
				if (tab[1][1] == znak_g && licznik_ruchow == 1) // je�li na pocz�tku gracz posyawi sw�j znak w �rodku to komputer ma ma�e szanse na wygran� 
				{ // wi�c bd si� broni�a ale jesli nadarzy si� sznsa b�dzie potem te� atakowa�
					goto obrona;
				}
				else if (tab[1][1] == " " && licznik_ruchow == 1) //gracz postawi� sw�j znak w innym miejscu ni� srodek
				{// komputer ma ma�e szanse na wygran� gdy zaczyna cz�owiek wi�c d��y do remisu daj�c znak do �rodka 
					tab[1][1] = znak_k;
					licznik_ruchow++;
					rozpocznij_gre(0);
				}
				else goto obrona;

obrona:
				if(licznik_ruchow == 3 && tab[1][1] == znak_k && tab[0][0] == znak_g && tab[2][2] == znak_g)
				{ // je�li na skos s� 3 znaki a w �rodku jest znak kompa to daje on sw�j znak w losowe miejsce poza naro�nikami bo wtedy przegra
					srand(time(NULL));
					int los = rand()%4;
 
					switch(los) 
					{
						case 0:
							tab[0][1] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 1:
							tab[1][0] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 2:
							tab[2][1] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 3:
							tab[1][2] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
					}
				}

				if(licznik_ruchow == 3 && tab[1][1] == znak_k && tab[2][0] == znak_g && tab[0][2] == znak_g)
				{
					srand(time(NULL));
					int los = rand()%4;
 
					switch(los) 
					{
						case 0:
							tab[0][1] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 1:
							tab[1][0] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 2:
							tab[2][1] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
						case 3:
							tab[1][2] = znak_k;
							licznik_ruchow++;
							rozpocznij_gre(0);
					}
				}

				for (int kol=0; kol<3; kol++) // sprawdzanie czy komputer ma gdzie� mozliwo�� wygranej
					{
					for (int wiersz=0; wiersz<3; wiersz++)
						{
							// spr wiersze
							if(tab[wiersz][0] == tab[wiersz][1] && tab[wiersz][0] == znak_k && tab[wiersz][2] == " ") 
								{
									tab[wiersz][2]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
							else if(tab[wiersz][1] == tab[wiersz][2] && tab[wiersz][1] == znak_k && tab[wiersz][0] == " ") 
								{
									tab[wiersz][0]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
							else if(tab[wiersz][0] == tab[wiersz][2] && tab[wiersz][0] == znak_k && tab[wiersz][1] == " ") 
								{
									tab[wiersz][1]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
						
							
							// spr w kolumnach
							else if(tab[0][kol] == tab[1][kol] && tab[0][kol] == znak_k && tab[2][kol] == " ") 
								{
									tab[2][kol]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
							else if(tab[1][kol] == tab[2][kol] && tab[1][kol] == znak_k && tab[0][kol] == " ") 
								{
									tab[0][kol]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
							else if(tab[0][kol] == tab[2][kol] && tab[0][kol] == znak_k && tab[1][kol] == " ") 
								{
									tab[1][kol]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
						}
					}
										
							// sprawdzenie po skosie "/", sprawdzanie czy komputer ma gdzie� mozliwo�� wygranej
							if(tab[2][0] == tab[1][1] && tab[2][0] == znak_k && tab[0][2] == " ") 
							{
								tab[0][2]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[2][0] == tab[0][2] && tab[2][0] == znak_k  && tab[1][1] == " ") 
							{
								tab[1][1]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[1][1] == tab[0][2] && tab[1][1] == znak_k && tab[2][0] == " ") 
							{
								tab[2][0]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
		
							// sprawdzanie po skosie "\" sprawdzanie czy komputer ma gdzie� mozliwo�� wygranej
							else if(tab[0][0] == tab[1][1] && tab[0][0] == znak_k && tab[2][2] == " ") 
							{
								tab[2][2]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[2][2] == tab[1][1] && tab[2][2] == znak_k && tab[0][0] == " ") 
							{
								tab[0][0]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[2][2] == tab[0][0] && tab[2][2] == znak_k && tab[1][1] == " ") 
							{
								tab[1][1]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
						

				for (int kol=0; kol<3; kol++) // blokowanie rzeciwnika, sprawdzanie podobne jak wcze�niej
					{
					for (int wiersz=0; wiersz<3; wiersz++)
						{
							// spr wiersze
							if(tab[wiersz][0] == tab[wiersz][1] && tab[wiersz][0] !=" " && tab[wiersz][2] == " ") 
								{
									tab[wiersz][2]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
							else if(tab[wiersz][1] == tab[wiersz][2] && tab[wiersz][1] !=" " && tab[wiersz][0] == " ") 
								{
									tab[wiersz][0]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
							else if(tab[wiersz][0] == tab[wiersz][2] && tab[wiersz][0] !=" " && tab[wiersz][1] == " ") 
								{
									tab[wiersz][1]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
						
							
							// spr w kolumnach
							else if(tab[0][kol] == tab[1][kol] && tab[0][kol] !=" " && tab[2][kol] == " ") 
								{
									tab[2][kol]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
							else if(tab[1][kol] == tab[2][kol] && tab[1][kol] !=" " && tab[0][kol] == " ") 
								{
									tab[0][kol]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
							else if(tab[0][kol] == tab[2][kol] && tab[0][kol] !=" " && tab[1][kol] == " ") 
								{
									tab[1][kol]=znak_k;
									licznik_ruchow++;
									rozpocznij_gre(0);
								}
						}
					}
										
							// sprawdzenie po skosie "/"
							if(tab[2][0] == tab[1][1] && tab[2][0] !=" " && tab[0][2] == " ") 
							{
								tab[0][2]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[2][0] == tab[0][2] && tab[2][0] !=" "  && tab[1][1] == " ") 
							{
								tab[1][1]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[1][1] == tab[0][2] && tab[1][1] !=" " && tab[2][0] == " ") 
							{
								tab[2][0]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
		
							// sprawdzanie po skosie "\"
							else if(tab[0][0] == tab[1][1] && tab[0][0] !=" " && tab[2][2] == " ") 
							{
								tab[2][2]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[2][2] == tab[1][1] && tab[2][2] !=" " && tab[0][0] == " ") 
							{
								tab[0][0]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[2][2] == tab[0][0] && tab[2][2] !=" " && tab[1][1] == " ") 
							{
								tab[1][1]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							} 
							else if(tab[2][1] == tab[0][0] && tab[2][1] == znak_g && tab[1][1] == znak_k && licznik_ruchow == 3) // brakuj�ca cz�� ^^
							{
								tab[1][2]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							}
							else if(tab[2][1] == tab[0][2] && tab[2][1] == znak_g && tab[1][1] == znak_k && licznik_ruchow == 3) // brakuj�ca cz�� ^^
							{
								tab[1][2]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							}
							else if(tab[1][2] == tab[2][0] && tab[1][2] == znak_g && tab[1][1] == znak_k && licznik_ruchow == 3) // brakuj�ca cz�� ^^
							{
								tab[0][2]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							}
							else if(tab[1][2] == tab[0][0] && tab[1][2] == znak_g && tab[1][1] == znak_k && licznik_ruchow == 3) // brakuj�ca cz�� ^^
							{
								tab[0][2]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							}
							else if(tab[1][1] == tab[2][2] && tab[1][1] == znak_g && tab[0][0] == znak_k && licznik_ruchow == 3) // brakuj�ca cz�� ^^
							{
								tab[2][0]=znak_k;
								licznik_ruchow++;
								rozpocznij_gre(0);
							}

				
						else //wstawianie znaku w pierwsze napotkane wolne miejsce gdy� nie ma to ju� znaczenia, komputer na pewno nie przegra
						{
							for (int kol=0; kol<3; kol++)
							{
								for (int wiersz=0; wiersz<3; wiersz++)
								{
									if(tab[wiersz][kol] == " ")
									{
										tab[wiersz][kol]=znak_k;
										licznik_ruchow++;
										rozpocznij_gre(0);
									}
								}
							}
						}
				}
			}

}
//#################################################################################
void rysuj_pola()
{
	czysc_ekran();
	
	cout<<"     |     |     \n"
        <<"  ";
		if(tab[0][0]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ustawia kolor znaku poruszania si�
				cout<<tab[0][0];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // przywrace domy�lny kolor dalszej cz�ci tabeli i znakom
			}
		else
			{
				cout<<tab[0][0];
			}	
	cout<<"  |  ";
		if(tab[0][1]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<tab[0][1];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		else
			{
				cout<<tab[0][1];
			}
	cout<<"  |  ";
		if(tab[0][2]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<tab[0][2];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		else
			{
				cout<<tab[0][2];
			}
	cout<<"  \n"
		<<"     |     |     \n"
		<<"-----+-----+-----\n"
		<<"     |     |     \n"
        <<"  ";
		if(tab[1][0]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<tab[1][0];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		else
			{
				cout<<tab[1][0];
			}
	cout<<"  |  ";
		if(tab[1][1]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<tab[1][1];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		else
			{
				cout<<tab[1][1];
			}
	cout<<"  |  ";
		if(tab[1][2]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<tab[1][2];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		else
			{
				cout<<tab[1][2];
			}
	cout<<"  \n"
		<<"     |     |     \n"
		<<"-----+-----+-----\n"
		<<"     |     |     \n"
		<<"  ";
		if(tab[2][0]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<tab[2][0];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		else
			{
				cout<<tab[2][0];
			}
	cout<<"  |  ";
		if(tab[2][1]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<tab[2][1];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		else
			{
				cout<<tab[2][1];
			}
	cout<<"  |  ";
		if(tab[2][2]==krok)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<tab[2][2];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		else
			{
				cout<<tab[2][2];
			}
	cout<<"  \n"
		<<"     |     |     \n\n\n";
}
//#################################################################################
void sprawdzanie()
{
// poziome i pionowe sprawdzenie czy wystepuja 3 znaczki obok siebie

for (int kol=0; kol<3; kol++)
	{
		for (int wiersz=0; wiersz<3; wiersz++)
			{

				if((tab[wiersz][0] == tab[wiersz][1] && tab[wiersz][1] == tab[wiersz][2]) && tab[wiersz][kol] != " ") 
				{
					zwycieski_znak = tab[wiersz][kol];
					gramy_dalej = 0; // je�li 0-gra sko�czona, je�li 1-sprawdza dalej
					goto stop;
				}
				else if((tab[0][kol] == tab[1][kol] && tab[1][kol] == tab[2][kol]) && tab[wiersz][kol] != " ") 
				{
					zwycieski_znak = tab[wiersz][kol];
					gramy_dalej = 0;
					goto stop;
				}
	 
				// sprawdzenie po skosie
				else if((tab[2][0] == tab[1][1] && tab[1][1] == tab[0][2]) && tab[2][0] != " ") 
				{
					zwycieski_znak = tab[2][0];
					gramy_dalej = 0;
					goto stop;
				} 
				else if((tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) && tab[0][0] != " ") 
				{
					zwycieski_znak = tab[0][0];
					gramy_dalej = 0;
					goto stop;
				}
	}
}

stop:

    // sprawdzamy czy sa jeszcze puste pola aby moc kontynuowac gre lub zakonczyc ja remisem
     
			if(tab[0][0] == " " || tab[0][1] == " " || tab[0][2] == " " || tab[1][0] == " " || tab[1][1] == " " || tab[1][2] == " " || tab[2][0] == " " || tab[2][1] == " " || tab[2][2] == " ") 
			{ 
				puste_pola = 1; //gramy dalej
				goto stop1;
			}
			else
			{
				puste_pola = 0; //gra sko�czona
				goto stop1;
			} 
     
stop1:

    if(gramy_dalej==0) 
		{ // ktos wygral to wyswietlamy wynik
        string winner;
		if(zwycieski_znak == znak_g) 
		{ // jesli znaczek np. X nalezal do cz�owieka to on wygra� i jego imie si� wyswietli, w przeciwnym wypadku X musial nalezec do kompa
            winner = imie;
			cout<<"Wygral "<<winner<<"!";
        } 
		else 
		{
            winner = "Komputer";
			cout<<"Wygral "<<winner<<"!";
        }
         
			rysuj_pola();
            Sleep(500); // wyswietlamy napis po 500ms
            cout<<"Wygral "<<winner<<"!\n";
			Sleep(2800);
        
            cout<<"\n Co chcesz teraz zrobic?\n"
				<<"1) Zagrac od nowa.\n"
				<<"2) Wyjsc.\n";

			int wybor;
			cin>>wybor;

			if(wybor == 1)
			{// zerowanie wszystkich warto�ci
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<3; j++)
					{
						tab[i][j]=" ";
					}
				}
				puste_pola=0;
				gramy_dalej=1;
				licznik_ruchow=0;
				start(0);
			}
			else if (wybor == 2) 
				{
					exit(1);
				}
        }
 
	if(puste_pola == 0 && gramy_dalej == 1) 
	{ // nieznaleziono pustych pol i nikt nie zdobyl 3 znaczkow obok siebie wiec gra konczy sie remisem         
			rysuj_pola();
            Sleep(500);
            cout<<"Remis!! \n\n";
            Sleep(2800);
			cout<<"\n Co chcesz teraz zrobic?\n"
				<<"1) Zagrac od nowa.\n"
				<<"2) Wyjsc.\n";

			int wybor;
			cin>>wybor;

			if(wybor == 1)
			{ // zerowanie
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<3; j++)
					{
						tab[i][j]=" ";
					}
				}
				puste_pola=0;
				gramy_dalej=1;
				licznik_ruchow=0;
				start(0);
			}
			else if (wybor == 2) 
				{
				exit(1);
				}
	}

}
//#################################################################################
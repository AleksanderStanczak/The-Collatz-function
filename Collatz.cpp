﻿#include "stdafx.h"
#include <iostream>
using namespace std;

struct wyraz_ciagu {
	unsigned int wartosc;
	int pozycja_w_ciagu;
};

int collatz(unsigned int liczba)
{
	if (liczba % 2 == 0)
	{
		if (liczba < UINT_MAX)
		{
			return liczba / 2;

		}
		//Jesli otrzymana liczba bedzie poza zakresem to oznaczamy ja jako -1
		else
		{
			return -1;
		}
	}
	else
	{
		if (liczba <= 1431655763)
		{
			return (liczba * 3) + 1;
		}
		else
		{
			return -1;
		}
	}
}

void zmien_szczyt(int wielkosc, wyraz_ciagu **kop, bool czy_kop_max)
{
	int ojciec = 0;
	int lewy_syn, prawy_syn;
	bool wykonuj_zamiany = true;
	if (czy_kop_max)
	{
		while (wykonuj_zamiany)
		{
			lewy_syn = (ojciec * 2) + 1;
			prawy_syn = (ojciec * 2) + 2;

			if (lewy_syn < wielkosc && kop[ojciec]->wartosc < kop[lewy_syn]->wartosc)
			{
				if (prawy_syn < wielkosc && kop[prawy_syn]->wartosc>kop[lewy_syn]->wartosc)
				{
					swap(kop[ojciec], kop[prawy_syn]);
					ojciec = prawy_syn;
				}
				else if (prawy_syn < wielkosc && kop[prawy_syn]->wartosc == kop[lewy_syn]->wartosc)
				{
					if (kop[prawy_syn]->pozycja_w_ciagu < kop[lewy_syn]->pozycja_w_ciagu)
					{
						swap(kop[ojciec], kop[prawy_syn]);
						ojciec = prawy_syn;
					}
					else
					{
						swap(kop[ojciec], kop[lewy_syn]);
						ojciec = lewy_syn;
					}
				}
				else
				{
					swap(kop[ojciec], kop[lewy_syn]);
					ojciec = lewy_syn;
				}
			}
			else if (prawy_syn < wielkosc && kop[ojciec]->wartosc < kop[prawy_syn]->wartosc)
			{
				swap(kop[ojciec], kop[prawy_syn]);
				ojciec = prawy_syn;
			}
			else if (lewy_syn < wielkosc && kop[ojciec]->wartosc == kop[lewy_syn]->wartosc && kop[lewy_syn]->pozycja_w_ciagu < kop[ojciec]->pozycja_w_ciagu)
			{
				swap(kop[ojciec], kop[lewy_syn]);
				ojciec = lewy_syn;
			}
			else if (prawy_syn < wielkosc && kop[ojciec]->wartosc == kop[prawy_syn]->wartosc && kop[prawy_syn]->pozycja_w_ciagu < kop[ojciec]->pozycja_w_ciagu)
			{
				swap(kop[ojciec], kop[prawy_syn]);
				ojciec = prawy_syn;
			}
			else if (prawy_syn < wielkosc && lewy_syn<wielkosc && kop[ojciec]->wartosc == kop[prawy_syn]->wartosc && kop[ojciec]->wartosc == kop[lewy_syn]->wartosc)
			{
				if (kop[prawy_syn]->pozycja_w_ciagu < kop[lewy_syn]->pozycja_w_ciagu)
				{
					swap(kop[ojciec], kop[prawy_syn]);
					ojciec = prawy_syn;
				}
				else
				{
					swap(kop[ojciec], kop[lewy_syn]);
					ojciec = lewy_syn;
				}
			}

			if (prawy_syn != ojciec && lewy_syn != ojciec)
			{
				wykonuj_zamiany = false;
			}

		}
	}

	else
	{
		while (wykonuj_zamiany)
		{
			lewy_syn = (ojciec * 2) + 1;
			prawy_syn = (ojciec * 2) + 2;

			if (lewy_syn < wielkosc && kop[ojciec]->wartosc > kop[lewy_syn]->wartosc)
			{
				if (prawy_syn < wielkosc && kop[prawy_syn]->wartosc<kop[lewy_syn]->wartosc)
				{
					swap(kop[ojciec], kop[prawy_syn]);
					ojciec = prawy_syn;
				}
				else if (prawy_syn < wielkosc && kop[prawy_syn]->wartosc == kop[lewy_syn]->wartosc)
				{
					if (kop[prawy_syn]->pozycja_w_ciagu < kop[lewy_syn]->pozycja_w_ciagu)
					{
						swap(kop[ojciec], kop[prawy_syn]);
						ojciec = prawy_syn;
					}
					else
					{
						swap(kop[ojciec], kop[lewy_syn]);
						ojciec = lewy_syn;
					}
				}
				else
				{
					swap(kop[ojciec], kop[lewy_syn]);
					ojciec = lewy_syn;
				}
			}
			else if (prawy_syn < wielkosc && kop[ojciec]->wartosc > kop[prawy_syn]->wartosc)
			{
				swap(kop[ojciec], kop[prawy_syn]);
				ojciec = prawy_syn;
			}
			else if (lewy_syn < wielkosc && kop[ojciec]->wartosc == kop[lewy_syn]->wartosc && kop[lewy_syn]->pozycja_w_ciagu < kop[ojciec]->pozycja_w_ciagu)
			{
				swap(kop[ojciec], kop[lewy_syn]);
				ojciec = lewy_syn;
			}
			else if (prawy_syn < wielkosc && kop[ojciec]->wartosc == kop[prawy_syn]->wartosc && kop[prawy_syn]->pozycja_w_ciagu < kop[ojciec]->pozycja_w_ciagu)
			{
				swap(kop[ojciec], kop[prawy_syn]);
				ojciec = prawy_syn;
			}
			else if (prawy_syn < wielkosc && lewy_syn<wielkosc && kop[ojciec]->wartosc == kop[prawy_syn]->wartosc && kop[ojciec]->wartosc == kop[lewy_syn]->wartosc)
			{
				if (kop[prawy_syn]->pozycja_w_ciagu < kop[lewy_syn]->pozycja_w_ciagu)
				{
					swap(kop[ojciec], kop[prawy_syn]);
					ojciec = prawy_syn;
				}
				else
				{
					swap(kop[ojciec], kop[lewy_syn]);
					ojciec = lewy_syn;
				}
			}

			if (prawy_syn != ojciec && lewy_syn != ojciec)
			{
				wykonuj_zamiany = false;
			}

		}
	}

}

void kopiec(int i, int wielkosc, wyraz_ciagu **kop, bool czy_kop_max)
{
	int ojciec = i;
	int lewy_syn = (i * 2) + 1;
	int prawy_syn = (i * 2) + 2;
	bool byla_zamiana = false;

	if (czy_kop_max)
	{
		if (lewy_syn < wielkosc && kop[ojciec]->wartosc < kop[lewy_syn]->wartosc)
		{
			if (prawy_syn < wielkosc && kop[prawy_syn]->wartosc>kop[lewy_syn]->wartosc)
			{
				swap(kop[ojciec], kop[prawy_syn]);
				ojciec = prawy_syn;
				byla_zamiana = true;
			}
			else if (prawy_syn < wielkosc && kop[prawy_syn]->wartosc == kop[lewy_syn]->wartosc)
			{
				if (kop[prawy_syn]->pozycja_w_ciagu < kop[lewy_syn]->pozycja_w_ciagu)
				{
					swap(kop[ojciec], kop[prawy_syn]);
					ojciec = prawy_syn;
					byla_zamiana = true;
				}
				else
				{
					swap(kop[ojciec], kop[lewy_syn]);
					ojciec = lewy_syn;
					byla_zamiana = true;
				}
			}
			else
			{
				swap(kop[ojciec], kop[lewy_syn]);
				ojciec = lewy_syn;
				byla_zamiana = true;
			}
		}
		else if (prawy_syn < wielkosc && kop[ojciec]->wartosc < kop[prawy_syn]->wartosc)
		{
			swap(kop[ojciec], kop[prawy_syn]);
			ojciec = prawy_syn;
			byla_zamiana = true;
		}
		else if (lewy_syn < wielkosc && kop[ojciec]->wartosc == kop[lewy_syn]->wartosc && kop[lewy_syn]->pozycja_w_ciagu < kop[ojciec]->pozycja_w_ciagu)
		{
			swap(kop[ojciec], kop[lewy_syn]);
			ojciec = lewy_syn;
			byla_zamiana = true;
		}
		else if (prawy_syn < wielkosc && kop[ojciec]->wartosc == kop[prawy_syn]->wartosc && kop[prawy_syn]->pozycja_w_ciagu < kop[ojciec]->pozycja_w_ciagu)
		{
			swap(kop[ojciec], kop[prawy_syn]);
			ojciec = prawy_syn;
			byla_zamiana = true;
		}
		else if (prawy_syn < wielkosc && lewy_syn<wielkosc && kop[ojciec]->wartosc == kop[prawy_syn]->wartosc && kop[ojciec]->wartosc == kop[lewy_syn]->wartosc)
		{
			if (kop[prawy_syn]->pozycja_w_ciagu < kop[lewy_syn]->pozycja_w_ciagu)
			{
				swap(kop[ojciec], kop[prawy_syn]);
				ojciec = prawy_syn;
				byla_zamiana = true;
			}
			else
			{
				swap(kop[ojciec], kop[lewy_syn]);
				ojciec = lewy_syn;
				byla_zamiana = true;
			}
		}
	}

	else
	{
		if (lewy_syn < wielkosc && kop[ojciec]->wartosc > kop[lewy_syn]->wartosc)
		{
			if (prawy_syn < wielkosc && kop[prawy_syn]->wartosc<kop[lewy_syn]->wartosc)
			{
				swap(kop[ojciec], kop[prawy_syn]);
				ojciec = prawy_syn;
				byla_zamiana = true;
			}
			else if (prawy_syn < wielkosc && kop[prawy_syn]->wartosc == kop[lewy_syn]->wartosc)
			{
				if (kop[prawy_syn]->pozycja_w_ciagu < kop[lewy_syn]->pozycja_w_ciagu)
				{
					swap(kop[ojciec], kop[prawy_syn]);
					ojciec = prawy_syn;
					byla_zamiana = true;
				}
				else
				{
					swap(kop[ojciec], kop[lewy_syn]);
					ojciec = lewy_syn;
					byla_zamiana = true;
				}
			}
			else
			{
				swap(kop[ojciec], kop[lewy_syn]);
				ojciec = lewy_syn;
				byla_zamiana = true;
			}
		}
		else if (prawy_syn < wielkosc && kop[ojciec]->wartosc > kop[prawy_syn]->wartosc)
		{
			swap(kop[ojciec], kop[prawy_syn]);
			ojciec = prawy_syn;
			byla_zamiana = true;
		}
		else if (lewy_syn < wielkosc && kop[ojciec]->wartosc == kop[lewy_syn]->wartosc && kop[lewy_syn]->pozycja_w_ciagu < kop[ojciec]->pozycja_w_ciagu)
		{
			swap(kop[ojciec], kop[lewy_syn]);
			ojciec = lewy_syn;
			byla_zamiana = true;
		}
		else if (prawy_syn < wielkosc && kop[ojciec]->wartosc == kop[prawy_syn]->wartosc && kop[prawy_syn]->pozycja_w_ciagu < kop[ojciec]->pozycja_w_ciagu)
		{
			swap(kop[ojciec], kop[prawy_syn]);
			ojciec = prawy_syn;
			byla_zamiana = true;
		}
		else if (prawy_syn < wielkosc && lewy_syn<wielkosc && kop[ojciec]->wartosc == kop[prawy_syn]->wartosc && kop[ojciec]->wartosc == kop[lewy_syn]->wartosc)
		{
			if (kop[prawy_syn]->pozycja_w_ciagu < kop[lewy_syn]->pozycja_w_ciagu)
			{
				swap(kop[ojciec], kop[prawy_syn]);
				ojciec = prawy_syn;
				byla_zamiana = true;
			}
			else
			{
				swap(kop[ojciec], kop[lewy_syn]);
				ojciec = lewy_syn;
				byla_zamiana = true;
			}
		}
	}

	if (byla_zamiana)
	{
		kopiec(ojciec, wielkosc, kop, czy_kop_max);
	}
}

int main()
{
	int n, q, poczatkowa_wielkosc, wielkosc_max, wielkosc_min;
	wyraz_ciagu *ciag, **kop_max, **kop_min;
	unsigned int nowa_liczba;
	int *k;
	char *c;
	bool czy_kop_max;
	cin >> n;
	poczatkowa_wielkosc = n;
	wielkosc_max = n;
	wielkosc_min = n;
	ciag = new wyraz_ciagu[n];
	kop_max = new wyraz_ciagu*[n];
	kop_min = new wyraz_ciagu*[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ciag[i].wartosc;
		ciag[i].pozycja_w_ciagu = i;
	}
	cin >> q;
	k = new int[q];
	c = new char[q];
	for (int i = 0; i < q; i++)
	{
		cin >> k[i] >> c[i];
	}
	int j = 0;
	for (int i = 0; i <poczatkowa_wielkosc; i++)
	{
		if (ciag[i].wartosc <= 1 || ciag[i].wartosc > UINT_MAX)
		{
			wielkosc_max--;
			wielkosc_min--;
		}
		else
		{
			kop_max[j] = &ciag[i];
			kop_min[j] = &ciag[i];
			j++;
		}
	}

	int wykonuj_obliczenia = 0;

	if (c[0] == 's')
	{
		czy_kop_max = false;
	}
	else
	{
		czy_kop_max = true;
	}

	while (wykonuj_obliczenia < q)
	{
		if (c[wykonuj_obliczenia] == 's')
		{
			if (czy_kop_max || wykonuj_obliczenia==0)
			{
				for (int i = wielkosc_min / 2 - 1; i >= 0; i--)
				{
					czy_kop_max = false;
					kopiec(i, wielkosc_min, kop_min, czy_kop_max);
				}
			}
			for (int i = 0; i < k[wykonuj_obliczenia]; i++)
			{
				if (wielkosc_min >= 1)
				{
					nowa_liczba = collatz(kop_min[0]->wartosc);
					ciag[kop_min[0]->pozycja_w_ciagu].wartosc = nowa_liczba;
					if (nowa_liczba == 1 || nowa_liczba == -1)
					{
						swap(kop_min[0], kop_min[wielkosc_min - 1]);
						wielkosc_min--;
					}
					zmien_szczyt(wielkosc_min, kop_min, czy_kop_max);
				}
			}

		}
		else if (c[wykonuj_obliczenia] == 'l')
		{
			if (!czy_kop_max || wykonuj_obliczenia==0)
			{
				for (int i = wielkosc_max / 2 - 1; i >= 0; i--)
				{
					czy_kop_max = true;
					kopiec(i, wielkosc_max, kop_max, czy_kop_max);
				}
			}
			for (int i = 0; i < k[wykonuj_obliczenia]; i++)
			{
				if (wielkosc_max >= 1)
				{
					nowa_liczba = collatz(kop_max[0]->wartosc);
					ciag[kop_max[0]->pozycja_w_ciagu].wartosc = nowa_liczba;
					if (nowa_liczba == 1 || nowa_liczba == -1)
					{
						swap(kop_max[0], kop_max[wielkosc_max - 1]);
						wielkosc_max--;
					}
					zmien_szczyt(wielkosc_max, kop_max, czy_kop_max);
				}
			}

		}
		wykonuj_obliczenia++;
	}

	for (int i = 0; i < poczatkowa_wielkosc; i++)
	{
		if (ciag[i].wartosc == -1)
		{
			cout << "m ";
		}
		else
		{
			cout << ciag[i].wartosc << " ";
		}
	}
	
	delete[] k;
	delete[] c;
	delete[] ciag;
	delete[] kop_max;
	delete[] kop_min;
	system("pause");
	return 0;
}

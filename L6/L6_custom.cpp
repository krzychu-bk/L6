#include <iostream>

using namespace std;

#define MAXYM_ROZMIAR 10

void wczytaj(int tab[MAXYM_ROZMIAR][MAXYM_ROZMIAR], int *rozm, int *mode, int *param) {
	cin >> *rozm;
	for (int i = 0; i < *rozm; i++) {
		for (int j = 0; j < *rozm; j++) {
			cin >> tab[i][j];
		}
	}
	cin >> *mode;
	if (*mode == 3 || *mode == 4) {
		cin >> *param;
	}
}

int tryb0(const int tab[MAXYM_ROZMIAR][MAXYM_ROZMIAR],const int rozm) {
	int sumwierszy[MAXYM_ROZMIAR]{ 0,0,0,0,0,0,0,0,0,0 }, sumkolumn[MAXYM_ROZMIAR]{0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < rozm; i++) {
		for (int j = 0; j < rozm; j++) {
			sumwierszy[j] += tab[i][j];
			sumkolumn[i] += tab[i][j];
		}
	}
	for (int k = 0; k < rozm; k++) {
		if (sumwierszy[k] != sumkolumn[k]) {
			return 0;
		}
	}
	return ;
}

int tryb1(const int tab[MAXYM_ROZMIAR][MAXYM_ROZMIAR], const int rozm) {
	if (tryb0(tab, rozm) == 0) {
		return 1;
	}
	else {
		int sumprzek1=0,sumprzek2=0,sumwiersza=0;
		for (int i = 0; i < rozm; i++) {
			sumwiersza += tab[0][i];
			for (int k = 0; k < rozm; k++) {
				if (i == k) {
					sumprzek1 += tab[i][k];
				}
			}
		}
		for (int i = rozm-1; i >= 0; i--) {
			for (int k = rozm -1; k >=0; k--) {
				if (i == k) {
					sumprzek2 += tab[i][k];
				}
			}
		}
		if (sumwiersza == sumprzek1 && sumprzek2 == sumprzek1) {
			return 0;
		}
		else return 1;
	}
}
int tryb2(const int tab[MAXYM_ROZMIAR][MAXYM_ROZMIAR], int rozm)
{
	int sum = 0;
	for (int t = 0; t < rozm; t++)
		sum = sum + tab[t][t];
	int sutryb1 = 0;
	for (int r = 0; r < rozm; r++)
		sutryb1 = sutryb1 + tab[r][rozm - 1 - r];

	if (sum != sutryb1)
		return 1;
	for (int y = 0; y < rozm; y++)
	{
		int sumawierszy = 0;
		for (int x = 0; x < rozm; x++)
			sumawierszy = sumawierszy + tab[y][x];
		if (sumawierszy != sum)
			return 1;

	}
	for (int x = 0; x < rozm; x++)
	{
		int sumakolumn = 0;
		for (int y = 0; y < rozm; y++)
			sumakolumn = sumakolumn + tab[y][x];
		if (sumakolumn != sum)
			return 1;

	}
	for (int y = 0; y < rozm; y++)
	{
		for (int x = 0; x < rozm; x++)
		{
			if (tab[y][x] == rozm * rozm)
			{
				return 0;
			}
			else
				return 1;
		}
	}
	return 1;
}

int tryb3(const int tab[MAXYM_ROZMIAR][MAXYM_ROZMIAR], const int rozm, const int param) {
	int subtab[MAXYM_ROZMIAR][MAXYM_ROZMIAR];
	for (int i = 1; i < (param + 1); i++) {
		for (int j = 0; j < param; j++) {
			subtab[i-1][j] = tab[i][j];
		}
	}
	if (tryb0(subtab, param)) {
		return 0;
	}
	else {
		return 1;
	}
	
}

int main() {
	int kwadrat[MAXYM_ROZMIAR][MAXYM_ROZMIAR];
	int rozm,  tryb, k;
	wczytaj(kwadrat, &rozm, &tryb, &k);
	if (tryb == 0) {
		if (tryb0(kwadrat, rozm) == 1) {
			cout << "NO";
		}
		else if (tryb0(kwadrat, rozm)==0) {
			cout << "YES";
		}
	}
	else if (tryb == 1) {
		if (tryb1(kwadrat, rozm) == 1) {
			cout << "NO";
		}
		else if (tryb1(kwadrat, rozm) == 0) {
			cout << "YES";
		}
	}
	else if (tryb == 2) {
		if (tryb2(kwadrat, rozm) == 1) {
			cout << "NO";
		}
		else if (tryb2(kwadrat, rozm) == 0) {
			cout << "YES";
		}
	}
	else if (tryb == 3) {
		if (tryb3(kwadrat, rozm, k) == 1) {
			cout << "NO";
		}
		else if (tryb3(kwadrat, rozm, k) == 0) {
			cout << "YES";
		}
	}
	return 0;
}

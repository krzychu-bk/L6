#include <iostream>
using namespace std;

#define MAX_SIZE 10

void input(char source[MAX_SIZE][MAX_SIZE], int size[2], int* mode, int* turns) {
	for (int i = 0; i < 2; i++) {
		cin >> size[i];
	}
	for (int j = 0; j < size[0]; j++) {
		for (int k = 0; k < size[1]; k++) {
			cin >> source[j][k];
		}
	}
	cin >> *mode;
	if (*mode == 1) {
		cin >> *turns;
	}
}

void countNeighbours(char source[MAX_SIZE][MAX_SIZE],int neiMap[MAX_SIZE][MAX_SIZE], int size[2]) {
	for (int b = 0; b < size[0]; b++) {
		for (int a = 0; a < size[1]; a++) {
			neiMap[b][a] = 0;
		}
	}
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++) {
			if (source[i][j]=='1') {
				if (i != 0) {
					if (j != 0) {
						neiMap[i - 1][j - 1]++;
					}
					neiMap[i - 1][j]++;
					neiMap[i - 1][j + 1]++;
				}
				if (j != 0) {
					neiMap[i][j - 1]++;
					neiMap[i + 1][j - 1]++;
				}		
				neiMap[i][j + 1]++;
				neiMap[i + 1][j]++;
				neiMap[i + 1][j + 1]++;
			}
		}
	}
}

void charPrint(char source[MAX_SIZE][MAX_SIZE], int size[2]) {
	for (int y = 0; y < size[0]; y++) {
		for (int x = 0; x < size[1]; x++) {
			cout << source[y][x];
			if (x == (size[1] - 1)) {
				cout << endl;
			}
		}
	}
}

void intPrint(int source[MAX_SIZE][MAX_SIZE], int size[2]) {
	for (int y = 0; y < size[0]; y++) {
		for (int x = 0; x < size[1]; x++) {
			cout << source[y][x];
			if (x == (size[1] - 1)) {
				cout << endl;
			}
		}
	}
}

void game(char source[MAX_SIZE][MAX_SIZE], int neiMap[MAX_SIZE][MAX_SIZE], int size[2], int turns) {
	char dest[MAX_SIZE][MAX_SIZE];
	charPrint(source, size);
	cout << endl;
	for (int a = 0; a < turns; a++) {
		countNeighbours(source, neiMap, size);
		for (int i = 0; i < size[0]; i++) {
			for (int j = 0; j < size[1]; j++) {
				if (source[i][j] == '0') {
					if (neiMap[i][j] == 3) {
						dest[i][j] = '1';
					}
					else dest[i][j] = '0';
				}
				if (source[i][j] == '1') {
					if ((neiMap[i][j] == 2) || neiMap[i][j] == 3) {
						dest[i][j] = '1';
					}
					else dest[i][j] = '0';
				}
				if (source[i][j] == 'X') {
					dest[i][j] = 'X';
				}
			}
		}
		charPrint(dest, size);
		cout << endl;
		for (int k = 0; k < size[0]; k++) {
			for (int l = 0; l < size[1]; l++) {
				source[k][l] = dest[k][l];
			}
		}
	}
}

int main() {
	char board[MAX_SIZE][MAX_SIZE];
	int size[2], mode, turns, neiMap[MAX_SIZE][MAX_SIZE];
	input(board, size, &mode, &turns);
	if (mode == 0) {
		countNeighbours(board,neiMap,size);
		intPrint(neiMap, size);
	}
	if (mode == 1) {
		game(board, neiMap,size,turns);
	}
	return 0;
}



#include <iostream>
using namespace std;

#define MSIZE 10

void input(char array[MSIZE][MSIZE], int size[2], int* mode, int* arg) {
	for (int i = 0; i < 2; i++) {
		cin >> size[i];
	}
	for (int j = 0; j < size[0]; j++) {
		for (int k = 0; k < size[1]; k++) {
			cin >> array[j][k];
		}
	}
	cin >> *mode;
	if (*mode == 1) {
		cin >> *arg;
	}
}

void mode0(char array[MSIZE][MSIZE],int nofN[MSIZE][MSIZE], int size[2]) {
	for (int b = 0; b < size[0]; b++) {
		for (int a = 0; a < size[1]; a++) {
			nofN[b][a] = 0;
		}
	}
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++) {
			if (array[i][j]=='1') {
				if (i != 0) {
					if (j != 0) {
						nofN[i - 1][j - 1]++;
					}
					nofN[i - 1][j]++;
					nofN[i - 1][j + 1]++;
				}
				if (j != 0) {
					nofN[i][j - 1]++;
					nofN[i + 1][j - 1]++;
				}		
				nofN[i][j + 1]++;
				nofN[i + 1][j]++;
				nofN[i + 1][j + 1]++;
			}
		}
	}
}

void printC(char array[MSIZE][MSIZE], int size[2]) {
	for (int y = 0; y < size[0]; y++) {
		for (int x = 0; x < size[1]; x++) {
			cout << array[y][x];
			if (x == (size[1] - 1)) {
				cout << endl;
			}
		}
	}
}

void printI(int array[MSIZE][MSIZE], int size[2]) {
	for (int y = 0; y < size[0]; y++) {
		for (int x = 0; x < size[1]; x++) {
			cout << array[y][x];
			if (x == (size[1] - 1)) {
				cout << endl;
			}
		}
	}
}

void mode1(char array[MSIZE][MSIZE], int nofN[MSIZE][MSIZE], int size[2], int arg) {
	char dest[MSIZE][MSIZE];
	printC(array, size);
	cout << endl;
	for (int a = 0; a < arg; a++) {
		mode0(array, nofN, size);
		for (int i = 0; i < size[0]; i++) {
			for (int j = 0; j < size[1]; j++) {
				if (array[i][j] == '0') {
					if (nofN[i][j] == 3) {
						dest[i][j] = '1';
					}
					else dest[i][j] = '0';
				}
				if (array[i][j] == '1') {
					if ((nofN[i][j] == 2) || nofN[i][j] == 3) {
						dest[i][j] = '1';
					}
					else dest[i][j] = '0';
				}
				if (array[i][j] == 'X') {
					dest[i][j] = 'X';
				}
			}
		}
		printC(dest, size);
		cout << endl;
		for (int k = 0; k < size[0]; k++) {
			for (int l = 0; l < size[1]; l++) {
				array[k][l] = dest[k][l];
			}
		}
	}
}

int main() {
	char board[MSIZE][MSIZE];
	int size[2], mode, arg, nofN[MSIZE][MSIZE];
	input(board, size, &mode, &arg);
	if (mode == 0) {
		mode0(board,nofN,size);
		printI(nofN, size);
	}
	if (mode == 1) {
		mode1(board, nofN,size,arg);
	}
	return 0;
}



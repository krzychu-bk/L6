#include <iostream>

using namespace std;

#define MSIZE 10

void input(int array[MSIZE][MSIZE], int *size, int *mode, int *arg) {
	cin >> *size;
	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size; j++) {
			cin >> array[i][j];
		}
	}
	cin >> *mode;
	if (*mode == 3 || *mode == 4) {
		cin >> *arg;
	}
}

int mode0(const int array[MSIZE][MSIZE],const int size) {
	int sumr[MSIZE]{ 0,0,0,0,0,0,0,0,0,0 }, sumc[MSIZE]{0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sumc[j] += array[i][j];
			sumr[i] += array[i][j];
		}
	}
	for (int k = 0; k < size; k++) {
		if (sumc[k] != sumr[k]) {
			return 0;
		}
	}
	return 1;
}

int mode1(const int array[MSIZE][MSIZE], const int size) {
	if (mode0(array, size) == 0) {
		return 0;
	}
	else {
		int sumd1=0,sumd2=0,sumrow=0;
		for (int i = 0; i < size; i++) {
			sumrow += array[0][i];
			for (int k = 0; k < size; k++) {
				if (i == k) {
					sumd1 += array[i][k];
				}
			}
		}
		for (int i = size-1; i >= 0; i--) {
			for (int k = size -1; k >=0; k--) {
				if (i == k) {
					sumd2 += array[i][k];
				}
			}
		}
		if (sumrow == sumd1 && sumrow == sumd2) {
			return 1;
		}
		else return 0;
	}
}
int mode3(const int array[MSIZE][MSIZE], const int size, const int arg) {
	int subarray[MSIZE][MSIZE];
	for (int i = 1; i < (arg + 1); i++) {
		for (int j = 0; j < arg; j++) {
			subarray[i-1][j] = array[i][j];
		}
	}
	if (mode0(subarray, arg)) {
		return 1;
	}
	else {
		return 0;
	}
	
}

int main() {
	int src[MSIZE][MSIZE];
	int size,  mode, arg;
	input(src, &size, &mode, &arg);
	if (mode == 0) {
		if (mode0(src, size) == 0) {
			cout << "NO";
		}
		else if (mode0(src,size)==1) {
			cout << "YES";
		}
	}
	if (mode == 1) {
		if (mode1(src, size) == 0) {
			cout << "NO";
		}
		else if (mode1(src, size) == 1) {
			cout << "YES";
		}
	}
	if (mode == 3) {
		if (mode3(src, size, arg) == 0) {
			cout << "NO";
		}
		else if (mode3(src, size, arg) == 1) {
			cout << "YES";
		}
	}
	return 0;
}
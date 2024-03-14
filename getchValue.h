#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>


using namespace std;

int getchVal(char x[], int l) { // 101 is up, 111 is down
	//x[32];

	int num =1;
	char a;

	for (int i = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}
		else if (a == 13) {
			x[i] = '\0';
			return 111;
			break;
		}
		else if (a == 8 && i >= 1) {
			cout << "\b \b";
			x[--i] = '\0';
		}
		else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') {
			if (num == 1) {
				//cout << string(20, ' ');
				for (int u = 0; u < 32; u++) {
					x[u] = '\0';
				}
				num = 0;
			}
			if (l >= 2 && l <= 11) { // age
				if ((a >= '0' && a <= '9')) {
					if (l == 2 && i < 2) { // age and bday
						cout << a;
						x[i] = a;
						++i;
					}
					else if (l == 11 && i < 11) { // gnumber
						cout << a;
						x[i] = a;
						++i;
					}
					else if (l == 4 && i < 4) { // byear and zip
						cout << a;
						x[i] = a;
						++i;
					}
					else if (l == 12 && i < 11) { // gnumber
						cout << a;
						x[i] = a;
						++i;
					}
				}
			}
			else {
				cout << a;
				x[i] = a;
				++i;
			}
		}
	}
}

int getchValc(string& s, char t, int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[50];

	int num = 1;
	int nm = 1; // for curriculum erasing
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ' || x[j] == '-' || x[j] == '/' ||x[j] == ',') {
					s += x[j];
				}
				else {
					break;
				}
			}

			return 111;
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100;
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') && z < l) {

			// erasing previous string value
			if (num == 1) {
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}



void getchcout(char x[]) { // x = array of letters  y is size of letters
	for (int i = 0;; i++) {
		if (x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z' || x[i] >= '0' && x[i] <= '9' || x[i] == ' ') {
			cout << x[i];
		}
		else {
			break;
		}

	}
}

void delarr(char x[]) {
	for (int i = 0; i < 32; i++) {
		x[i] = '\0';
	}
}

void multival(string& v, string& w, string& x, string& y, string& z, int a, int b, int c) { // w x y z is the storage, a b is the position of gotoxy, c if erasing (1 == erase)


	if (c == 1) { // this is to erase
		v = "";
		coorxy(a + 25, b); cout << string(9, ' ');
		coorxy(a + 25, b); cout << v;
		w = "";
		coorxy(a + 34, b); cout << string(47, ' ');
		coorxy(a + 34, b); cout << w;
		x = "";
		coorxy(a + 91, b); cout << string(4, ' ');
		coorxy(a + 91, b); cout << x;
		y = "";
		coorxy(a + 102, b); cout << string(7, ' ');
		coorxy(a + 102, b); cout << y;
		z = "";
		coorxy(a + 109, b); cout << string(7, ' ');
		coorxy(a + 109, b); cout << y;
	}
	else {

		int localcounter = 1;
		int sm;

		//getting the values inside the line

	Q:
		switch (localcounter) {
		case 1:
			coorxy(a + 30, b); sm = getchValc(v, 'l', 13); // subject code
			coorxy(a + 30, b); cout << string(9, ' ');
			coorxy(a + 30, b); cout << v;
			if (sm == 111)localcounter++; // if getchvalc returned a value
			else if (sm == 100) goto Q; // if getchvalc returned empty/null
			goto Q;
			break;
		case 2:
			coorxy(a + 43, b); sm = getchValc(w, 'l', 47); // subject description
			coorxy(a + 43, b); cout << string(47, ' ');
			coorxy(a + 43, b); cout << w;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 3:
			coorxy(a + 93, b); sm = getchValc(x, 'l', 8); // subject credits
			coorxy(a + 93, b); cout << string(4, ' ');
			coorxy(a + 93, b); cout << x;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 4:
			coorxy(a + 99, b); sm = getchValc(y, 'l', 8);  // subject pre req 1
			coorxy(a + 99, b); cout << string(7, ' ');
			coorxy(a + 99, b); cout << y;
			if (sm == 101)localcounter--;
			else if (sm == 100) goto Q;
			else localcounter++;
			goto Q;
			break;
		case 5:
			coorxy(a + 106, b); sm = getchValc(z, 'l', 8); // subjecy pre req 2
			coorxy(a + 106, b); cout << string(7, ' ');
			coorxy(a + 106, b); cout << z;
			if (sm == 101) {
				localcounter--;
				goto Q;
			}
			else if (sm == 100) {
				goto Q;
			}
			else {
				//localcounter++;
				break;
			}
		}
	}


}
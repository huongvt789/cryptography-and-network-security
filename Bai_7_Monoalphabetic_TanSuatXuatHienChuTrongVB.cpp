
/*
* Bài tập 7:
+ Lập trình tần xuất xuất hiện các ký tự trong 1 văn bản xuất hiện bao nhiêu lần.
*/
#include "stdafx.h"
#include<iostream>
using namespace std;
#include <string>

#include<iostream>

using namespace std;

string M = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int KiTu_So(char c) {

	for (int i = 0; i < 26; i++) {

		if (c == M[i]) {

			return i;
		}
	}
}

char So_KiTu(int n) {

	return M[n];
}

void SoLanXuatHien(string a) {

	int b[27];

	for (int i = 0; i < 27; i++) {

		b[i] = 0;
	}

	for (int i = 0; i < a.size(); i++) {

		for (int j = 0; j < M.size(); j++) {

			if (a[i] == M[j]) {

				b[j]++;
			}
			else {

				b[26]++;
			}
		}
	}

	for (int i = 0; i < 27; i++) {

		cout << M[i] << " : " << b[i] << endl;
	}
}

int main() {

	string s;

	cout << "Nhap chuoi ki tu : ";
	getline(cin, s);

	SoLanXuatHien(s);
		system("pause");
		return 0;
}


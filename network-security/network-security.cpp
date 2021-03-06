﻿/*
Bài tập 4:
- Lập trình nhập một chuỗi kí tự từ bàn phím, mã hoá chuỗi bằng thuật toán Affine với cặp số {a,b} nhập từ bàn phím. Hiện chuỗi mới ra màn hình.
Bài tập 5:
- Lập trình giải mã Affine để khôi phục lại chuỗi ban đầu:
- Đầu vào chương trình là cặp số {a,b} và chuỗi kí tự cipher text từ Bài tập 1.
- Đầu ra chương trình là chuỗi kí tự plain text.
*/
#include "stdafx.h"
#include<iostream>
using namespace std;
#include <string>

bool KiemTraA(int a) {

	for (int i = 1; i <= 25; i++) {

		if ((i*a) % 26 == 1) {

			return true;

			break;
		}
	}

	return false;
}
int NghichDao(int a) {
	for (int i = 1; i <= 25; i++) {

		if ((i*a) % 26 == 1) {

			return i;
		}
	}
}


string M = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int KiTu_So(char chuoi) {
	for (int i = 0; i < 26; i++) {
		if (chuoi == M[i]) {
			return i;
		}
	}
}

char MaHoa(char chuoi, int soT1, int soT2) {
	int ma = KiTu_So(chuoi);
	ma = (soT1*ma + soT2) % 26;
	return M[ma];
}

char GiaiMa(char chuoi, int a, int b) {
	int giai = KiTu_So(chuoi);
	giai = NghichDao(a)*((giai - b + 26) % 26);
	return M[giai];
}
int main()
{
	bool check = false;
	string s;
	int a, b;
	cout << "Nhap chuoi : "; cin >> s;
	int N[] = { 1, 3,  5,  7,  9,  11, 15, 17, 19, 21, 23, 25 };

	while (!check) {
		cout << "Nhap a : ";
		cin >> a;
		for (int i = 0; i < 12; i++) {
			if (KiemTraA(a) == true) {
				break;
			}
		}
		cout << "Nhap b : ";
		cin >> b;
		for (int i = 0; i < s.size(); i++) {
			s[i] = MaHoa(s[i], a, b);
			cout << s[i];
		}
		cout << "Chuoi ma hoa la:" << s << endl;

		//Giai ma
		for (int i = 0; i < s.size(); i++) {
			s[i] = GiaiMa(s[i], a, b);
		}
		cout << "Chuoi giai ma : " << s << endl;
		system("pause");

		return 0;
	}
}


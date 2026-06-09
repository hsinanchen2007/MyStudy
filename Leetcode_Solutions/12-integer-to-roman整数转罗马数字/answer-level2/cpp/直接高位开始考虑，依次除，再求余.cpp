#pragma once
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		string str = "";
		int a = num / 1000;
		if (a != 0) {
			for (int i = 0; i < a; i++) {
				str += "M";
			}
		}
		int b = num % 1000;
		a = b / 900;
		if (a != 0) {
			str += "CM";
			b = b % 900;
		}
			a = b / 500;
			if (a != 0) {
				str += "D";
				b = b % 500;

			}
				a = b / 400;
				if (a != 0) {
					str += "CD";
					b = b % 400;
				}
					a = b / 100;
					if (a == 3) {
						str += "CCC";
					}
					if (a == 2) {
						str += "CC";
					}
					if (a == 1)str += "C";
					b = b % 100;
					
		a = b / 90;
		if (a != 0) {
			str += "XC";
			b = b % 90;
		}
			a = b / 50;
			if (a != 0) {
				str += "L";
				b = b % 50;

			}
				a = b / 40;
				if (a != 0) {
					str += "XL";
					b = b % 40;
				}
					a = b / 10;
					if (a == 3) {
						str += "XXX";
					}
					if (a == 2) {
						str += "XX";
					}
					if (a == 1)str += "X";
					b = b % 10;

		if (b <= 3) {
			for (int i = 0; i < b; i++) {
				str += "I";
			}
		}
		if (b == 4) str += "IV";
		if (b == 5)str += "V";
		if (b == 6)str += "VI";
		if (b == 7)str += "VII";
		if (b == 8)str += "VIII";
		if (b == 9)str += "IX";
		if (b == 10)str += "X";
		return str;
	}
};
#pragma once
#include<iostream>
#include<string>
using namespace std;
string s[20] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
string s2[9] = { "Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
class Solution {
public:
	void mod(string &str,int &num,int m) {
		int  a = num / m;
		if (m == 1000000000) {
			if (a != 0) {
			if (a == 1) { str += "One Billion"; }
			if (a == 2) { str += "Two Billion"; }
			num = num % 1000000000;
			}
			if (num == 0)return;
			else {
				mod(str,num,1000000);
			}
		
		}
		if (m == 1000000) {
			if (a >=100) {
				space(str, s[a/100-1]+" Hundred");
			}
			int b = a % 100;
			if (b >=20) {
				space(str, s2[b / 10 - 1]);
				b = b % 10;
				if (b != 0) space(str, s[b - 1]);
			}
			else {
				if(b!=0) space(str, s[b - 1]);
			}
			if(num>=1000000)
			str +=" Million";
			num = num % 1000000;
			if (num == 0)return;			
			mod(str, num, 1000);
		}
		if (m == 1000) {
			if (a >= 100) {
				space(str, s[a / 100 - 1]+ " Hundred");
			}
			int b = a % 100;
			if (b >= 20) {
				space(str, s2[b / 10 - 1]);
				b = b % 10;
				if (b != 0)
					space(str, s[b - 1]);
			}
			else {
				if(b!=0)
				space(str, s[b - 1]);
			}
			if (num >=1000)
			str += " Thousand";
			num = num % 1000;
			if (num == 0)return;
			mod(str, num, 100);
		}
		if (m == 100) {
			if (a >= 1) {
				space(str, s[a - 1] + " Hundred");
			}
			num = num % 100;
			if (num == 0)return;
			mod(str, num, 10);
		}
		if (m == 10) {
			if (a >= 2) {
				space(str, s2[a - 1]);
				num= num% 10;
				if (num == 0)return;
				space(str, s[num-1]);
			}
			else {
				if (num == 0)return;
				space(str, s[num - 1]);

			}
		}
	}



	string numberToWords(int num) {
		string str = "";
		if (num == 0) { return "Zero"; }
		mod(str, num, 1000000000);
		return str;
	}
	void space(string &res, string temp) {
		if (res.size() == 0) {
			res += temp;
		}
		else {
			if (res[res.size()-1] == ' ') {
				res += temp;
			}
			else {
				res += " " + temp;
			}
		}
	
	}
};
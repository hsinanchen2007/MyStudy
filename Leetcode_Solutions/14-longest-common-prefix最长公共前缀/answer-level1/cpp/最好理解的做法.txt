#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string a = "";
		int b = strs.size();
		if (b == 0)return a;
		else if (b == 1) return strs[0];
		else {
		string c = strs[0];
		int index = 0;
		for (int i = 0; i < c.length(); i++) {
			for (int j = 1; j < b; j++) {
				if (i >= strs[j].length()) { index = 1; break; }
				if (c[i] != strs[j][i]) {
					index = 1;
					break;
				}
			}
			if (index == 0) { a += c[i]; }
		}
		return a;
		}
		
	}
};
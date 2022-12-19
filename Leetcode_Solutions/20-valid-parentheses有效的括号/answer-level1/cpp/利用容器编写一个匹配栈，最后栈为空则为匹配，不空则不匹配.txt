#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		if (s == "")return true;
		int a = s.length();
		if (a % 2 != 0)return false;
		if(s[0]=='}'||s[0]==']'||s[0]==')')return false;
		vector<char>p;
		for (int i =0; i <a; i++) {
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
				p.push_back(s[i]);
			}
			else {
				if (s[i] == ']') {
					if (p[p.size() - 1] != '[')
					{
						return false;
					}
					else {
						p.pop_back();
					}
				}
				if (s[i] == '}') {
					if (p[p.size() - 1] != '{')
					{
						return false;
					}
					else {
						p.pop_back();
					}
				}
				if (s[i] == ')') {
					if (p[p.size() - 1] != '(')
					{
						return false;
					}
					else {
						p.pop_back();
					}
				}
			}
		}
		if (p.size() != 0)return false;
		return true;
	}
};
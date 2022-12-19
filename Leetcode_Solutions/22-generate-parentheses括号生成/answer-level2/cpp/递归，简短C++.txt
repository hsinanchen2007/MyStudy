#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>res;
		string temp;
		search(res, n, n, temp);
		return res;
	}
	void search(vector<string>&res, int mleft, int mright,string temp) {
		if (mleft > mright||mright<0||mleft<0) { return; }
		if (mleft == 0 && mright == 0) { res.push_back(temp); }
		search(res, mleft - 1, mright, temp + "(");
		search(res, mleft, mright-1, temp + ")");
	}
};
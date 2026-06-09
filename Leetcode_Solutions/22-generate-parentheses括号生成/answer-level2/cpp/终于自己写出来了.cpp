深度优先搜索，判断左括号和右括号的数量。菜鸡在路上，大佬们请指教
```
void core(vector<string>&v, string s, int n, int leftnum, int rightnum) {
	if (s.length() >= n * 2 && leftnum == n) {
		v.push_back(s);
		return;
	}
	if (leftnum<n) {
		string t = s;
		if (leftnum>rightnum)
			core(v, s + ")", n, leftnum, rightnum + 1);
		core(v, s + "(", n, leftnum + 1, rightnum);
		s = t;
	}
	if (leftnum == n) {
		while (s.length()<n * 2) {
			s += ")";
		}
		v.push_back(s);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string>res;
	string s = "(";
	core(res, s, n, 1, 0);
	return res;
}
```
![image.png](https://pic.leetcode-cn.com/cb4217c13743c88a99b2c4706ce5146762d389b094b7a7068cfea34b1068606e-image.png)

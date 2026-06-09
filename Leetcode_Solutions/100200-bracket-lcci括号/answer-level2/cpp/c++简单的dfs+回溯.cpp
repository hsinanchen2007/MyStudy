注意一下回溯条件，就可以了。
左括号 > n 或者 右括号 > n 或者 右括号 > 左括号，就回溯
`if (l > n || r > n || r > l) return;`
```
void dfs(int n, int l, int r, int i, string& s, vector<string>& ans) {
	if (l > n || r > n || r > l) return;
	if (s.size() == 2 * n) {
		ans.push_back(s);
	}
	s.push_back('(');
	dfs(n, l + 1, r, i + 1, s, ans);
	s.pop_back();
	s.push_back(')');
	dfs(n, l, r + 1, i + 1, s, ans);
	s.pop_back();
}
//生成n对括号组合方法
vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string s;
	dfs(n, 0, 0, 1, s, ans);
	return ans;
}
```


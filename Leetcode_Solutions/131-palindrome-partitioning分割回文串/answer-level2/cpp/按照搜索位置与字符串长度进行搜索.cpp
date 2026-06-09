这题和[93. 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)思路类似。



从 ` i = 0`开始，枚举长度为`len=1，2，3 ...` 的字符串，看是否能构成回文串，如果能构成回文串，再从 `i = 0 + len`的位置开始，枚举长度为`len = 1，2，3 ...`的字符串；
初始时，`i = 0, len = 1`；然后 `i = 1`开始，不断递归，直到分割出的字串都是回文串；
最后回溯到 `i = 0, len = 2;` 再不断搜索`i=1, len=2`的情况
```cpp
bool check(string s, int i, int j) {
	while (i <= j) {
		if (s[i] == s[j]) {
			i++; 
			j--;
		}
		else {
			return false;
		}
	}
	return true;
}
void dfs(vector<vector<string>>& ans, vector<string>& temp, string s, int i) {
	if (i == s.size()) {
		ans.push_back(temp);
		return;
	}
	for (int len = 1; len <= s.size(); len++) {
		int j = i + len - 1;
		if (j >= s.size()) break;
		if (check(s, i, j)) {
			temp.push_back(s.substr(i, len));
			dfs(ans, temp, s, j + 1);
			temp.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<string>> ans;
	vector<string> temp;
	dfs(ans, temp, s, 0);
	return ans;
}
```

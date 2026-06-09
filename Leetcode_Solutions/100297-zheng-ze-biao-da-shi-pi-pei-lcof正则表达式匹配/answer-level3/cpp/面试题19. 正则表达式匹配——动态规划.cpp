两个字符串比较时，结果在前n-1个字符的基础上叠加当前字符的比较结果，可以用动态规划求解。
定义dp[i][j]表示s的前i个字符与p[j]的前j个字符的比较结果，通过当前字符的种类进行分类，逐步遍历所有情况，最终得出最后结果。
```
class Solution {
public:
	bool isMatch(string s, string p) {
		int sn = s.size();
		int pn = p.size();
		if (sn == 0 && pn == 0) {
			return true;
		} else if (sn != 0 && pn == 0) {
			return false;
		}
		vector<vector<bool>> dp(sn + 1, vector<bool>(pn + 1, false));
		for (int i = 0; i <= sn; i++) {
			for (int j = 0; j <= pn; j++) {
				if (j == 0) {
					dp[i][j] = (i == 0);
					continue;
				}
				if (p[j - 1] == '.' || isalpha(p[j - 1])) {
					if (i >= 1) {
						if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
							dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
					}
				} else {
					if (j >= 2) {
						dp[i][j] = dp[i][j] || dp[i][j - 2];
						if (i >= 1) {
							if ((isalpha(p[j - 2]) && p[j - 2] == s[i - 1]) || p[j - 2] == '.') {
								dp[i][j] = dp[i][j] || dp[i - 1][j];
							}
						}
					}

				}
			}
		}
		return dp[sn][pn];
	}
};
```

```
代码块
class Solution {
public:
bool isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();
	vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
	dp[0][0] = true;
	dp[0][1] = p[0] == '*';
	for (int j = 2; j <= n; j++)
	{
		dp[0][j] = p[j - 1] == '*'&&dp[0][j - 2];
	}
	for (int i = 1; i <= m; i++)
	{
		for(int j=1;j<=n;j++)
		{
		if (s[i - 1] == p[j - 1] || p[j - 1] == '.') dp[i][j] = dp[i-1][j-1];



		else if (p[j - 1] == '*'&&j > 1) {//j==1且为*必为false

			dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] &&( s[i - 1] == p[j - 2]||p[j-2]=='.'));//情形1，空匹配
			//情形2：匹配重复字符 1-x个，如果s的最后一个字符和p的倒数第二个字符一样或者p的倒数第二个字符是.那么
			//如果dp[i-1][j]匹配的话那么i j肯定也匹配（*复制） 
		}
		}

	}
	return dp[m][n];

	
	
}
};
```

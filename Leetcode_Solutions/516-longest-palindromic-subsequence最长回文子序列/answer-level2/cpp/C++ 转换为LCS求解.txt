
### 代码

```cpp
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		string s2(s);
		//s2反转
		reverse(s2.begin(), s2.end());
		//定义状态
		//s的前i个字符和s2的前j个字符的LCS
		vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));
		//初始化
		for (int i=0;i<=s.size();i++)
		{
			dp[0][i] = 0;
			dp[i][0] = 0;
		}
		//状态转移
		for (int i=1;i<=s.size();i++)
		{
			for (int j=1;j<=s.size();j++)
			{
				if (s[i-1] == s2[j-1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[s.size()][s.size()];
	}
};
```
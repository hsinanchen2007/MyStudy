```
执行用时 :
class Solution {
public:
	const int mod = 1e9 + 7;
	int countVowelPermutation(int n) {
		vector< vector<long long> >dp(n+1, vector<long long>(5));
		for (int i = 0; i < 5; i++)
		{
			dp[1][i] = 1;
		}
		for (int i = 2; i < n + 1; i++)
		{
			dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) %mod;
			dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
			dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
			dp[i][3] = dp[i - 1][2]%mod;
			dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		}
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
			sum = (int)((sum+dp[n][i])%mod);
		}
		return sum;
	}
};
```
tips:一定要注意数据的范围！！

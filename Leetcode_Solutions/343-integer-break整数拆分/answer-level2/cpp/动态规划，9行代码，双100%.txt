```
int integerBreak(int n) {
		vector<int> dp(n + 1, 1);
		int max = 1;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= i - 1;j++) 
				max = j * dp[i - j] > max ? j * dp[i - j] : max;
			if (i < n)dp[i] = max > i ? max : i;
			else dp[i] = max;
		}
		return dp[n];
	}
```

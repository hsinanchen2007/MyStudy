n^3的方法不难想 关键是展开降维，这里参考了下官解。

n^3最原始的方法 利用插入的思想 原理是插入第n个数可以使得全部逆序对增加0到n-1对 因此对于k对的答案 去累加n-1,k-n+1一直到n-1,k的答案即可
```cpp
int kInversePairs(int n, int k) {
	vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k + 1, 0));
	dp[0][0] = dp[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int t = j; t <= k; ++t) {
				dp[i][t] += dp[i - 1][t - j];
				dp[i][t] %= 1000000007;
			}
		}
	}
	return dp.back().back();
}
```

然后是降维 其实就是展开化简 可以参考官解
```cpp
int kInversePairs(int n, int k) {
	vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k + 1, 0));
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 1;
	for (int i = 2; i <= n; ++i)
		for (int t = 1; t <= k; ++t)
			dp[i][t] = t >= i ? 
			(dp[i - 1][t] + dp[i][t - 1] - dp[i - 1][t - i] + 1000000007) % 1000000007 : 
			(dp[i - 1][t] + dp[i][t - 1]) % 1000000007;
	return dp.back().back();
}
```
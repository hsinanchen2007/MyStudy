题不难 特殊情况 N = 1 和 K = 0两种 容易错

```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
	if (N == 1)
	    return { 0,1,2,3,4,5,6,7,8,9 };
	vector<vector<int>> dp(N);
	dp[0] = { 1,2,3,4,5,6,7,8,9 };
	for (int n = 1; n < N; ++n) {
	    for (int& i : dp[n - 1]) {
		if (K) {
		    if (i % 10 - K >= 0)
			dp[n].push_back(i * 10 + i % 10 - K);
		    if (i % 10 + K <= 9)
			dp[n].push_back(i * 10 + i % 10 + K);
		}
		else
		    dp[n].push_back(i * 10 + i % 10);
	    }
	}
	return dp.back();
    }
};
```
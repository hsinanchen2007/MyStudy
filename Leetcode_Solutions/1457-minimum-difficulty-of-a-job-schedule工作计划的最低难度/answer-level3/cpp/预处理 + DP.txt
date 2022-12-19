dp[d][Length] 意味着将长度为Length的工作计划，划分为d段（天）完成的最低总长度
为了计算方便，提前记录好任务（i...j）之间的最难工作记为maxi[i][j];

这样动态转移方程就变成了
dp[day][j] = min(dp[day][j], dp[day - 1][k] + maxi[k][j - 1]);
我们可以把day天完成的任务 
拆成 day-1天 加 1天 的子任务解决 

```
class Solution {
public:
	int minDifficulty(vector<int>& jobDifficulty, int d) {
		int maxi[310][310];
		int dp[15][310];
		int n = jobDifficulty.size();
		if (d > n) return -1;
		memset(maxi, 0, sizeof(maxi));
		memset(dp, 0x3f, sizeof(dp));

		for (int i = 0; i < n; i++) {
			maxi[i][i] = jobDifficulty[i];
			for (int j = i + 1; j < n; j++)
				maxi[i][j] = max(maxi[i][j - 1], jobDifficulty[j]);
		}
		dp[0][0] = 0;
		for (int day = 1; day <= d; day++) {
			for (int j = day; j <= n; j++) {
				for (int k = day-1; k < j; k++) {
					dp[day][j] = min(dp[day][j], dp[day - 1][k] + maxi[k][j - 1]);
				}
			}
		}
		return dp[d][n];
	}
};
```

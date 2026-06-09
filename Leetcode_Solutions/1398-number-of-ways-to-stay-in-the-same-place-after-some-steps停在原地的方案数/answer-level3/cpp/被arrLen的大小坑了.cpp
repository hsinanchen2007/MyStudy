题目实际上不难，用动态规划很容易做，`dp[i][j]=dp[i][j-1]+dp[i][j]+dp[i][j+1]`，dp[i][j]表示i步到达j处的方法个数。
关键是我被arrLen的大小坑了，steps小于arrLen时根本不用考虑每行后面的计算，因为最终结果根本用不到那些值。因此dp矩阵的大小只要steps*steps就可以了，实际上右下角的那个三角也可以不要。
```
class Solution {
public:
	int numWays(int steps, int arrLen) {
		int max = 1000000007;
		int** dp = new int*[steps];
		for (int i = 0; i < steps; i++)
			dp[i] = new int[steps + 1];
		for (int i = 0; i < steps; i++){
			for (int j = 0; j < steps + 1; j++)
				dp[i][j] = 0;
		}
		dp[0][0] = 1;
		for (int i = 1; i < steps; i++){
			for (int j = 0; j < steps + 1; j++){
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= max;
				if (j>0){
					dp[i][j] += dp[i - 1][j - 1];
					dp[i][j] %= max;
				}
				if (j < arrLen - 1 && j < steps){
					dp[i][j] += dp[i - 1][j + 1];
					dp[i][j] %= max;
				}
			}
		}
		int res = dp[steps - 1][0];
		if (arrLen>1)
			res += dp[steps - 1][1];
		res %= max;
		return res;
	}
};
```

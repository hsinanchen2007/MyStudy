## 动态规划
状态转移方程：`dp[i][j] = max(dp[i-1][j], dp[i-1][(ModNum + j - nums[i] % ModNum) % ModNum] + nums[i])`
1. `dp[i][j]`代表前`i`个数余数为`j`时最大和。
2. 知道了`dp[i][j]`代表的状态意义之后，状态转移方程就好理解了。如果不将`nums[i]`加进来，`dp[i][j]`取值即为`dp[i-1][j]`；如果将`nums[i]`加进来，则`dp[i][j]`取值为`dp[i-1][nMutNum] + nums[i]`，其中`(nMutNum + nums[i]) % ModNum == j`，因此`nMutNum = ModNum + j - nums[i] % ModNum`，两者取最大值即为`dp[i][j]`的最优解。
3. 比如，`num[i]`等于`5`时，那么它除以`ModNum(3)`的余数是`nMod(2)`，所以`dp[i][j(1)] = max(dp[i-1][j(1)], dp[i-1][nMutNum(2)] + nums[i])`。
4. 由于状态转移方程中只用到了`dp[i]`和`dp[i-1]`，因此空间也可以优化到只使用`2 * ModNum`。
```
class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		const int ModNum = 3;
		vector<vector<int>> dpAns(2, vector<int>(ModNum, -1));
		dpAns[0][0] = 0;
		for (size_t i = 0; i < nums.size(); ++i) {
			// 不使用nums[i]时
			for (int j = 0; j < ModNum; ++j)
				dpAns[1][j] = dpAns[0][j];

			// 使用nums[i]时
			int nMod = nums[i] % 3;
			for (int j = 0; j < ModNum; ++j) {
				// 相对于ModNum的补数
				int nMutNum = (ModNum + j - nMod) % ModNum;
				if (dpAns[0][nMutNum] != -1)
					dpAns[1][j] = max(dpAns[1][j], dpAns[0][nMutNum] + nums[i]);
			}

			// 空间优化，递进
			for (size_t j = 0; j < ModNum; ++j) {
				dpAns[0][j] = dpAns[1][j];
			}
		}

		return dpAns[0][0];
	}
};
```
我果真不适合写题解，写文章啊！
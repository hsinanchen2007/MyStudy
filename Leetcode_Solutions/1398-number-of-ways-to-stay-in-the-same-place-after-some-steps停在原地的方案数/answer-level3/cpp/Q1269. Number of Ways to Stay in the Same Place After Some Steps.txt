## 动态规划
1. 看懂题目之后，动态转移方程很好写：`dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]`，`dp[i][j]`代表走了`i`步之后到达`j`位置的方案数。
2. 由上面的状态转移方程可以看到，第`i`步的结果只和上一步`i-1`有关。于是，状态转移方程可以改写成`dp[1][j] = dp[0][j] + dp[0][j-1] + dp[0][j+1]`，其中`dp[0][j]`代表上一步到`j`位置的方案数，`dp[1][j]`代表当前这一步到达`j`位置的方案数。同时，可以对空间复杂度进行优化，由原来的`O(steps * arrLen)`优化到`O(2 * arrLen)`。每次这一步走完之后，都需要将`dp[1]`状态重置到`dp[0]`状态。
3. 即使如此，时间复杂度仍然高达`O(steps * arrLen)`，对于极限状态依旧存在超时的问题。我们注意到，**每次移动只能移动一格，即使所有步数全部向右移动，也只能到达`steps+1`位置**，后面位置的计算完全没有必要。因此，基于这一点，我们可以计算出一个最大的能到达的长度`nMaxLen=min(step + 1, arrLen)`，我们计算到这个位置即可。这样子空间复杂度和时间复杂度都降到了`O(steps^2)`。
4. 其实应该还可以继续进行优化：一共走`steps`步，按照最远的走法，考虑往回走到0位置，我们只需保留`steps/2`的长度即可。不过这只是一时的想法。
5. 另外补充一点数学知识：`x % ModNum + y % ModNum = (x + y) % ModNum`。
```
class Solution {
public:
	int numWays(int steps, int arrLen) {
		int ModNum = 1000000007;
		int nMaxLen = min(steps + 1, arrLen);
		vector<int> vecNumWays(nMaxLen, 0);
		vector<int> vecLastNumWays(nMaxLen, 0);
		vecLastNumWays[0] = 1;
		for (int i = 1; i <= steps; ++i) {
			nMaxLen = min(i + 1, arrLen);
			for (int j = 0; j < nMaxLen; ++j) {
				// stay in the same place
				vecNumWays[j] = vecLastNumWays[j];
				// move 1 position to the right
				if (j > 0)
					vecNumWays[j] = (vecNumWays[j] + vecLastNumWays[j - 1]) % ModNum;
				// move 1 position to the left
				if (j < nMaxLen - 1)
					vecNumWays[j] = (vecNumWays[j] + vecLastNumWays[j + 1]) % ModNum;
			}

			for (int j = 0; j < nMaxLen; ++j)
				vecLastNumWays[j] = vecNumWays[j];
		}

		return vecNumWays[0];
	}
};
```
详情见代码注释
```
class Solution {
public:
	int getMoneyAmount(int n) {
		//动态规划思想，用二分查找不一定能得到最后的最优解，所以需要动态规划的思想
		//用dp查找来代替2分查找这个概念
		//
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		//dp[i][j]表示从数i到数j之间进行猜测，最优划分查找下的最小的花费（保证最大值最小）
		//动态规划的转移方程 dp[i][j]= min(k+max(dp[i][k-1],dp[k+1][j]) k在闭区间[i+1,j-1]中
		for (int len = 2; len <= n; len++) {
			for (int i = 1; i + len <= n; i++) {
				int minRes = INT_MAX;
				int j = i + len;
				//用到了一个小技巧，就是当k小于[i,j]的中间值时，总会是右边区间的值更大（进而选取右边区间）
				//，为了最小化最大值，从中间位置开始进行遍历
				for (int k = i + (j-i) / 2; k < j; k++) {
					int res = k + max(dp[i][k - 1], dp[k + 1][j]);
					minRes = min(minRes, res);
				}
				dp[i][j] = minRes;
			}
		}
		return dp[1][n];
	}
};
```

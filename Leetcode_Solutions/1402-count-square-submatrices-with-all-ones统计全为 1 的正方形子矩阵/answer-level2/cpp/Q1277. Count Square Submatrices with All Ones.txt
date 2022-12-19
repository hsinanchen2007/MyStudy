### 动态规划（递推）
文首推荐LeetCode官方题解：[A1277. Count Square Submatrices with All Ones](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/tong-ji-quan-wei-1-de-zheng-fang-xing-zi-ju-zhen-b/)
 - 我也是看了官方题解的提示之后才做出来的。
 - `dp[i][j]`表示以`(i, j)`为右下角的最大正方形边长，同时，也表示以`(i, j)`为右下角的正方形的个数。
 - 状态转移方程是：`dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])`。
 - 在计算出所有的`dp[i][j]`后，我们将它们进行累加，就可以得到矩阵中正方形的数目。

```
class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		vector<vector<int>> vecCount(matrix.size(), vector<int>(matrix[0].size(), 0));
		// 初始化第一行（懒得写i==0的判断）
		for (size_t i = 0; i < matrix[0].size(); ++i)
			vecCount[0][i] = matrix[0][i];

		for (size_t i = 1; i < matrix.size(); ++i) {
			// 初始化第一列（懒得写j==0的判断）
			vecCount[i][0] = matrix[i][0];
			for (size_t j = 1; j < matrix[i].size(); ++j) {
				if (matrix[i][j])
					vecCount[i][j] = min(min(vecCount[i - 1][j], vecCount[i][j  -1]), vecCount[i - 1][j - 1]) + 1;
			}
		}

		int nCount = 0;
		for (size_t i = 0; i < matrix.size(); ++i) {
			for (size_t j = 0; j < matrix[i].size(); ++j) {
				nCount += vecCount[i][j];
			}
		}

		return nCount;
	}
};
```

### 解题思路
动态规划构造转移方程
用个矩阵来记录

### 代码

```python3
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if text1 == text2:
            return len(text1)
        all_col = len(text1)
        all_row= len(text2)
        # 构造一个全0矩阵出来
        dp = [([0] * all_col) for i in range(all_row)]
        # 这个时候把这个变成矩阵，然后构造状态转移方程
        # 最长子序列只可能继承左边或者上面的，如果相等就加一
        # dp[i][j] = max(dp[i- 1][j],dp[i][j-1],dp[i-1][j-1] + 1)
        for row in range(all_row):
            for col in range(all_col):
                if row == col == 0:
                    if text1[col] == text2[row]:
                        dp[0][0] = 1
                elif row == 0:
                    if text1[col] == text2[row]:
                        dp[row][col] = 1
                    else:
                        dp[row][col] = dp[row][col - 1]
                elif col == 0:
                    if text1[col] == text2[row]:
                        dp[row][col] = 1
                    else:
                        dp[row][col] = dp[row - 1][col]
                else:
                    if text1[col] == text2[row]:
                        dp[row][col] = max(dp[row - 1][col],dp[row][col - 1],dp[row - 1][col - 1] + 1)
                    else:
                        dp[row][col] = max(dp[row - 1][col],dp[row][col - 1])
        # print(dp)
        return dp[-1][-1]
```
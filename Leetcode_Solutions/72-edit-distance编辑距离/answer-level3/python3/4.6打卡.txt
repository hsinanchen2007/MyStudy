### 解题思路
此处撰写解题思路

### 代码

```python3
import functools
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # 动态规划
        # m, n = len(word1), len(word2)
        # # 有一个字符串为空串
        # if m * n == 0: return m+n
        # # 用 dp[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离
        # dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        # # 边界状态初始化
        # # 一个空串和一个非空串的编辑距离为 D[i][0] = i 和 D[0][j] = j
        # for i in range(m+1):
        #     dp[i][0] = i
        # for j in range(n+1):
        #     dp[0][j] = j
        # # 
        # for i in range(1, m+1):
        #     for j in range(1, n+1):
        #         # 不需要替换
        #         if word1[i-1] == word2[j-1]:
        #             dp[i][j] = dp[i-1][j-1]
        #         # 至少要进行一次操作，取最小值
        #         else:
        #             dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        # return dp[m][n]

        # 记忆化递归
        @functools.lru_cache(None)
        def dp(i, j):
            # base case
            if i == -1: return j + 1
            if j == -1: return i + 1
            if word1[i] == word2[j]:
                return dp(i-1, j-1)
            else:
                return min(dp(i-1, j), dp(i, j-1), dp(i-1, j-1)) + 1
        return dp(len(word1)-1, len(word2)-1)

        
```
**思路：**

按照题意，这道题目可以看做一个背包问题，用动态规划解决。用 `dp[i][j]` 表示 `i` 个骰子掷出 `j` 点的方案数目。状态转移方程为 `dp[i][j] = dp[i][j] + dp[i - 1][j - k]  (1 <= k <= f)`。代码实现可以用递推或者记忆化搜索。

**图解：**

![图解](https://pic.leetcode-cn.com/b3a2fcd67cb3abc5f36fdc17fc3aaeede66284a92771d231c130c5635ec79ce4.png)

**代码：**

递归 + 记忆化搜索

```python
class Solution:
    def __init__(self):
        self.memo = {}
        self.m = 10 ** 9 + 7
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        if (d, f, target) in self.memo:
            return self.memo[(d, f, target)]
        if target <= 0:
            return 0
        if d == 1 and target <= f:
            return 1
        if d == 1 and target > f:
            return 0
        
        ans = 0
        for i in range(1, f + 1):
            ans += self.numRollsToTarget(d - 1, f, target - i)
        ans = ans % self.m
        self.memo[(d, f, target)] = ans
        return ans
```

递推 + 动态规划

```python
class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        m = 10 ** 9 + 7
        dp = [[0] * (target + 1) for _ in range(d + 1)]
        dp[0][0] = 1
        for i in range(1, d + 1):
            for j in range(1, f + 1):
                for k in range(j, target + 1):
                    dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % m
        return dp[d][target]
```

![image.png](https://pic.leetcode-cn.com/0f49ea828b36a50f9eff15cdc7229ba820dfe07b4079cf75ab451fc0457f923a-image.png)


```

'''
动态规划
dp[i][j] 表示[i, j]区段是不是一个回文
dp[i][j] = dp[i+1][j-1] and s[i] == s[j]
求出dp数组之后递归拆解字符串可能的不同长度的回文前缀，找拆分
次数最小的方案
'''

class Solution:

    def solve(self, cur, n, m, memo):
        if cur == n:
            return 0

        if cur in memo:
            return memo[cur]

        min_val = 0x7fffffff
        for end in m[cur]:
            min_val = min(min_val, self.solve(end + 1, n, m, memo))
        memo[cur] = min_val + 1
        return min_val + 1

    def minCut(self, s: str) -> int:
        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]
        m = {i:[i] for i in range(n)}      # 回文起点到终点的记录

        for i in range(n-1, -1, -1):
            dp[i][i] = True
            for j in range(i+1, n):
                if j == i + 1:
                    dp[i][j] =  s[i] == s[j]
                else:
                    dp[i][j] = s[i] == s[j] and dp[i+1][j-1]
                if dp[i][j]:
                    m[i].append(j)

        return self.solve(0, n, m, {}) - 1
```

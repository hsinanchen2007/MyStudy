![image.png](https://pic.leetcode-cn.com/da581a1b1048e396df6081af5b7ee1bc7c351efce21a79e170631815248a3bd7-image.png)


```
from functools import lru_cache
class Solution:
    # 不对称的字符个数
    @lru_cache(typed=False)
    def getDiffCharNum(self, s: str):
        i, j = 0, len(s)-1
        ans = 0
        while i < j:
            if s[i] != s[j]:
                ans += 1
            i, j = i+1, j-1
        return ans

    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)

        # dp(i, j) 表示前i个字符分j组需要操作最小次数
        dp = [[0x7fffffff for _ in range(k+1)] for _ in range(n)]
        for i in range(n):
            for j in range(1, k+1):
                if j == 1:
                    dp[i][j] = self.getDiffCharNum(s[:i+1])
                else:
                    # 最后一组为s[x: i]
                    x = i
                    while x >= j-1:
                        dp[i][j] = min(dp[i][j], self.getDiffCharNum(s[x:i+1]) + dp[x-1][j-1])
                        x -= 1
        return dp[n-1][k]
```

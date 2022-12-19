### 解题思路
- s从末尾开始对t匹配；
- 后一位匹配好前一位才可行；

### 代码

```python3
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        if not s or not t:
            return 0
        dp = [0] * len(t)
        dp += [1]
        for i in range(len(s) - 1, -1, -1):
            for j in range(len(t)):
                if s[i] == t[j]:
                    dp[j] += dp[j + 1]
        return dp[0]
```
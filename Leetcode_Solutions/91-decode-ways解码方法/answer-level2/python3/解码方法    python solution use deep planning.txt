### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        l = len(s)
        if l==0:
            return 0
        
        dp = [0]*(l+1)
        dp[0] = 1

        for i in range(1,l+1):
            ele = int(s[i-1])
            if 1 <= ele <= 9:
                dp[i] += dp[i-1]

            if i>=2:
                t = int(s[i-2])*10+int(s[i-1])
                if 10 <= t <= 26:
                    dp[i] += dp[i-2]
        return dp[-1]
```




the  very nice method for this problem
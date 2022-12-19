### 解题思路
动态规划：若只能和前面一个数组合，就是dp[i-2];若只能单独，就是dp[i-1]；若两者皆可，就是dp[i-2]+dp[i-1]。注意"0"无处不在。

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        if "0" == s or s[0] == '0': return 0
        dp = [1]
        if len(s) >= 2: 
            if int(s[1]) == 0:
                if int(s[0:2]) > 26 or s[0:2] == '00':
                    dp.append(0)
                else:
                    dp.append(1)
            else:
                if s[0] == '0':
                    dp.append(0)
                elif int(s[0:2]) > 26:
                    dp.append(1)
                else:
                    dp.append(2)
        l = len(s)
        for i in range(2,l):
            if int(s[i]) == 0:
                if int(s[i-1:i+1]) > 26 or s[i-1:i+1] == '00':
                    dp.append(0)
                else:
                    dp.append(dp[i-2])
            else:
                if int(s[i-1:i+1]) > 26 or s[i-1] == '0':
                    dp.append(dp[i-1])
                else:
                    dp.append(dp[i-1]+dp[i-2])
        return dp[-1]
```
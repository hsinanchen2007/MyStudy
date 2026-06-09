### 解题思路
此处撰写解题思路
        前面一位是0时，dp[i] = dp[i-1]
        当前位为0，则只有10和20可以匹配，因此如果前面是1和2，则dp[i] = dp[i-1] + dp[i-2];否则dp[i]=dp[i-2]

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or int(s[0]) == 0:
            return 0
        best = [1,1]
        n = len(s)
        for i in range(2,n+1):
            if s[i - 1] == '0':
                if s[i-2] not in ['2','1']:
                    return 0
                else:
                    best.append(best[i-2])
            else:
                cur_value = int(s[i - 2:i])
                if int(s[i-2]) in [1,2] and cur_value <= 26:
                    best.append(best[i-1] + best[i-2])
                else:
                    best.append(best[i-1])


        return best[-1]
```
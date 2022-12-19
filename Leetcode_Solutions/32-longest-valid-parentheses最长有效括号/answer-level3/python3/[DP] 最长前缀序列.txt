## Methods
- DP三步：
  1. `D[i]` 表示以i位置字符结束的最长括号序列
  2. `D[i]` 转移方程：
      - `s[i-1] == '('`: `D[i] = D[i-1] + 2`
      - `s[i-1] == ')' and s[i - D[i-1] -1] == '('`: `D[i] = D[i-1] + D[i - D[i-1] - 2] + 2`
  3. 注意边界判断

## Solutions
```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        if not s:
            return 0
        d = [0] * n 

        res = 0
        for iind in range(n):
            if iind > 0 and s[iind] == ')':
                if s[iind-1] == '(':
                    if iind == 1:
                        d[iind] = 2
                    else:
                        d[iind] = d[iind-2] + 2
                else:
                    if iind - d[iind-1] - 1 < 0:
                        d[iind] = 0
                    elif s[iind-d[iind-1]-1] == '(':
                        if iind - d[iind-1] - 1 == 0:
                            d[iind] = d[iind-1] + 2
                        else:
                            d[iind] = d[iind-1] + 2 + d[iind - d[iind-1] - 2]
                res = max(res, d[iind])
        # print(d)
        return res
```
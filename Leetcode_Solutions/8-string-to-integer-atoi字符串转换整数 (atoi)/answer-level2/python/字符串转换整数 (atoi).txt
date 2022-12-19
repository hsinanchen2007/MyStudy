### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        if len(str) == 0:
            return 0
        s = list(str)
        i = 0
        n = 1
        r = 0
        while(s[i] == ' '):
            i = i + 1
            if i == len(s):
                break
        if i == len(s):
            return 0
        s = s[i:]
        if (s[0] < '0' or s[0] > '9') and s[0] != '+' and s[0] != '-':
            return 0
        if s[0] == '-':
            n = -1
            s = s[1:]
        elif s[0] == '+':
            n = 1
            s = s[1:]
        if len(s) == 0:
            return 0
        m = 0
        while(s[m] >= '0' and s[m] <= '9'):
            m = m + 1
            if m == len(s):
                break
        s = s[:m]
        s = s[::-1]
        for i in range(len(s)):
            r = r + int(s[i]) * 10 ** i
        r = r * n
        if r < -2 ** 31:
            r = -2 ** 31
        if r > 2 ** 31 - 1:
            r = 2 ** 31 - 1
        return r
```
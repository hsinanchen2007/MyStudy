### 解题思路

每次向后看一位:

- 若后一位的面值比前一位大, 则结果中加入二者之差, 指针加 2
- 若后一位的面值小于或等于前一位, 则直接加入前一位的面值, 指针加 1

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'M': 1000, 'D': 500, 'C': 100, 'L': 50, 'X': 10, 'V': 5, 'I': 1}
        ret = 0
        i = 0
        while(i < len(s)):
            if i < len(s) - 1 and d[s[i]] < d[s[i+1]]:
                ret += (d[s[i+1]] - d[s[i]])
                i += 2
            else:
                ret += d[s[i]]
                i += 1
        return ret
```
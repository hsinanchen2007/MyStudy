### 解题思路
字符为偶数个，直接相加，基数个要减一后相加，另基数加一

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = {}
        for c in s:
            d.setdefault(c,0)
            d[c] += 1
        acc = 0
        flag = 0
        for v in d.values():
            if v%2 == 0:
                acc += v
            else:
                flag = 1
                acc += v - 1
        return acc + flag
```
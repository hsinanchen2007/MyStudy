### 解题思路
倒叙遍历, 
归纳总结出来每一位的规律.
比如BAA = 2 * 26 ^ 2 + 1 * 26 ^ 1 + 1 * 26 ^ 0

### 代码

```python3
class Solution:
    def titleToNumber(self, s: str) -> int:
        total = 0
        i = 0
        for j in range(len(s)-1, -1, -1):
            c = s[j]
            total = total + (ord(c) - 64) * (26 ** i)
            i += 1
        return total 
```
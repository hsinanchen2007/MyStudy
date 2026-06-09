### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        d = {}
        for c in s:
            d[c] = d.get(c, 0) + 1
        L = []
        for k, v in d.items():
            if v == 1:
                L.append(k)
        for i in range(len(s)):
            if s[i] in L:
                return i
        return -1
```
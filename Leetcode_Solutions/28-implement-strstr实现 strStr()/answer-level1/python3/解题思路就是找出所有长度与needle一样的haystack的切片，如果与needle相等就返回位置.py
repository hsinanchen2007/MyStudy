### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        m = list(haystack)
        n = list(needle)
        a = len(n)
        for i in range(len(m)-a+1):
            s = m[i:i+a]
            if s == n:
                return i
        return -1
```
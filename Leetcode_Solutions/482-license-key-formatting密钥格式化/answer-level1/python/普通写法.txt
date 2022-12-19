### 解题思路
普通写法，看了尾插法思路，可能更好一些

### 代码

```python3
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        s, l = '', 0
        for i in S:
            if i != '-':
                l, s = l + 1, s + i
        i = l % K if l % K != 0 else K
        res = s[:i]
        while i < l:
            i += K
            res = res + '-' + s[i - K:i] 
        return res.upper()

```

### 代码

```python3
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        if 2*k > len(s) - 1:
            return s[:k][::-1] + s[k:]
        res = ""
        for i in range(0, len(s), 2*k):
            if i+2*k < len(s):
                res += s[i:i+k][::-1]+s[i+k:i+2*k]
            else:
                res += s[i:i+k][::-1]+s[i+k:]
        return res

```
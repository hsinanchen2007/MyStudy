
### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res = 0
        i = 0
        j = 0
        while j < len(s):
            tmp = s[i:j+1]
            if tmp.count("R") == tmp.count("L"):
                res += 1
                i = j + 1
            j += 1
        return res
```
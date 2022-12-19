### 解题思路

### 代码

```python
class Solution(object):
    def isSubsequence(self, s, t):
        if not s:
            return True
        if len(t) < len(s):
            return False
        i = 0
        while i < len(s):
            for j,c in enumerate(t):
                if c == s[i]:
                    i += 1
                    if i == len(s):
                        return True
                if j == len(t) - 1:
                    return False
        return False
```
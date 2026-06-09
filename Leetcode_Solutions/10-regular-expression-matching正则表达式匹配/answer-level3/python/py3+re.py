### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        import re
        canfind=re.findall(p,s)
        if len(canfind)==0:
            return False
        else:
            for i in canfind:
                if i==s:
                    return True
            return False
```
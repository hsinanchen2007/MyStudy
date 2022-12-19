### 解题思路
暴力替换'++'为'-', 递归

### 代码

```python3
from functools import lru_cache
class Solution:
    @lru_cache(None)
    def canWin(self, s: str) -> bool:
        for i in range(1, len(s)):
            if s[i-1] == s[i] == '+' and not self.canWin(s[:i-1]+'-'+s[i+1:]):
                return True
        return False
                
```
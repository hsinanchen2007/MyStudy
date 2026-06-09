### 解题思路
- 记忆化搜索
- 如果当前的反转使得对方无法获得胜利，那么当前获得胜利

### 代码

```python
from functools import lru_cache


class Solution:
    @lru_cache(None)
    def canWin(self, s: str) -> bool:
        length = len(s)
        for i in range(length - 1):
            if s[i] == "+" and s[i + 1] == "+":
                if not self.canWin(s[:i] + "--" + s[i + 2:]):
                    return True
        return False
```
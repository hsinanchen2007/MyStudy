```python
from functools import lru_cache
class Solution:
    @lru_cache(None)
    def minCut(self, s: str) -> int:
        if len(s) == 0 or len(s) == 1: return 0
        ans = float('inf')
        for j in range(len(s)):
            if s[: j + 1] == s[: j + 1][::-1]:
                if j == len(s) - 1:ans = 0
                ans = min(ans, 1 + self.minCut(s[j + 1:]))
        return ans
    

```
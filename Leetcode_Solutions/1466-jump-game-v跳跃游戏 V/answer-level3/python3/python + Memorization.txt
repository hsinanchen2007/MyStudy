```python
from functools import lru_cache
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        @lru_cache(None)
        def jump(index):
            left = max(0, index - d)
            right = min(len(arr) - 1, index + d)
            res = 0
            for i in range(index + 1, right + 1):
                if arr[i] < arr[index]:
                    res = max(res, jump(i))
                else: break
            for i in range(index - 1, left - 1, -1):
                if arr[i] < arr[index]:
                    res = max(res, jump(i))
                else: break
            return 1 + res
        res = 0
        for i in range(len(arr)):
            res = max(res, jump(i))
        return res
```
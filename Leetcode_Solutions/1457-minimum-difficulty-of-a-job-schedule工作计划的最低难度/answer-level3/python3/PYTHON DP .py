
新年好！
拔了牙还感冒了 一周没刷题 差一点写出来 最后看的国际版大神的解法 想法是一样的
```
from functools import lru_cache
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:     
        @lru_cache(None)
        def dfs(i, d):
            n = len(jobDifficulty)
            if n < d: 
                return -1
            if d == 1:
                return max(jobDifficulty[i:])
            res, maxd = float('inf'), 0
            for j in range(i, n - d + 1):
                maxd = max(maxd, jobDifficulty[j])
                res = min(res, maxd + dfs(j + 1, d - 1))
            return res
        return dfs(0, d)
```

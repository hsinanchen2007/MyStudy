```python
from functools import lru_cache
def mincostTickets(days, costs):
    """
        1. dp问题: dp(i) = min(
                dp(i+1) + costs[0],
                dp(i+7) + costs[1],
                dp(i+30) + costs[2])
        2. 用到了lru_cache缓存技术
    """
    dur = [1, 7, 30]
    @lru_cache(None)
    def dp(i):
        if i > 365:
            return 0
        if i in days:
            return min(dp(i+d) + c for d, c in zip(dur, costs))
        else:
            return dp(i + 1)
    
    return dp(1)

print(mincostTickets([1,4,6,7,8,20], [2,7,15]))
```
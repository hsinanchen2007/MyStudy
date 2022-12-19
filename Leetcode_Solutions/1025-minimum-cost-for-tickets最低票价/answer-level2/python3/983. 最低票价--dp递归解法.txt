### 解题思路
dp解法：dp(i)表示从i到最后一天的最小开销
### 代码

```python3
import functools

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        cnt = [1, 7, 30]
        @functools.lru_cache(None)
        def dp(i):
            if i>days[-1]:
                return 0
            elif i in days:
                return min(dp(i+c)+d for c,d in zip(cnt, costs))
            else:
                return dp(i+1)
        return dp(1)
```
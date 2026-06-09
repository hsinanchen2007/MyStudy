相当于带备忘录的搜索
```
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:

        @lru_cache()
        def helper(i):
            if i > days[-1]:
                return 0
            if i not in days:
                return helper(i+1)
            return min(helper(i+d)+c for d, c in zip([1,7,30], costs))
        return helper(1)
             
```

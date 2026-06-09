```python
from functools import lru_cache
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        arr_sum = sum(nums)
        if arr_sum % 2 == 1: return False
        target = arr_sum // 2
        nums.sort(reverse = True)
        ans = False
        @lru_cache(None)
        def dfs(i, target):
            nonlocal ans
            if ans == True or target < 0 or i >= len(nums): return 
            if target == 0:
                ans = True
                return
            dfs(i + 1, target - nums[i])
            dfs(i + 1, target)
        dfs(0, target)
        return ans
```
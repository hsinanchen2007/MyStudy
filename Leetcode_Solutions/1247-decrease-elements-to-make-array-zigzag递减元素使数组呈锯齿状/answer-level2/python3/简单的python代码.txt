```
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        N = len(nums)
        a = sum([max(0, nums[i] - min(nums[i-1], nums[i+1] if i+1 < N else float('inf')) + 1) for i in range(1, N, 2)])
        b = sum([max(0, nums[i] - min(nums[i-1] if i > 0 else float('inf'), nums[i+1] if i+1 < N else float('inf')) + 1) for i in range(0, N, 2)])
        
        return min(a, b)
```

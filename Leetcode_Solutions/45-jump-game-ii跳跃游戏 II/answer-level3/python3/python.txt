```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        
        # Time complexity: O(N)
        # Space complexity: O(1)

        end, maxDistance = 0, 0
        ans = 0
        if len(nums) == 1: return 0
        for i, num in enumerate(nums):
            maxDistance = min(len(nums), max(maxDistance, i + num))
            if i == end:
               ans += 1
               end = maxDistance
               if end >= len(nums) - 1: break
        return ans
```
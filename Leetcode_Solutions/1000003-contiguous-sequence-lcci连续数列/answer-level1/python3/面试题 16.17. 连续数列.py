

```python []
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1] > 0 and nums[i - 1]
        return max(nums)
```
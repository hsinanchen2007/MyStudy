```python
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        # sliding window
        # Time complexity: O(N)
        # Space complexity: O(1)
        if nums == []: return 0
        res, tempSum, l = float('inf'), 0, -1
        for i, num in enumerate(nums):
            tempSum += num
            while tempSum >= s:
                res = min(res, i - l)
                l += 1
                tempSum -= nums[l]
        return res if res != float('inf') else 0
```
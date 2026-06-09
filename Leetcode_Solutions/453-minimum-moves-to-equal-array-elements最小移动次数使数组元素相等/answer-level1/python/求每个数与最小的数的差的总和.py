
```python []
class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        min_value = min(nums)
        r = 0
        for i in range(len(nums)):
            r += nums[i]-min_value
        return r
```

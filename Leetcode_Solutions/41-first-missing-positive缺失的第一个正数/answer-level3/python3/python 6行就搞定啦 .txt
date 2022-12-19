```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not nums or max(nums) <= 0:  # max(nums)可以看作遍历了一遍nums
            return 1
        else:
            for i in range(1, max(nums)):
                if i not in nums:
                    return i
            return max(nums)+1
```
复杂度为O(n)，并且没用额外空间

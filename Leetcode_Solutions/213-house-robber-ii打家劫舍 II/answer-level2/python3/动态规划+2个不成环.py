```
class Solution:
    def rob(self, nums: List[int]) -> int:
        def robline(nums):
            if not nums:
                return 0
            p2 = 0
            p1 = nums[0]
            for i in range(1, len(nums)):
                p2, p1 = p1, max(p1, p2+nums[i])
            return p1
        if len(nums) == 1:
            return nums[0]
        return max(robline(nums[1:]), robline(nums[:-1]))
```

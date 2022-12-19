```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0 or not nums:
            return 0
        n = len(nums)
        if n == 1:
            return nums[0]
        return max(self.tmp(nums, 0, n - 2), self.tmp(nums, 1, n - 1))
    def tmp(self, nums, left, right):
        pre2, pre1 = 0, 0
        for i in range(left, right + 1):
            pre2, pre1 = pre1, max(pre1, pre2 + nums[i])
        return pre1
```
挺简洁的写法。

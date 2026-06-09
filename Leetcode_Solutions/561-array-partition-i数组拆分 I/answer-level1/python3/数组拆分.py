本来以为很难，结果仔细认真读题以后发现其实很简单。
```
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        sums = 0
        for i in range(1,n,2):
            m = min(nums[i-1],nums[i])
            sums += m
        return sums
```

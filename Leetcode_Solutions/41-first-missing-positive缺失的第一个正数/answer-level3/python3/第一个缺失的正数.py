想到了排序法，没想到竟然通过了
```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums += [0]
        nums.sort()
        for i in range(1,len(nums)):
            if nums[i-1]+1>0 and nums[i-1]+1<nums[i]:
                return nums[i-1]+1
        return nums[-1]+1
```

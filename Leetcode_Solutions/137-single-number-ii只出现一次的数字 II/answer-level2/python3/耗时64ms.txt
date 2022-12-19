```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        n1 = len(nums)
        if n1 == 1:
            return(nums[0])
        for i in range(2,n1,3):
            if nums[i] != nums[i-2]:
                return(nums[i-2])
        return(nums[i+1])
```

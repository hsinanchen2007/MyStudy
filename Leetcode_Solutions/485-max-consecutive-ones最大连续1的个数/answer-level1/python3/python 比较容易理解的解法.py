```
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        t = 0
        max_=0
        for i in range(len(nums)):
            if nums[i] == 1:
                t+=1
                max_ = max(max_,t)
            else:
                t=0
        return max_
```

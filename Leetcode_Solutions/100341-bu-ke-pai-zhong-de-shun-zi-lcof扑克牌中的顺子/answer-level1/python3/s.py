```
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        countW = 0
        countS = 0
        nums.sort()
        for i in range(len(nums)-1):
            if nums[i] != 0 and nums[i] == nums[i+1]: return False
            if nums[i] == 0: countW += 1
            else:
                countS +=nums[i+1] - nums[i] -1
        if countW < countS: return False 
        return True
```

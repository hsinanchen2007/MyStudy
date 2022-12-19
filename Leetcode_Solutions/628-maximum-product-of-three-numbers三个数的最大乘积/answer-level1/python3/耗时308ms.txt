```
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()
        if nums[0] >= 0:
            return(nums[-1] * nums[-2] * nums[-3])
        elif nums[-1] <= 0:
            return(nums[0] * nums[1] * nums[2])
        elif nums[0] < 0 and nums[1] >= 0:
            return(nums[-1] * nums[-2] * nums[-3])
        elif nums[0] < 0 and nums[1] < 0 and nums[2] > 0:
            sum1 = nums[0] * nums[1] * nums[-1]
            sum2 = nums[-1] * nums[-2] * nums[-3]
            return(max(sum1,sum2))
        elif nums[2] < 0:
            sum1 = nums[0] * nums[1] * nums[-1]
            sum2 = nums[-1] * nums[-2] * nums[-3]
            return(max(sum1,sum2))
            
            
```

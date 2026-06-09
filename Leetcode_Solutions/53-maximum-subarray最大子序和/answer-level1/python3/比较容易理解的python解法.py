比较容易理解的python解法
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = nums[0]
        sum0 = 0
        for i in range(len(nums)):
            if sum0 > 0:
                sum0 += nums[i]
            else:
                sum0 = nums[i]
            ans = max(ans,sum0)
        return ans
        
```

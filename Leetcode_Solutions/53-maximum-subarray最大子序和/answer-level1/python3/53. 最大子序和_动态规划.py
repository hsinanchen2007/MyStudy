求出当前下标前的最大值，最后给出数组的最大值即可


```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i] + nums[i-1] > nums[i]:
                nums[i] = nums[i] + nums[i-1]
        
        return max(nums)
```

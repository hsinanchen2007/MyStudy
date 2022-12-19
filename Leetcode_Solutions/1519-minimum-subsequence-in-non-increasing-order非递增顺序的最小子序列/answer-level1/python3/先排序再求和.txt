```
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        target_sum,temp_sum = int(sum(nums) // 2), 0
        nums.sort(reverse=True)
        for i in range(len(nums)):
            temp_sum += nums[i]
            if temp_sum > target_sum: return nums[:i+1]

```

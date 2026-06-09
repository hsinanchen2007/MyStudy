```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])
        dp = [0 for i in range(len(nums)+1)]
        dp[1] = nums[0]
        dp[2] = nums[1]
        max0 = 0
        for i in range(2, len(nums)):
            dp[i+1] = nums[i] + max(dp[i-1], dp[i-2])  #强行以最后一个数结尾的最大偷窃财富，最后的最大值肯定在dp的最后两个数
        return max(dp[len(nums)], dp[len(nums)-1])
```

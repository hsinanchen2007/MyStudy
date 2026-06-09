分解问题，求解当前队列的从0开始的每个位置的最大利润，对于位置x的最大值为当前位置值加上当前为止向前数两个位置的最大利润与当前为止前一个为止的最大利润中更大的那个。

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = {}
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        dp[0] = 0
        dp[1] = nums[0]
        if len(nums) == 2:
            return max(nums[0],nums[1])
        dp[2] = max(nums[0],nums[1])
        for i in range(3,len(nums)+1):
            
            tmp = nums[i-1]+dp[i-2]
            neighbor = dp[i-1]
          
            larger = max(tmp,neighbor)
            dp[i] = larger
        return dp[len(nums)]


        
```

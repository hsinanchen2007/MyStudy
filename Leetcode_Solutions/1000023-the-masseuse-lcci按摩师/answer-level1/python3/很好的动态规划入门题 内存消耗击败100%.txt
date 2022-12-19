### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        
        if len(nums) == 0:
            return(0)

        dp = [[0,0] for i in nums]
        dp[0][0] = 0
        dp[0][1] = nums[0]

        for i in range(1,len(nums)):
            dp[i][0] = max(dp[i-1][0],dp[i-1][1])
            dp[i][1] = dp[i-1][0] + nums[i]
        
        return(max(dp[-1][0],dp[-1][1]))
```
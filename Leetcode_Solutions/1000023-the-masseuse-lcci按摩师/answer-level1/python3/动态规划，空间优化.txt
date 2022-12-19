状态转移方程：
dp[i][0],dp[i][1]分别表示当前预约不接受和接受

dp[i][0]=max(dp[i-1][0],dp[i-1][1])
dp[i][1]=dp[i-1][0]+nums[i]

分析可知，只保留最新状态就够，即dp[i][0]和dp[i][1]为后面所用

空间复杂度:O(n)
```
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp=[[0]*2 for _ in range(len(nums))]
        dp[0][1]=nums[0]
        for i in range(1,len(nums)):
            dp[i][0]=max(dp[i-1][0],dp[i-1][1])
            dp[i][1]=dp[i-1][0]+nums[i]
        return max(dp[-1])
```
空间复杂度:O(1)
```        
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        rej,ace=0,nums[0]
        for i in range(1,len(nums)):
            rej,ace=max(rej,ace),rej+nums[i]
        return max(rej,ace)
              
```


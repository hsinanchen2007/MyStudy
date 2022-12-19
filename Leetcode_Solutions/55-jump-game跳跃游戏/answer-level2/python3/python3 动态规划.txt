```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        #动态规划
        size = len(nums)
        dp = [False for i in range(size)]
        dp[0] = True
        for i in range(1,size):
            for j in range(i-1,-1,-1): #倒着判断
                if dp[j] == True and nums[j] >= i-j :
                    dp[i] = True
                    break
        
        return dp[-1]
            
```

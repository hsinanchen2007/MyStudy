### 解题思路
**1.二维空间**
dp[i][j]表示前i个元素能否得到和为j的bool值
初始化： j = 0 时，均为False
        j = nums[i] 时，dp[i][j] = True
        除此之外，状态方程均满足：dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i]]
**2.空间优化**
dp[j] = dp[j] or dp[j-n]
dp[j] 可以表示dp[i][j]也可以表示dp[i-1][j]
需要先求dp[i][j]再求dp[i][j-n]倒序处理，否则会出现覆盖dp[i-1][j-n]情况
### 代码
```python
class Solution(object):
    def canPartition(self, nums):
        if sum(nums) % 2 == 1:return False
        t = sum(nums)//2
        dp = [[False]*(t+1) for i in range(len(nums) + 1)]
        for j in range(t+1):
            for i in range(len(nums)):
                if j == nums[i]:
                    dp[i+1][j] = True
                elif j > nums[i]:
                    dp[i+1][j] = dp[i][j] or dp[i][j-nums[i]]
                else:
                    dp[i+1][j] = dp[i][j]
        return dp[-1][-1]

class Solution(object):
    def canPartition(self, nums):
        if sum(nums) % 2 == 1:return False
        t = sum(nums)//2
        dp = [False]*(t+1) 
        #dp[j] 可以表示dp[i][j]也可以表示dp[i-1][j]
        #需要先求dp[i][j]再求dp[i][j-n]倒序处理，否则会出现覆盖dp[i-1][j-n]情况
        for n in nums:
            for j in range(t,0,-1):
                if j == n:
                    dp[j] = True
                elif j > n:
                    dp[j] = dp[j] | dp[j-n]
        return dp[-1] 
       
```
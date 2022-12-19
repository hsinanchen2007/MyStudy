简单的动态规划问题，公式;

dp[i]=max(dp[i-2]+num[i],dp[i-1])

问题分为最后选择了第i个或者没有选择第i个。

dp[i]是前i个房间里的最优解，若选择了第i个，则答案就是第i个加dp[i-2]（i-2）的最优解
代码:
```
class Solution:
    def massage(self, nums):
        if len(nums)==0:
            return 0
        if len(nums) == 1:
            return nums[0]
        dp={}
        dp[0]=nums[0]
        dp[1]=max(nums[0],nums[1])
        for i in range(2,len(nums)):
            dp[i]=max(dp[i-2]+nums[i],dp[i-1])
        return  dp[len(nums)-1]
a=Solution()
nums=[]
print(a.massage(nums))
```
萌新刚学python，大佬勿喷。
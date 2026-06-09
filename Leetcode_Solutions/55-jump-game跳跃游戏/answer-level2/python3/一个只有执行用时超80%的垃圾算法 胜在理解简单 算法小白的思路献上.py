算是动态规划吧 

题目给出一个列表nums
我自己定义一个列表 dp，dp[i]的含义是 在nums[i]这个位置 能跳到的最远的距离
dp[0]=nums[0]
dp[1]=max(dp[0],nums[1]+1) dp[1]的最远距离为 'dp[0]和nums[1]的值+1' 中取最大值 
现在解释下这个等式中的nums[1]+1
因为dp[1]的值=nums[1]这个位置上能跳的最远距离（即nums[1]的值）+相对初始位置（nums[0]）的距离
i
每次计算dp[i]的距离前需要判断dp[i-1]的值是否大于i  
假设dp[4]=4 那么就是最大只能到达第四个位置 第五个位置永远无法到达 返回失败 
```
nums =[3,0,8,2,0,0,1]
num=[0,1]
class Solution:
    def canJump(self, nums):
        if len(nums)==0:return False
        if len(nums)==1: return True
        dp=[]
        dp.append(nums[0])
        for i in range(1,len(nums)-1):
            if dp[i-1]<i:return False
            dp.append(max(nums[i]+i,dp[i-1]))
            
        return (dp[-1])>=len(nums)-1


s =Solution()
print(s.canJump(nums))
```
代码如上
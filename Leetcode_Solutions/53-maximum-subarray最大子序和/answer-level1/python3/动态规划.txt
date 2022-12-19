# 动态规划
## 关键变量：  
maxSum：记录当前最大结果  
res：res+nums[i] 上一次求和与当前值相加

## 有两种情况发生：
1. 第i个数 > 上一次求和与当前最大结果   ==>  maxSum与res重新赋值为nums[i]；
2. （第i个数 > 上一次求和） But （第i个数 <= 当前最大结果）  ==>  仅res赋值为nums[i]；

同时，若 res > maxSum 将 maxSum赋值为res；

## 代码
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # S0: Error Proceess
        if len(nums)<=1:
            return nums[0]
        
        # S1: DP
        maxSum, res = nums[0], nums[0]
        for i in range(1, len(nums)):
            res += nums[i]
            
            if nums[i]>res and nums[i]>maxSum:
                res, maxSum = nums[i], nums[i]
                
            elif nums[i]>res:
                res = nums[i]
                
            if res > maxSum:
                maxSum = res
                
        return maxSum
```


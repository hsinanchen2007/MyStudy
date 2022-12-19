可以看到当 f(4)表示target=4时的所有组合数，f(4) = f(4-3) + f(4-2) + f(4 - 1) ，跟最后一次组合 3 2 1 这三枚硬币的和有关。   

# 初始化
关于初始化跟前面动态规划python有点不一样，前面的哥们是将dp[0] = 1空集当作一个解参与运算，实际上大同小异   

我这边是将空解设为0，实际上空解的意义还是将单独dp[num[i]] 作为初始化，将dp[nums[i]] 初始化为1，因为如果一个数字就能填满target，那么必定是有一种可能的。
```
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        
        # f(4) = (f(3) ) + (f(2) ) + (f(1) ) 
        
        dp = [0] * (target + 1)
        
        for n in nums:
            if (n <= target):   # 
                dp[n] += 1
        
        for i in range(1,target+1):
            
            for n in nums:
                if(i >= n):
                    dp[i] += (dp[i - n])
        
        return dp[target]
```
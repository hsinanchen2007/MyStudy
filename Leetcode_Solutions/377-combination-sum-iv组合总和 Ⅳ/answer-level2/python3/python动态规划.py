### 动态规划

```python3
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # 动态规划
        dp = [0] * (target+1) # dp[i]代表和为i的组合个数
        dp[0]  = 1 # 辅助作用
        nums.sort()   # 排序降低遍历代价
        for i in range(1, target+1):
            for num in nums:
                if num > i:
                    break
                dp[i] += dp[i - num] # 和为i的一种可能排列是(num, 和为i-num的所有可能排列)
        return dp[target]
                
                
                
            
            
```
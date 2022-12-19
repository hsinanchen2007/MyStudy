**思路：**
1. 状态设计： dp[i] 代表包含第 i 个房屋的当前最大偷盗金额

2. 状态转移：一旦选择偷盗第 i 个房屋，那么接下来可以选择 i+2 或者 i+3 个房屋
    (至于为什么没有i + 4呢，大家可以思考一下)
    所以状态转移方程为： 
    dp[i] = max(dp[i-2]+nums[i],nums[i]+ dp[i-3])

3. 输出： 关于为什么输出条件是 dp[-1]/dp[-2]: 
    这是由于对于本题，限制是不能偷盗相邻的屋子，而且房间金额为非负，对于最佳结果来说，最后两个房间则必有一个被访问到。
    包含最后两间屋子路线即为当前的最长路线（包括所有被偷的房子），所以找到这两者中的大值即为所需结果。
    
    
**代码：**


```python []
class Solution:
    def rob(self, nums) -> int:
        #边界条件处理
        N = len(nums)
        if N == 0: return 0
        if N == 1: return nums[0]
        if N == 2: return max(nums)
        else:
            dp = [0 for _ in range(N)]
            dp[0] = nums[0]
            dp[1] = nums[1]
            dp[2] = nums[0] + nums[2]
        # 防止数组越界，对dp[2]单独赋值，并从3开始循环
            for i in range(3,N):
                dp[i] = max(dp[i-2]+nums[i],dp[i-3]+nums[i])
        return max(dp[-1],dp[-2])
```


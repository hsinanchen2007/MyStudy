### 解题思路
1.使用dp数组保存1~n家劫取最大金钱
2.因为不能抢劫相邻的房子，所以至少隔一个房子抢劫
2.很明显，到第i家时(i>2),抢到的最大金钱应该是：第i-2家抢到的最大金钱加上当前第i家所抢到的钱，和i-1家抢到的钱的较大值。所以dp[i] =max(dp[i-2] + nums[i], dp[i-1]).

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:return 0
        if len(nums) == 1:
            return nums[0]
        dp = [0 for _ in range(len(nums))]        
        dp[0] = nums[0]
        dp[1] = max(nums[0],nums[1])
        for i in range(2,len(nums)):
            dp[i] = max(dp[i-2] + nums[i], dp[i-1])
        return dp[len(nums) - 1]
```
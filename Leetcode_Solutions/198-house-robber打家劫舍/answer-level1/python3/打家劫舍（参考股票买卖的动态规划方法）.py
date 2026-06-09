### 解题思路
核心在于定义状态，并得出状态方程，从而实现动态规划。
本题解受力扣第120题股票买卖的几个高赞题解启发，有兴趣的朋友可以前往一看，相信会有收获。
言归正传：

1. 定义两个状态：被盗和未被盗，相应的用0和1表示
2. 可得状态方程：F(n,0) = max{F(n-1,0), F(n-1,1)} & F(n,1) = F(n,0) + P(n)
                其中 F(n)表示偷到第n家后能得到的最高金额，P(n)表示第n家的存放金额
3. 实现动态规划：代码如下。时间复杂度是O(n)，空间复杂度O(1)

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        # 使用状态方程+动态规划：时间复杂度是O(n)
        # 定义状态为：被偷和没被偷
        if(len(nums) == 0):
            return 0
        profit_safe = 0
        profit_robbed = nums[0]
        for i in range(1,len(nums)):
            new_profit_safe = max(profit_safe, profit_robbed)
            new_profit_robbed = profit_safe + nums[i]
            profit_safe = new_profit_safe
            profit_robbed = new_profit_robbed
        return max(profit_robbed, profit_safe)
```
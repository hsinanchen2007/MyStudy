### 解题思路
经典dp，状态转移方程：dp[i] = max(dp[i] + dp[i-2], dp[i-1])
遍历整个数组，每次记录当前可获取的最大结果。
可以事先判断数组长度是否大于3，做一些预处理
### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) < 3:
            return max(nums)
        nums[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            nums[i] = max(nums[i] + nums[i-2], nums[i-1])
        return nums[-1]
```
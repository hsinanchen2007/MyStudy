### 解题思路
设置dp[i]表示以nums[i]结尾的连续数组最大值，初态dp[0]很简单就是nums[0]。状态转移方程是这样想的：如果前面的数加起来是负数，那nums[i]就是对应的dp[i]，否则就是dp[i-1]+nums[i]。最后用result来记录每一次比较得到的最大值。
咸鱼本鱼，继续努力！

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [int] * len(nums)
        dp[0] = nums[0] ##dp初态
        result = nums[0]
        for i in range(1,len(nums)):
            dp[i] = max(nums[i],dp[i-1]+nums[i]) ##状态转移方程
            result = max(result,dp[i])
        return result

```
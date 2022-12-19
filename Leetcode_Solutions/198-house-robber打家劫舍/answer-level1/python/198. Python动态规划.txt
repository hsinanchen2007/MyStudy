### 解题思路
这道题很容易看出来是动态规划习题，子问题是前n个数可以获得的最大值。但是要注意的是并不一定打劫的两个房间之间会隔1个房间，如果真是这样的话，对于任意数列只有两个答案比较了，实际上打劫的两个房间之间可能隔1个房间或者2个房间。
这样我们就能得到转移方程dp[i] = max(dp[i - 1], nums[i] + dp[i - 2], nums[i] + dp[i - 3]) 。

### 代码

```python
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        elif length <= 2:
            return max(nums)
        elif length == 3:
            return max(nums[0] + nums[2], nums[1])
        dp = nums[:2] + [nums[0] + nums[2]] + [0] * (length - 3)
        for i in range(3, length):
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2], nums[i] + dp[i - 3])
        return dp[-1]
```
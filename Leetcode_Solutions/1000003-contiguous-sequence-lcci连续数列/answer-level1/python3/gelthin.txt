### 解题思路

这一题是经典题目，可以查看习题
[53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) 可以查看进一步的题解。
[gelthin-经典题-待进一步总结](https://leetcode-cn.com/problems/maximum-subarray/solution/gelthin-jing-dian-ti-by-gelthin/)

这里采用 DP 的写法。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        l = len(nums)
        if l==0:
            return
        if l==1:
            return nums[0]
        dp = [None]*l
        dp[0] = nums[0]
        result = dp[0]
        for i in range(1,l):
            dp[i] = max(dp[i-1]+nums[i], nums[i])
            result = max(result, dp[i])
        return result

```
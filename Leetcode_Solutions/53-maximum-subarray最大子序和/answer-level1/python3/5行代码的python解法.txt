动态规划的思路，声明两个变量，一个变量存最终结果，一个缓存对目前状态有增益的子序列之和。
如果之前的缓存的子序列之和大于零，说明其是对之后状态有增益的，加上当前状态的值并更新缓存；反之则舍弃，只取当前状态的值更新至缓存。
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans, sums = float('-inf'), 0
        for i in range(len(nums)):
            sums = sums + nums[i] if sums > 0 else nums[i]
            ans = max(sums, ans)            
        return ans
```

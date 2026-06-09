### 解题思路
一个子序列一定会以一个数结尾，于是将状态定义成：dp[i] 表示以 nums[i] 结尾的“最长上升子序列”的长度，注意这个定义中 nums[i] 必须被选取，且必须被放在最后一个元素。

第 2 步：考虑状态转移方程；
遍历到 nums[i] 时，考虑把索引 i 之前的所有的数都看一遍，只要当前的数 nums[i] 严格大于之前的某个数，那么 nums[i] 就可以接在这个数后面形成一个更长的上升子序列。因此，dp[i] 就等于索引 i 之前严格小于 nums[i] 的状态最大者 +1。
第 3 步：考虑初始化：dp[0] = 1，1 个字符当然也是长度为 1 的上升子序列；
第 4 步：考虑输出：所有 dp[i] 中的最大值（dp[i] 考虑了所有以 nums[i] 结尾的上升子序列）；
第 5 步：考虑状态压缩：之前所有的状态都得保留，因此无法压缩。

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n ==0:
            return 0
        dp = [0]*n
        dp[0] = 1
        for i in range(1,n):
            dp[i] = max([dp[j]+1 if nums[i]>nums[j] else 1 for j in range(i)])
        return max(dp[i] for i in range(n))
```
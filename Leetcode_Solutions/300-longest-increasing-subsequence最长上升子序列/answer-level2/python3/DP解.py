用 dp[i] 表示 nums[0:i+1] 能够组成的最长的上升子序列长度

当 k < i , 如果nums[i] > nums[k] 那么dp[i] = dp[k] + 1

所以我们只需要找到 满足 0 <= k < i , 并且 nums[i] > nums[k] 的 值最大的dp[k], 

把该 max_dp[k] + 1 赋值给 dp[i] 即可

复杂度分析：

时间复杂度： O(n^2) 对于每个i，都需要回述一遍dp[0] ~ dp[i-1], 共有n个数

空间复杂度： O(n)

```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        length = len(nums)
        dp = [1 for _ in range(length)]
        self.max_len = 1
        for i in range(1, length):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            self.max_len = max(self.max_len, dp[i])
        return self.max_len
```

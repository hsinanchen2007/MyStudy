### 解题思路
动态规划，定义dp[i]表示元素i位置的最长上升子序列的长度
对于nums[i], 和从0到i-1的元素比较，确定是否上升，从而计算出dp[i]
最大的dp[i]即为整个数组的最长上升子序列
### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = 0

        if len(nums) > 0:
            dp = [0 for i in range(len(nums))]

            for i in range(len(nums)):
                dp[i] = 1

                for j in range(0, i):
                    if nums[i] > nums[j]:
                        tmp = dp[j] + 1
                        if tmp > dp[i]:
                            dp[i] = tmp

                if dp[i] > res:
                    res = dp[i]

        return res
```
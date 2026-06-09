### 解题思路
动态规划方程：dp[ i ] = max( dp[ j ] ) + 1  ( j < i,且nums[ i ] > nums[ j ] )
dp[ i ] 表示以nums[ i ]结尾的上升子序列长度的最大值
寻找出所有dp[ i ]中的最大值

### 代码

```python
class Solution:
    # 以第i个数字为结尾的子序列的长度
    # dp[i] = max(dp[j]) +1 (j<i)
    def lengthOfLIS(self, nums: List[int]) -> int:
        t = len(nums)
        dp = [1]*t
        if t == 0:
            return 0
        max_ans = 1
        for i in range(1,t):
            max_val = 0
            for j in range(i):
                if nums[i] > nums[j]:
                    max_val = max(max_val,dp[j])

            dp[i] = max_val + 1

            if dp[i] > max_ans:
                max_ans = dp[i]
        return max_ans
```
主要思路是动态规划，用一个数组记录以第i个位置结尾的最长定差子序列。
同时，为了尽快找到上一个val-difference的位置，用一个dict记录最后一个val-difference的位置。
```
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        n = len(arr)
        dp = [1] * n
        last_val = {}
        max_length = 0
        for i in range(n):
            val = arr[i]
            if val - difference in last_val:
                j = last_val[val - difference]
                dp[i] = dp[j] + 1
            last_val[val] = i
            max_length = max(max_length, dp[i])
        return max_length
```

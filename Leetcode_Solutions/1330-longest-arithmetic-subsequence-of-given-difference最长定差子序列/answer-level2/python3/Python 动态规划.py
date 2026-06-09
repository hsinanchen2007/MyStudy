![image.png](https://pic.leetcode-cn.com/5e32fc64f3e55bf645cc8a59b6f366414d84ee06ca36dd3b7c4caed3ec19ac8f-image.png)


```
'''
动态规划
dp(i) 表示以i位置结尾的等差数列的最长长度
'''

from typing import List
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        pos = {}
        ans = 1
        for i, val in enumerate(arr):
            if val not in pos:
                pos[val] = []
            pos[val].append(i)

        dp = [1 for _ in range(len(arr))]
        for i in range(1, len(arr)):
            prev_val = arr[i] - difference
            if prev_val in pos:
                pos_list = pos[prev_val]

                prev_pos = -1
                l, r = 0, len(pos_list) - 1
                while l <= r:
                    mid = l + (r - l) // 2
                    if pos_list[mid] < i:
                        prev_pos = pos_list[mid]
                        l = mid + 1
                    else:
                        r = mid - 1

                if prev_pos != -1:
                    dp[i] = dp[prev_pos] + 1

        return max(dp)
```

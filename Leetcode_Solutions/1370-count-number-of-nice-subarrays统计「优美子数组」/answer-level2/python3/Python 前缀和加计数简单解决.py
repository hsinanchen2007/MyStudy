![image.png](https://pic.leetcode-cn.com/a79985a07e50790777a9ee964ff25db751599c5eef23f5fe6a9b303e109050ee-image.png)


```
'''
前缀和累加计数数字出现的次数，一遍扫描即可解决
'''

from typing import List

from collections import Counter
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        c = Counter()
        dp = [0 for _ in range(n)]

        ans = 0
        c[0] = 1
        for i in range(0, n):
            if i == 0:
                dp[i] = nums[0] % 2
            else:
                dp[i] = dp[i-1] if nums[i] % 2 == 0 else dp[i-1] + 1

            if dp[i] - k in c:
                ans += c[dp[i] - k]

            c[dp[i]] += 1

        return ans
```

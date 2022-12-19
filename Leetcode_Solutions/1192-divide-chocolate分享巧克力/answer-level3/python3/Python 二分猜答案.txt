

一开始动态规划超时了，时间复杂度N^3, 自己太愚蠢了

```
'''
动态规划
dp(i, j) 表示前i个巧克力分成j份，不管用什么分法，所有可能的和的组合里面，组合里面最小的和的最大值是多少
时间复杂度n^3, 超时了
'''

from typing import List
class Solution:
    def maximizeSweetness(self, sweetness: List[int], K: int) -> int:
        n = len(sweetness)
        dp = [[0 for _ in range(K+2)] for _ in range(n)]
        for i in range(n):
            dp[i][1] = sum(sweetness[:i+1])
            for j in range(2, K+2):
                # 最后一份分sweetness[k:]
                k = i
                total = 0
                while True:
                    if k < j-1:
                        break

                    total += sweetness[k]
                    dp[i][j] = max(dp[i][j], min(total, dp[k-1][j-1]))
                    if total >= dp[k-1][j-1]:
                        break
                    k -= 1
        return dp[n-1][K+1]
```

二分法才是正解

```
from typing import List
import bisect
class Solution:

    def isValid(self, s, val, segments):
        cnt = 0
        i = 0
        while i < len(s):
            target = val if i == 0 else s[i-1] + val
            idx = bisect.bisect_left(s, target, i)
            if idx != len(s):
                cnt += 1
                if cnt >= segments:
                    return True
            i = idx + 1
        return False

    def maximizeSweetness(self, sweetness: List[int], K: int) -> int:
        prefix_sum = [sweetness[i] for i in range(len(sweetness))]
        for i in range(1, len(sweetness)):
            prefix_sum[i] += prefix_sum[i-1]
        l, r = 1, prefix_sum[-1]

        ans = -1
        while l <= r:
            mid = l + (r - l) // 2
            if self.isValid(prefix_sum, mid, K+1):
                l = mid + 1
                ans = mid
            else:
                r = mid - 1
        return ans
```


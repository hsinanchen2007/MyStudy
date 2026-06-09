

```
'''
先求开销的累加和，然后二分搜索累加的起点
'''


class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        dp = [0 for _ in range(len(s))]
        dp[0] = abs(ord(s[0]) - ord(t[0]))
        ans = 1 if dp[0] <= maxCost else 0

        for i in range(1, len(s)):
            dp[i] = dp[i-1] + abs(ord(s[i]) - ord(t[i]))
            if abs(ord(s[i]) - ord(t[i])) > maxCost:
                continue

            target = dp[i] - maxCost
            if target <= 0:
                ans = max(ans, i+1)
                continue

            # 二分找区间起点
            l, r = 0, i-1
            pos = -1
            while l <= r:
                mid = l + (r-l) // 2
                if dp[mid] >= target:
                    pos = mid
                    r = mid - 1
                else:
                    l = mid + 1

            length = 1 if pos == -1 else i - pos
            ans = max(ans, length)

        return ans
```

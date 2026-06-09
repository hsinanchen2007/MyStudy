

```
'''
dp(i, j) 表示序列p[i:]第一次取数上限为j情况下的最高得分

dp(i, j) = max {
    piles[i] + (total[i+1] - dp(i+1, j*2)),
    piles[i] + piles[i+1] + (total[i+2] - dp(i+2, j*2)),
    piles[i] + piles[i+1] + piles[i+2] + (total[i+3] - dp(i+3, j*2)),
    ......
}

'''

from typing import List
class Solution:

    def solve(self, i, j, m, p, total, memo):
        if (i, j) in memo:
            return memo[(i, j)]

        max_pick = min(j, len(p)-i)

        prefix_sum = 0
        ans = 0
        for pick_num in range(1, max_pick+1):
            prefix_sum += p[pick_num + i - 1]
            if i + pick_num == len(p):
                ans = max(ans, prefix_sum)
            else:
                ans = max(ans, prefix_sum + total[i+pick_num] - self.solve(i+pick_num, max(m,pick_num)*2, max(m,pick_num), p, total, memo))
        memo[(i, j)] = ans
        return ans

    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        total = [0 for _ in range(n)]       # 后项累计和
        total[n-1] = piles[n-1]
        for i in range(n-2, -1, -1):
            total[i] = total[i+1] + piles[i]

        return self.solve(0, 2, 1, piles, total, {})
```

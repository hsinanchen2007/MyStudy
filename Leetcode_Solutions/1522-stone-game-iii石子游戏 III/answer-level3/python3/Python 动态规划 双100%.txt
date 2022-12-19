![image.png](https://pic.leetcode-cn.com/3a3b0416d001cb765b037d7f4de1a6ac549133a851fe33764e6266808630e487-image.png)


```
'''
dp[i] 表示处理stoneValue[i:]序列时候先手的人可能拿到的最高得分
'''

from typing import List
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        # 前缀和数组
        prefix_sum = [val for val in stoneValue]
        for i in range(1, n):
            prefix_sum[i] += prefix_sum[i-1]

        dp = [-0x7fffffff for _ in range(n)]
        for i in range(n-1, -1, -1):
            total = 0
            for j in range(i, min(i+3, n)):
                total += stoneValue[j]
                if j+1 == n:
                    dp[i] = max(dp[i], total)
                else:
                    # 后续序列总和减去后手的人在后续序列里面能拿到额最高分就是当前先手的人在后续序列里面能拿到的分数
                    suffix_sum = prefix_sum[-1] - prefix_sum[j]
                    dp[i] = max(dp[i], total + (suffix_sum - dp[j+1]))

        val1, val2 = dp[0], prefix_sum[-1] - dp[0]
        if val1 == val2:
            return 'Tie'
        return 'Alice' if val1 > val2 else 'Bob'

```

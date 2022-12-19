### 解题思路
先求微分，然后就最大连续序列和

### 代码

```python3
import numpy as np
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        r = 0
        dp = list(np.diff(prices))
        s = 0
        maxs = 0
        for i in range(len(dp)):
            s += dp[i]
            if s > maxs:
                maxs = s
            if s < 0:
                s = 0
        return int(maxs)
            

```
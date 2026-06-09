### 解题思路
1、爬楼梯是可以走1步和2步，这里的步数变成了每块硬币的枚举；
2、dp[i]为前面减去dp[i-coin]所有可能值加1
3、注意dp[i-coin]会小于0导致无效值，要限定从0开始；
4、可以用float('inf')设置为无限大；
5、最后可能兑换不出来，所以是-1；

### 代码

```python
import numpy as np


class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        min_coin = np.array(coins).min()
        dp = np.full(shape=amount + 1, fill_value=float('inf'))
        dp[0] = 0
        for i in range(min_coin, amount + 1):
            arr = []
            for coin in coins:
                if i - coin >= 0:
                    arr.append(dp[i - coin])
            dp[i] = np.array(arr).min() + 1
        return int(dp[amount]) if dp[amount] != float('inf') else -1
```
### 解题思路
构建函数 F(x)，其中 x 表示当前的金额数，F(x)表示当前金额数所对应的最少硬币数；
假设最后一枚硬币的面值是 coin[j]，则 F(amount) = min(F[amount-coin[0], ..., F(amount-coin[n])]) + 1
依次往上递推，可得每一个“计算可得”的 F(x) 均为最小值。
因此用两个循环实现：
外循环：面值金额递增直至总额 amount；
内循环：求得当前面值所需的最少硬币数。

### 代码

```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        group = [float('inf')]*(amount+1)
        group[0] = 0

        for x in range(min(coins), amount+1):
            step = []
            for coin in coins:
                if x-coin >= 0:
                    step.append(group[x-coin])
            group[x] = min(step) + 1
        
        return group[amount] if group[amount]!= float('inf') else -1



```
### 解题思路
在保持优秀时间空间复杂度的情况下，与直接累加差值法相比，可以获得买入卖入点；与动态规划法比，更加简单易于理解。

重点在于，“假如从今天来看，已经不再增值了，那么选择抛售”。从数学角度看，这么选择是不会亏的。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        if not prices:
            return 0

        buy = prices[0]
        total = 0
        profit = 0
        for price in prices:
            if price < buy:
                buy = price
            cur_profit = price - buy

            # 假如从今天来看，还在增值则更新profit
            if cur_profit >= profit:
                profit = cur_profit
            # 假如从今天来看，已经不再增值了，那么选择抛售，把赚到的钱计入。且重新定义买入点buy和profit
            else:
                total += profit
                buy = price
                profit = 0

        return total + profit

```
### 解题思路
用贪心策略其实非常简单: 有涨了赚到钱了我就卖出.
要注意及时更新持仓成本价(pre), 股价跌了更新价格, 股价涨了卖出获利后也要更新成本价到卖出价格.

### 代码

```python3
import sys
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        pre = sys.maxsize  # pre是当前持仓的成本价. 默认值设置成哨兵值, 这样子会被新的输入值.
        total = 0
        for i, p in enumerate(prices):
            if p < pre:
                pre = p  # 价格跌了就降低pre的成本价
            if p > pre:
                total = total + p - pre  # 涨了就马上卖出结算收益
                pre = p  # 卖出后把持仓成本价也立刻更新到当前价格.
        return total


```
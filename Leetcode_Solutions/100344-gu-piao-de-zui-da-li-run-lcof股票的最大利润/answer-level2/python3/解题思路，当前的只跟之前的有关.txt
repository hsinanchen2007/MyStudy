### 解题思路
想要利润最大，就要竭尽所能地让左边买入的价格最小，所以用一个变量不断地更新最小的值，再用一个变量不断地检测当前价格和左侧的最小价格之差（利润）是否是当前最大。什么？你担心右边还会有更小的买入价格，没关系那个跟当前的利润没有任何关系，只需要记住当前位置能拥有的最大利润即可，相当于是每次都在迭代得到一个当前天数的最大利润（这就很动态规划了），最后输出即可

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices == []:
            return 0
        min = prices[0]
        max_num = 0
        for i in range(len(prices)):
            if prices[i] < min:
                min = prices[i]
            max_num = max(max_num, prices[i]-min )
        return max_num
```
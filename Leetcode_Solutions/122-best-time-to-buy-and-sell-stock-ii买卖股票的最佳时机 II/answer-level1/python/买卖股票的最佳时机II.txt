### 解题思路
结题思路：贪心算法
在对本问题求解时，不从整体最优考虑，而是考虑当前最优，也就是某种意义上的局部最优解
首先，对于空列表，返回空值
其次，判断当前值和前一时刻值的大小，若当前值>前一时刻值，则卖出，记录当前差值（即利润）。随后，不断与后面元素的相应差值相加，得到最大整体最大利润。
最后，返回该最大利润值。
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        res = 0
        for i in range(1,len(prices)):
            if prices[i] > prices[i-1]:
                res += prices[i]-prices[i-1]
        return res
```
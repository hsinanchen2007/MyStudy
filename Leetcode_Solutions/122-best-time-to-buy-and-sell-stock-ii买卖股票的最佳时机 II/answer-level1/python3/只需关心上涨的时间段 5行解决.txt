### 解题思路
把股票变动的情况看成一段函数，我们要想最大化盈利只需关心上升的部分
![捕获1.PNG](https://pic.leetcode-cn.com/00d39592bcaa1bfe93d77fee255aef3212e4bbfa194ece1281e8b870149e1045-%E6%8D%95%E8%8E%B71.PNG)


### 代码

```python
class Solution:
    # 最简单的解法就是只要上涨就买，开始下跌就抛出股票
    # 即只关心上升的部分
    def maxProfit(self, prices: List[int]) -> int:
        sum_val = 0
        for i in range(1,len(prices)):
            if prices[i] > prices[i-1]:
                sum_val += prices[i] - prices[i-1]
        return sum_val
            
```
### 解题思路
涉及贪心算法，只要今天价格比昨天低，就抛售
### 代码

class Solution:
    def maxProfit(self, prices) -> int:
        n = len(prices)
        if n == 0 or n == 1:
            return 0
        money = 0
        for i in range(1,n):
            if prices[i] > prices[i - 1]:
                money += prices[i] - prices[i - 1]



        return money



```
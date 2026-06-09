```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = []
        left = 0
        right = 0
        for i in range(1, len(prices)):
            if prices[i] < prices[i - 1] :
                if right > left:
                    profit.append(prices[right] - prices[left])
                left = i
            else:
                right = i
        if right == len(prices)-1:
            profit.append(prices[right] - prices[left])
        return(sum(profit))
```
阶梯思路比较简单，只需要考虑所有的上升区间即可。将所有的上升区间最后加在一起，就是最后的最大利润
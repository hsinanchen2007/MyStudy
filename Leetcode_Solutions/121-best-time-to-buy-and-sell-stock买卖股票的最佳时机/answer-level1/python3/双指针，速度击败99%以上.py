### 解题思路
- 定义左右两个指针l和r，初始化利润为0.从头遍历数组，如果prices[l] > prices[r]，直接把l指向r；否则更新利润。此时l指向较小的位置，即买入价格低，卖出价格高。向后移动r，重复以上步骤直到r遍历完数组。
- 时间复杂度O(N)，空间复杂度O(1)。
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = r = 0
        profit = 0
        while r < len(prices):
            if prices[l] > prices[r]:
                l = r
            else:
                profit = max(profit, prices[r] - prices[l])
            r += 1
        return profit
```
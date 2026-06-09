### 解题思路
1, 找到当前节点位置，最小的`low_price`
2, 更新最大的 `price_max` 

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        low_price = prices[0]
        rev_max = 0
        for p in prices[1:]:
            if p <= low_price:
                low_price = p
            else:
                rev_max = max(rev_max, p-low_price)
        return rev_max                
```
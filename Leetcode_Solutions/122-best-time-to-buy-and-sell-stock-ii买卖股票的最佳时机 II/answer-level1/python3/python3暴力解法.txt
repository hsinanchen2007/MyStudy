### 解题思路
模拟游标，寻找最佳卖点

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        x_cursor = 0
        earn = 0
        while x_cursor < len(prices):
            x_val = prices[x_cursor]
            y_cursor = x_cursor + 1
            best_y_val = None
            best_y_cursor = None
            while y_cursor < len(prices):
                # if y_cursor == x_cursor:
                #     break
                y_val = prices[y_cursor]
                if not best_y_val:
                    # 没有发现好的卖点
                    if x_val < y_val:
                        # 发现卖点
                        best_y_val = y_val
                        best_y_cursor = y_cursor
                    else:
                        # 没有卖点，当日不买，换一天
                        break
                else:
                    # 有卖点，再找更好的卖点
                    if best_y_val < y_val:
                        best_y_val = y_val
                        best_y_cursor = y_cursor
                    else:
                        break
                y_cursor = y_cursor + 1
            if best_y_val:
                earn = earn + best_y_val - x_val
                x_cursor = best_y_cursor + 1
                best_y_val = None
            else:
                x_cursor = x_cursor + 1
        return earn
```
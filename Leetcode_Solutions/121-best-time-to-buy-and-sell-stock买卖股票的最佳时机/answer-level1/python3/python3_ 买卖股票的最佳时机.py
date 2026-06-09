```python
def maxProfit(prices):
    # 倒序遍历数组, 获取其最大值
    # 将最大值 - 每个值 = 当前的最大利润
    if not prices:
        return 0
    r, max_price = 0, prices[-1]
    for i in range(len(prices) - 1, -1, -1):
        # 当前更大的值
        if prices[i] > max_price:
            max_price = prices[i]
        else:
            # 最大利润
            r = max(max_price - prices[i], r)
    return r

print(maxProfit([7,1,5,3,6,4]))
print(maxProfit([7,6,4,3,1]))
```
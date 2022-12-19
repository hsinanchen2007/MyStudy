```python
def maxProfit(prices):
    # 考虑[1,2,3], 最大利润 = 3 - 1,
    # 实际上等价于(2 - 1) + (3 - 2)(违背卖出2再买入2的规则), 但这不影响最终的结果
    # 所以, 最大利润 = 每次升序的差值
    r = 0
    for i in range(1, len(prices)):
        v = prices[i] - prices[i - 1]
        r += v if v > 0 else 0
    return r

print(maxProfit([7,1,5,3,6,4]))
print(maxProfit([1,2,3,4,5]))
```
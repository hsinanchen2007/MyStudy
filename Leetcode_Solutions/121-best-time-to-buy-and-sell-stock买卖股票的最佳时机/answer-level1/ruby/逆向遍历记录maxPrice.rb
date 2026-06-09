先上代码：

```javascript []
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var max = 0, maxPrice = prices[prices.length - 1];
    // 逆向遍历一遍，保存第 i 天之后的最大价格 maxPrice
    for(var i = prices.length - 1;  i >= 0; i--){
        if(prices[i] > maxPrice){
            maxPrice = prices[i];
        }
        // 所以 maxPrice - prices[i] 就是第 i 天能取得的最大利润
        // 取所有天数中最大利润最大的那个就是答案
        max = Math.max(max, maxPrice - prices[i]);
    }
    return max;
};
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```

解题思路：

    1.如果我在第 i 天买入股票，那么后面价格最高的那天 maxPrice 时卖出就是最赚的
        
    2.要知道对于第 i 天后面最大价格 maxPrice，逆向遍历一遍数组就行
        比如对于 [7,1,5,3,6,4]:
        第 6 天的 maxPrice = 4，所以第 6 天买卖的利润就是 maxPrice - prices[5] = 0
        第 5 天的 maxPrice = 6，所以第 5 天买卖的利润就是 maxPrice - prices[4] = 0
        第 4 天的 maxPrice = 6，所以第 4 天买卖的利润就是 maxPrice - prices[3] = 3
        第 3 天的 maxPrice = 6，所以第 3 天买卖的利润就是 maxPrice - prices[2] = 1
        第 2 天的 maxPrice = 6，所以第 2 天买卖的利润就是 maxPrice - prices[1] = 5
        第 1 天的 maxPrice = 7，所以第 1 天买卖的利润就是 maxPrice - prices[0] = 0
        所以最终最大利润为 5.
*法一：暴力双循环*

缺点：速度太慢，被吊打

```js
var maxProfit = function(prices) {
    var len = prices.length;
    var result = [];
    for(var i = 0; i < len-1; i++) {
        for(var j = i+1; j < len; j++) {
            if(prices[j] > prices[i]) {
                result.push(prices[j] - prices[i])
            }
        }
    }
    var max = Math.max.apply(null,result);
    if(result.length == 0) {
        return 0
    }
    return max;
};

var prices = [7,1,5,3,6,4];
console.log(maxProfit(prices))
```

*法二：动态规划 【推荐】*

前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}

1.	记录【今天之前买入的最小值】

2.	计算【今天之前最小值买入，今天卖出的获利】，也即【今天卖出的最大获利】

3.	比较【每天的最大获利】，取最大值即可


```js
var maxProfit2 = function(prices) {
    var len = prices.length;
    if (len <= 1) {
        return 0;
    }
    var min = prices[0];
    var max = 0;
    for(var i = 1; i < len; i++) {
        if (prices[i] > prices[i-1]) {
            max = Math.max(max,prices[i] - min);
        } else {
            min = Math.min(min, prices[i])
        }   
    }
    return max;
};
```


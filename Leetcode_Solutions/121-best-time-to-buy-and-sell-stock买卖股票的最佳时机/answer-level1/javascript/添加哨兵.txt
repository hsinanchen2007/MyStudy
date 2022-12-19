### 解题思路
1.有一个最大值和最小值的哨兵，分别指向数组第1个元素
2.这时候差值为0
3.循环开始，当下一个元素比最大值还要大时（此时股价上涨），就更新最大值的哨兵，并计算当前的差值，并且和之前的差值比较求最大值
4.当下一个元素比最小值还要小的时候，更新最小值的哨兵，并且同步重置最大值的哨兵（相当于此时股价下跌）
5.循环完毕返回差值

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var min = prices[0];
    var max = prices[0];
    var difference = 0;
    for(var i =1; i< prices.length; i++) {
        if(prices[i] > max) {
            max = prices[i];
            difference = max - min > difference ? (max - min) : difference;
        } else if(prices[i] < min) {
            min = prices[i];
            max = prices[i];
        }
    }
    return difference;
};
```
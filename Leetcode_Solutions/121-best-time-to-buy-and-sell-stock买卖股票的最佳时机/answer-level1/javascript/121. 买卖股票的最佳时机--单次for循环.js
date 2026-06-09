### 执行结果
![image.png](https://pic.leetcode-cn.com/e5a945bd93ec9475e8418d61bf9b29e1f7fbb7cfa4cb3598aba4f6b5865eb4ef-image.png)

### 解题思路
关键点在于，每次最小值变更之后，可以继续往后遍历，求最大差值。
因为前面的最小值的最大差值已经被记录了，只要跟后面的最小值的最大差值进行比较，保留最大差值就行了。

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let len = prices.length;
    if (!len) return 0
    let diff = 0
    let min = prices[0]

    for (let i = 1; i < len; i ++) {
        if (prices[i] < min) {
            min = prices[i]
            continue
        }
        diff = Math.max( diff, (prices[i] - min))
    }

    return diff
};
```
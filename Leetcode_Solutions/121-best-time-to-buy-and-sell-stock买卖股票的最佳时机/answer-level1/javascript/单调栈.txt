### 解题思路
维护一个递增的单调栈，每次栈顶元素大于当前元素时，出栈并更新结果。

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const stack = [];
    let res = 0;
    for (let i = 0; i < prices.length; ++i) {
        while (stack[stack.length-1] > prices[i]) {
            const current = stack.pop();
            if (stack.length) {
                res = Math.max(current - stack[0], res);
            }
        }
        stack.push(prices[i]);
    }
    if (stack.length) {
        res = Math.max(stack[stack.length-1]-stack[0], res);
    }
    return res;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)
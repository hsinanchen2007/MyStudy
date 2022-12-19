### 解题思路

大家好，我是 17

每 X 分钟如果老板生气不满意的客人记下来，找出最大值，这就是老板如果不生气的最大收益

### 代码

```javascript
/**
 * @param {number[]} customers
 * @param {number[]} grumpy
 * @param {number} X
 * @return {number}
 */
var maxSatisfied = function (customers, grumpy, X) {
  let len = customers.length
  let total = 0
  let max = 0
  let cur = 0
  for (let i = 0; i < len; i++) {
    total += customers[i] * (grumpy[i] === 1 ? 0 : 1)
    if (i < X) cur += customers[i] * grumpy[i]
    else {
     
      max = Math.max(cur, max)
      cur += customers[i] * grumpy[i]
      cur -= customers[i - X] * grumpy[i-X]
    }
  }
  max = Math.max(cur, max)
  return total + max
};
```
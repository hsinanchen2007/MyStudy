### 解题思路
i 记录步骤次数，偶数/2，奇数自减，while循环直至为0

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function (num) {
  let i = 0;
  if (num === 0) return i;
  while (num > 0) {
    num % 2 === 0 ? (num /= 2) : (num--);
    i++
  }
  return i
};
```
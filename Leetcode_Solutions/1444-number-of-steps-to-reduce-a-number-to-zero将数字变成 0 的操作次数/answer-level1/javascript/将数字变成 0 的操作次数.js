### 解题思路
循环叠加

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
    let i = 0
    while (num !== 0) num % 2 === 0 ? num /= 2 : num--, i++
    return i
};
```
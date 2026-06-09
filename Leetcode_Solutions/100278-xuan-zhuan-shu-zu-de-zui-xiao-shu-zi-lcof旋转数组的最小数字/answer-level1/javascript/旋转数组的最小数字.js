### 解题思路

找出数组中的最小值。

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function(numbers) {
    return Math.min(...numbers);
};
```
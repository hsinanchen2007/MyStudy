### 解题思路
递归

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var sumNums = function(n) {
    return n > 0 ? n + sumNums(n - 1) : 0
};
```
### 解题思路

### 代码

```javascript
/**
 * @param {number} N
 * @return {number}
 */
var bitwiseComplement = function(N) {
    return parseInt(N.toString(2).split('').map(num => num ^ 1).join(''), 2)
};
```
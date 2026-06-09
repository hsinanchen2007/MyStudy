### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if (n == 0) return false;
    while( n % 2 === 0) {
        n=n/2;
    }
    return (n === 1);
};
```
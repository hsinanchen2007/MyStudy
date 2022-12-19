### 解题思路
除2，递归，但是我干什么了内存消耗那么多？？？？？

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if(!n) return false
    if(n == 1 || n == 2) return true
    if(n % 2 !== 0) return false

    return isPowerOfTwo(n/2) 
};
```
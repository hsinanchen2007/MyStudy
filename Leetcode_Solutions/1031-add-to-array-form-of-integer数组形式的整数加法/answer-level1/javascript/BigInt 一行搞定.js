### 解题思路
BigInt

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number[]}
 */
var addToArrayForm = function(A, K) {
    return (BigInt(A.join(''))+BigInt(K+'')+'').split('')
};
```
padStart(32, 0)
```js
/** 常规解法
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    return parseInt(n.toString(2).padStart(32, 0).split('').reverse().join(''), 2);
};

/** 位运算
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    let res = 0;
    for(let i = 0; i < 32; i++) {
        res = res << 1 + n & 1;
        n = n >> 1;
    }
    return res;
};
```

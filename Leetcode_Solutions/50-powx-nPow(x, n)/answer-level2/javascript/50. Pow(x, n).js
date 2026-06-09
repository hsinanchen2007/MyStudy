### 解题思路
n = 2*x + rest 通过>>>=1控制x，通过 n & 1 累加 x，求得n
这道题 n >> 1过不了，显示超时，但是 n >>>=1 通过了，是什么原因
### 代码

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if( n < 0) {
        x = 1 / x
        n = -n
    }
    let pow = 1
    while(n) {
        if (n & 1) pow *=x
        x *= x
        n >>>= 1
    }
    return pow
};
```
击败100%
```js
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var rangeBitwiseAnd = function(m, n) {
    let res = m;
    if(n >> 1 > m) return 0;
    for(let i = m; i <= n; i++) {
        if(!res) return 0;
        res &= i;
    }
    return res;
};
```

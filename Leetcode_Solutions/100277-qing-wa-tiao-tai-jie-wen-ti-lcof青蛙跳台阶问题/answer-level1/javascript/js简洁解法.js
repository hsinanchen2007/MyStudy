```javascript []
/**
 * @param {number} n
 * @return {number}
 */
var numWays = function(n) {
    let [a, b] = [1n, 1n];
    for(let i = 2n; i <= n; i++) {
        [a, b] = [b, a + b];
    }

    return b % 1000000007n;
};
```

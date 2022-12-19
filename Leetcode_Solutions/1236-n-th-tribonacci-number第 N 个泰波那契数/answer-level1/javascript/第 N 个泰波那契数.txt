```js
var tribonacci = function(n) {
    let res = [0,1,1]
    for (let i = 3; i <= n; i++) {
        res[i] = res[i-1] + res[i-2] + res[i-3]
    }
    return res[n]
};
```

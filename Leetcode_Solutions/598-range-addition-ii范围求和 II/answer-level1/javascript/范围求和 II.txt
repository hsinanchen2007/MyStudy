```js
var maxCount = function(m, n, ops) {
    for (let i = 0; i < ops.length; i++) {
        m = Math.min(m, ops[i][0])
        n = Math.min(n, ops[i][1])
    }
    return m * n
};
```
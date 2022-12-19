```
var merge = function(A, m, B, n) {
    A.splice(m, n, ...B)
    A.sort((a, b) => a -b)
};
```

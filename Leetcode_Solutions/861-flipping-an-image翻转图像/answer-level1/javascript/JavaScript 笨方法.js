```javascript []
var flipAndInvertImage = function(A) {
    for (i = 0; i < A.length; i++) {
        A[i] = A[i].reverse();
        for (j = 0; j < A.length; j++) {
            A[i][j] = A[i][j]^1;
        }
    }
    return A;
```
翻转用异或^或者三目运算符都可以，但位运算的性能更优。


```
var transpose = function (A) {
    let row = A.length,
        col = A[0].length
    let res = Array.from({ length: col }, () => [])
    for (let i = 0; i < row; ++i) {
        for (let j = 0; j < col; ++j) {
            res[j][i] = A[i][j]
        }
    }
    return res
};
```

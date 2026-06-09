```
var isToeplitzMatrix = function (matrix) {
    if (matrix.length < 2 || matrix[0].length === 1) return true
    let len = matrix[0].length - 1
    let max = len * (matrix.length - 1)

    for (let i = 0; i < matrix.length - 1; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] === matrix[i + 1][j + 1]) {
                max--
            }
        }
    }
    return max === 0 ? true : false
};
```

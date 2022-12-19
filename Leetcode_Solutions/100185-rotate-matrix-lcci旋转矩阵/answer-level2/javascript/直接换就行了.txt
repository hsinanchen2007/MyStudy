
```
var rotate = function(matrix) {
    var n = matrix.length;
    for (let i = 0; i < n / 2; i++) {
        for (let j = i; j < n - 1 - i; j++) {
            [matrix[n-1-j][i],matrix[i][j]]=[matrix[i][j], matrix[n-1-j][i]];
            [matrix[n-1-i][n-1-j],matrix[n-1-j][i]]=[matrix[n-1-j][i], matrix[n-1-i][n-1-j]];
            [matrix[j][n-1-i],matrix[n - 1 - i][n - 1 - j]]=[matrix[n - 1 - i][n - 1 - j], matrix[j][n-1-i]];
        }
    }
    return matrix;
};
```


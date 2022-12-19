先来欣赏一下空间O(n^2)的粗暴解法
```js
var rotate = function(matrix) {
    const cloneMartix = JSON.parse(JSON.stringify(matrix));

    const n = matrix.length;

    for (let x = 0; x < n; x++) {
        for (let y = 0; y < n; y++) {
            matrix[x][y] = cloneMartix[n - y - 1][x];
        }
    }
};
```

先转置, 后逐行翻转🙃
```js
var rotate = function(matrix) {
    for (let x = 0; x < matrix.length; x++) {
        for (let y = x; y < matrix.length; y++) {
            if (x === y) continue;

            // swap without third party
            matrix[x][y] = matrix[x][y] ^ matrix[y][x];
            matrix[y][x] = matrix[x][y] ^ matrix[y][x];
            matrix[x][y] = matrix[x][y] ^ matrix[y][x];
        }
    }

    for (let x = 0; x < matrix.length; x++) {
        matrix[x].reverse();
    }
};
```
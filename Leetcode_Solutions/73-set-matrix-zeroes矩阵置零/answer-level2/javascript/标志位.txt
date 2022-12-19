### 解题思路
先将对应行和列的部分改为一个标识（如果本来是 0 则不改），
再将所有标志位改为 0。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
const setString = (matrix, x, y) => {
    for (let i = 0; i < matrix[0].length; ++i) {
        matrix[x][i] = (matrix[x][i] === 0 ? 0 : 's');
    }
    for (let j = 0; j < matrix.length; ++j) {
        matrix[j][y] = (matrix[j][y] === 0 ? 0 : 's');
    }
}

const setZero = (matrix) => {
    for (let i = 0; i < matrix.length; ++i) {
        for (let j = 0; j < matrix[0].length; ++j) {
            if (matrix[i][j] === 's') {
                matrix[i][j] = 0;
            }
        }
    }
}

var setZeroes = function(matrix) {
    const m = matrix.length;
    if (!m) return;
    const n = matrix[0].length;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (matrix[i][j] === 0) {
                setString(matrix, i, j);
            }
        }
    }
    setZero(matrix);
};
```

### 复杂度
- 时间复杂度 O(MN*(M+N))
- 空间复杂度 O(1)
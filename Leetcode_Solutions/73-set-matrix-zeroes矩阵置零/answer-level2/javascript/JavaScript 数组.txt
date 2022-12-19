### 解题思路
使用一个数组保存matrix中所有0的坐标
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
 var setZeroes = function(matrix) {
    const m = matrix.length
    const n = matrix[0].length
    const temp = []
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 0) {
                temp.push([i, j])
            }
        }
    }
    const len = temp.length
    for (let i = 0; i < len; i++) {
        const x = temp[i][0]
        const y = temp[i][1]
        matrix[x].fill(0)
        for (let j = 0; j < m; j++) {
            matrix[j][y] = 0
        }
    }
};
```
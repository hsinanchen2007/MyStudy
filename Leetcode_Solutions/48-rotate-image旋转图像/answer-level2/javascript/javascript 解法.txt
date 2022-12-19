### 解题思路
旋转后位置为matrix[i][j]的元素，旋转前对应的位置为matrix[n - 1 - j][i]

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const n = matrix.length
    if (n > 1) {
        for (let i = 0; i < n; i++) {
            const temp = []
            for (let j = 0; j < n; j++) {
                temp.push(matrix[n - 1 - j][i])
            }
            matrix.push(temp)
        }
        matrix.splice(0, n)
    }
};
```
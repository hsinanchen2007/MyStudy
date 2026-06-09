> 思路: 对比每行的最后一个大小,如果大于该目标值,那么向前进行查找

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let m = matrix.length,
        n = (matrix[0] || []).length;
    for (let i = 0; i < m; i++) {
        if (matrix[i][n - 1] >= target) {
            for (let j = n - 1; j >= 0; j--) {
                if (matrix[i][j] === target) return true;
                else if (matrix[i][j] < target) return false;
            }
        }
    }
    return false;
};
```
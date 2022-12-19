### 解题思路


### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    const m = matrix.length
    if (m === 0 || target == null) {
        return false
    }
    const n = matrix[0].length
    const temp = []
    for (let i = 0; i < m; i++) {
        temp.push([matrix[i][0], matrix[i][n - 1]])
    }
    for (let i = 0; i < m; i++) {
        if (temp[i][0] <= target && temp[i][1] >= target) {
            for (let j = 0; j < n; j++) {
                if (matrix[i][j] === target) {
                    return true
                }
            }
        }
    }
    return false
};
```
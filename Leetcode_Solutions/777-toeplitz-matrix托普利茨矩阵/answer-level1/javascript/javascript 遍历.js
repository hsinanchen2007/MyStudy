### 解题思路


### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) {
    const m = matrix.length
    const n = matrix[0].length
    // 从第一行遍历对角线
    for (let i = 0; i < n; i++) {
        const val = matrix[0][i]
        let j = 1
        let k = i + 1
        let flag = true
        while (j < m && k < n) {
            if (val !== matrix[j][k]) {
                return false
            }
            j++
            k++
        }
    }
    // 从第二列遍历对角线
    for (let i = 1; i < m; i++) {
        const val = matrix[i][0]
        let j = 1
        let k = i + 1
        let flag = true
        while (j < n && k < m) {
            if (val !== matrix[k][j]) {
                return false
            }
            j++
            k++
        }
    }
    return true
};    
```
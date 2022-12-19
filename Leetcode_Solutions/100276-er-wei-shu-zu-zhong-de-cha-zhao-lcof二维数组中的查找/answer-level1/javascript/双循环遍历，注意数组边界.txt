### 解题思路
双循环遍历，注意数组边界

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    if (matrix && matrix.length) {
        for (let index = 0; index < matrix.length; index++) {
            const colData = matrix[index];
            if (colData.length > 0) {
                for (let iv = 0; iv < colData.length; iv++) {
                    const rowData = colData[iv];
                    if (rowData === target) {
                        return true;
                    }
                }
            }
            
        }
    }
    return false;
};
```
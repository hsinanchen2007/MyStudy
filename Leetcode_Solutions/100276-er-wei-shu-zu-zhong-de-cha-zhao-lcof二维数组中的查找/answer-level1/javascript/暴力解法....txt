### 解题思路
遍历一遍。。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    let x = 0
    let y = 0
    while (x < matrix.length && y < matrix[0].length) {
        let cur = matrix[x][y]

        if (cur === target) {
            return true
        }
        if (y === 0 && cur > target) {
            return false
        }
        if (cur > target || y === matrix[0].length - 1) {
            x++
            y = 0
        } else {
            y++
        }
        
    }
    return false
};
```
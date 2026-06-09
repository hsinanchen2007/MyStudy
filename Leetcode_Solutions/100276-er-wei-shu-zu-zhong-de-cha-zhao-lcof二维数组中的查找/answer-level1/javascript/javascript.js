### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    let m = matrix.length
    if (m == 0) return false
    let n = matrix[0].length

    let x = n - 1 // 横坐标
    let y = 0 // 纵坐标

    while (x >= 0 && y < m) {
        let cur = matrix[y][x]
        if (cur ===  target) return true
        if (cur > target) {
            x--
        } else {
            y++
        }
    }

    return false
};
```
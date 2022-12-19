### 解题思路
时间复杂度O（m + n）

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix = [], target) {
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
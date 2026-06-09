### 解题思路
减去右侧与下方贴合的面积*2

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function (grid) {
    let n = grid.length
    let result = 0
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let val = grid[i][j]
            if (val > 0) {
                result += (2 + val * 4)
            }
            let bottom = 0
            let right = 0
            try { bottom = grid[i + 1][j] } catch (e) { }
            try { right = grid[i][j + 1] } catch (e) { }
            if (bottom > 0){
                result -= 2 * Math.min(bottom, val)
            }
            if (right > 0){
                result -= 2 * Math.min(right, val)
            }
        }
    }
    return result
};
```
### 解题思路
取右上角数作为起点

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
/** 
 * [[4,3,2,-1],
 *  [3,2,1,-1],
 *  [1,1,-1,-2],
 *  [-1,-1,-2,-3]]
 */
var countNegatives = function(grid) {
    let m = grid.length
    let n = grid[0].length
    let i = 0
    let j = n - 1
    let res = 0
    while(j >= 0 && i < m){
        let cur = grid[i][j]
        if (cur < 0) {
            res = res + m - i
            j--
        } else {
            i++
        }
    }
    return res
};
```
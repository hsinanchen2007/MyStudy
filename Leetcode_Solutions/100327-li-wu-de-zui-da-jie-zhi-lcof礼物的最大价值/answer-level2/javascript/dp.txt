### 解题思路
每一行 每一列那样获得dp

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxValue = function(grid) {
    let i = 0
    let j = 0
    let dp = Array(grid.length).fill(0).map(ele => {
        return Array(grid[0].length).fill(0)
    })
    while (i <= grid.length - 1 && j <= grid[0].length - 1) {
        let m = i
        let n = j
        while(m <= grid.length - 1) {
            let top = m > 0 ? dp[m - 1][n] : 0
            let left = n > 0 ? dp[m][n - 1] : 0
            dp[m][n] = Math.max(dp[m][n], top + grid[m][n], left + grid[m][n])
            m++
        }
        m = i
        while(n <= grid[0].length - 1) {
            let top = m > 0 ? dp[m - 1][n] : 0
            let left = n > 0 ? dp[m][n - 1] : 0
            dp[m][n] = Math.max(dp[m][n], top + grid[m][n], left + grid[m][n])
            n++
        }
        i++
        j++
    }
    // console.log(dp)
    return dp[grid.length - 1][grid[0].length - 1]
};
```
### 解题思路
 1. 找状态
 *   到达sum(m-1,n-1)最小，则上一步是最小 min( minSum(m-2,n-1), minSum(m-1,n-2)), 得到 minSum(m-1,n-1) = min( minSum(m-2,n-1),  `       minSum(m-1,n-2)) + 1
 *   要是当前最小 则满足两个条件，
 *      1. 可以到达  则(m-2,n-1) OR (m-1,n-2)
 *      2. 上一步最小 minSum(m-1,n-1) = min( minSum(m-2,n-1)
2. 转移方程
 *      minSum(m-1,n-1) = min( minSum(m-2,n-1), minSum(m-1,n-2)) + 1
3. 初始值，边界
 *      minSum(0, 0) = grid[0][0]
 *      minSum(i, 0) = Σ0-i  grid[j][0]
 *      minSum(0, i) = Σ0-j  grid[0][j]
4. 计算顺序
 *      从小到大
 */

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
/**
 * 1. 找状态
 *   到达sum(m-1,n-1)最小，则上一步是最小 min( minSum(m-2,n-1), minSum(m-1,n-2)), 得到 minSum(m-1,n-1) = min( minSum(m-2,n-1), minSum(m-1,n-2)) + 1
 *   要是当前最小 则满足两个条件，
 *      1. 可以到达  则(m-2,n-1) OR (m-1,n-2)
 *      2. 上一步最小 minSum(m-1,n-1) = min( minSum(m-2,n-1)
 * 2. 转移方程
 *      minSum(m-1,n-1) = min( minSum(m-2,n-1), minSum(m-1,n-2)) + 1
 * 3.初始值，边界
 *      minSum(0, 0) = grid[0][0]
 *      minSum(i, 0) = Σ0-i  grid[j][0]
 *      minSum(0, i) = Σ0-j  grid[0][j]
 * 4计算顺序
 *      从小到大
 */
var minPathSum = function(grid) {
    if(grid.length == 0){
        return 0;
    }
    let minSum = [];
    let m = grid.length;
    let n = grid[0].length;
    for(let i = 0; i<grid.length; i++){
        minSum[i] = [];
    }
    minSum[0][0] = grid[0][0];
    for(let i = 0; i < m; i++){
        for(let j = 0;j < n; j++){
            if(i==0 && j==0){
                minSum[i][j] =  grid[i][j]
                continue;
            } 
            if(i == 0 && j!=0){
                minSum[i][j] = minSum[i][j-1] + grid[i][j]
                continue;
            }
            if(j == 0 && i!=0){
                minSum[i][j] = minSum[i-1][j] + grid[i][j]
                continue;
            }
            minSum[i][j] = Math.min(minSum[i-1][j], minSum[i][j-1]) + grid[i][j];
        }
    }
    return minSum[m-1][n-1];
};




```
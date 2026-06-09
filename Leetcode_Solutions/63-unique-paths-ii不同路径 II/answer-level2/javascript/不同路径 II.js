### 解题思路
这题的dp table 我们可以直接使用obstacleGrid,我们需要单独考虑第一行，第一列的情况，我们用obstacleGrid[i][j] 记录到达该点的路径数。
1. 如果obstacleGrid[0][0] = 1,则返回0，否则初始化obstacleGrid[0][0] = 1
2. obstacleGrid[0][j] =obstacleGrid[0][j-1] 和obstacleGrid[i][0] = obstacleGrid[i-1][0] 
3. obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j]
这样最后我们返回最后一个元素的值就是路径数了obstacleGrid[rowLen - 1][columnLen - 1]

### 代码

```javascript
var uniquePathsWithObstacles = function (obstacleGrid) {
    var rowLen = obstacleGrid.length
    var columnLen = obstacleGrid[0].length
    for (var i = 0; i < rowLen; i++) {
        for (var j = 0; j < columnLen; j++) {
            if (obstacleGrid[i][j] === 1) {
                obstacleGrid[i][j] = 0
            } else if (i === 0 && j === 0) {
                obstacleGrid[i][j] = 1
            } else if (i === 0) {
                obstacleGrid[i][j] = obstacleGrid[i][j - 1]
            } else if (j === 0) {
                obstacleGrid[i][j] = obstacleGrid[i - 1][j]
            } else {
                obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j]
            }
        }
    }
    return obstacleGrid[rowLen - 1][columnLen - 1]
};
```
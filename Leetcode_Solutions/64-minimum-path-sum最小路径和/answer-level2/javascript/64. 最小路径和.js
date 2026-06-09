#### 解法：动态规划
+ 思路
  + 状态定义：
    + 设dp[i][j]为走到当前位置的最小路径和
  + 递推公式：
    + 只能向下或向右走，意味着当前格子只能由上边或者左边走过来
    + **dp[i][j] = Min(dp[i-1][j],dp[i][j-1]) + grid[i][j]**
  + 初始化
    + 第一行第n列和第一列第n行为均原数组值
  + 边界条件
    + 格子有边界，因此当i==0 或j==0时，i-1和j-1会越界
      + **i = 0，j != 0时,dp[i][j] = dp[i][j-1]+grid[i][j]**
      + **i !=0，j == 0时,dp[i][j] = dp[i-1][j]+grid[i][j]**
      + **i !=0 && j != 0时,dp[i][j] = Min(dp[i-1][j],dp[i][j-1])+grid[i][j]**
      + **i == 0 && j == 0时,dp[i][j]=grid[i][j]**
  + 返回值
    + dp最后一个元素值
```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    var n = grid.length;
    var m = grid[0].length;
    var dp = Array.from(new Array(n),() => new Array(m));
    for(var i = 0;i < n;i++){
        for(var j = 0;j < m;j++){
            if( i != 0 && j!= 0){
                dp[i][j] = Math.min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }else if(i == 0 && j!=0){
                dp[i][j] = dp[i][j-1]+grid[i][j];
            }else if(i != 0 && j==0){
                dp[i][j] = dp[i-1][j]+grid[i][j];
            }else if(i == 0 && j==0){
                dp[i][j] = grid[i][j];
            }
        }
    }
    return dp[n-1][m-1];
};
```
+ 空间复杂度优化版+1
  + 降维处理
```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    var dp = new Array(grid.length);
    for(var i = 0;i < grid.length;i++){
        for(var j = 0;j < grid[0].length;j++){
            if( i != 0 && j!= 0){
                dp[j] = Math.min(dp[j-1],dp[j])+grid[i][j];
            }else if(i == 0 && j!=0){
                dp[j] = dp[j-1]+grid[i][j];
            }else if(i != 0 && j==0){
                dp[j] = dp[j]+grid[i][j];
            }else if(i == 0 && j==0){
                dp[j] = grid[i][j];
            }
        }
    }
    return dp[grid[0].length-1];
};
```
+ 空间复杂度优化版+2
  + 时间复杂度：O(M*N)
  + 空间复杂度：O(1)
  + 直接修改原数组即可
  ```javascript
  /**
   * @param {number[][]} grid
   * @return {number}
   */
  var minPathSum = function(grid) {
      for(var i = 0;i < grid.length;i++){
          for(var j = 0;j < grid[0].length;j++){
              if( i != 0 && j!= 0){
                  grid[i][j] = Math.min(grid[i-1][j],grid[i][j-1])+grid[i][j];
              }else if(i == 0 && j!=0){
                  grid[i][j] = grid[i][j-1]+grid[i][j];
              }else if(i != 0 && j==0){
                  grid[i][j] = grid[i-1][j]+grid[i][j];
              }else if(i == 0 && j==0){
                  continue;
              }
          }
      }
      return grid[grid.length-1][grid[0].length-1];
  };
  ```
# 解法三
![截屏2019-11-13上午5.59.18.png](https://pic.leetcode-cn.com/3af1438f4fc1f8b75e3d9ec4678e2f48644f1cc85c06fd8d3634bee72bb2b077-%E6%88%AA%E5%B1%8F2019-11-13%E4%B8%8A%E5%8D%885.59.18.png)
#### 解法一：动态规划
+ [与62. 不同路径-解法一一样](https://leetcode-cn.com/problems/unique-paths/solution/62-bu-tong-lu-jing-by-alexer-660/)
+ 区别就是此题设置了障碍物而已
  + 既然是障碍物，说明此路不通，即经过此节点的路径数为0，所以当遇到障碍物时，设置dp[i][r] = 0即可
  + 那么第一行第一列数据初始化的时候就不能都是1了，因为有的地方有障碍物存在
  + 初始化dp二维数组的时候各个节点都不可达
    + 这样dp递推的时候，只需要在62题的基础上加上obstacleGrid[i][r]当前节点不为障碍物的条件即可
    + 而有障碍物的地方为0，加0也就等于没走
```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    // 行
    var n = obstacleGrid.length;
    // 列
    var m = obstacleGrid[0].length;
    // 初始化
    var dp = new Array(n);
    for(var i = 0;i<n;i++){
        dp[i] = new Array(m).fill(0);
    }
    dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    // 如果起点就是障碍物
    if(dp[0][0] == 0){
        return 0 ;
    }
    // 第一行
    for(var j = 1;j < m;j++){
        if(obstacleGrid[0][j] != 1){
            dp[0][j] = dp[0][j-1];
        }
    }
    // 第一列
    for(var r = 1;r < n;r++){
        if(obstacleGrid[r][0] != 1){
            dp[r][0] = dp[r-1][0];
        }
    }
    // 动态递推
    for(var i = 1;i < n;i++){
        for(var r = 1;r < m;r++){
            if(obstacleGrid[i][r] != 1){
                dp[i][r] = dp[i-1][r] +dp[i][r-1];
            }
        }
    }
    return dp[n-1][m-1];
};
```
#### 解法二：递归
+ 超时
```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    var n = obstacleGrid.length;
    var m = obstacleGrid[0].length;
    if(!obstacleGrid || obstacleGrid[0][0] == 1){
        return 0;
    }
    function helper(i,j){
        var tmp = 0;
        if( i == n-1 && j == m-1 && obstacleGrid[i][j] != 1){
            return 1;
        }
        if( i >= n || j >= m || obstacleGrid[i][j] == 1){
            return 0;
        }
        tmp += helper(i+1,j);
        tmp += helper(i,j+1);
        return tmp;
    }
    return helper(0,0);
};
```
#### 解法三：动态规划-压缩降维
+ [与62. 不同路径-解法一的优化版2一样](https://leetcode-cn.com/problems/unique-paths/solution/62-bu-tong-lu-jing-by-alexer-660/)可减少空间复杂度
```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    var n = obstacleGrid.length;
    var m = obstacleGrid[0].length;
    var result = Array(m).fill(0);
    for(var i = 0;i < n;i++){
        for(var j = 0;j < m;j++){
            if(i == 0 && j == 0){
                result[j] = 1;
            }
            if(obstacleGrid[i][j] == 1){
                result[j] = 0;
            }else if(j > 0){
                result[j] += result[j-1];
            }
        }
    }
    return result[m-1];
};
```
+ 优化+1
  + 初始化第一步可达，为1
  + for双循环内就可以少一层判断
```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    var n = obstacleGrid.length;
    var m = obstacleGrid[0].length;
    var result = Array(m).fill(0);
    result[0] = 1;
    for(var i = 0;i < n;i++){
        for(var j = 0;j < m;j++){
            if(obstacleGrid[i][j] == 1){
                result[j] = 0;
            }else if(j > 0){
                result[j] += result[j-1];
            }
        }
    }
    return result[m-1];
};
```
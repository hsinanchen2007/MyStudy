### 解题思路
如果没有做过不同路径的初阶版本，先去做一下。

延续I的思路， 这里不同的就是，如果 arr[i][j] == 1, 也就是有石头了，直接dp[i][j] = 0.
我这里没路，你还是从别处走吧。
```
    if(obstacleGrid[i][j] == 1){
            dp[i][j] = 0;
            continue;
    }
```
也就是说，他的下面的那一块，只能从右边那条路到达，他的右边的那一块，只能从上面那条路到达。
![dp.png](https://pic.leetcode-cn.com/e8909aa4840d34f7e08d51f3e68e5aa32eaae015c5d8568d141746cf555e1948-dp.png)


### 代码

```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    let dp = [];
    let xlen = obstacleGrid.length;
    if(xlen == 0){
        return 0;
    }
    let ylen = obstacleGrid[0].length;
    if(ylen == 0){
        return 1;
    }
    for(let i = 0; i < xlen; i++){
        dp[i] = [];
    }
    dp[0][0] = 1;
    for(let i = 0; i < xlen; i++){
        for(let j = 0; j < ylen; j++){
            if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
            }
            if(i == 0 || j == 0){
                if(i ==0 && j == 0){
                    continue;
                }
                if(i == 0){
                    dp[i][j] = dp[0][j-1];
                }else{
                    dp[i][j] = dp[i-1][0];
                }
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[xlen-1][ylen-1];
};
```

但不知为什么，没有JavaScript高票的题解性能那么好（虽然相差不多）

```javascript []
var uniquePathsWithObstacles = function(obstacleGrid) {
    var dp=[];
    var width=obstacleGrid[0].length;
    var height=obstacleGrid.length;
    var filler=1;//用于保存第一行或第一列的初始值

    for(var j=0; j<width; j++){//初始化第一行值
        if(obstacleGrid[0][j]===1){
            filler=0;
        }
        dp[j]=filler;
    }

    filler=1;//重置初始值为1, 用于初始化第一列的值

    for(var i=1; i<height; i++){
        for(var j=0; j<width; j++){
            if(j===0){//
                if(dp[j]===0 || obstacleGrid[i][j]===1){
                    filler=0;
                }
                dp[j]=filler;//若上方有阻塞时，模块填充0；
            }
            else if(obstacleGrid[i][j]===1){//模块本身有障碍时，填充0
                dp[j]=0;
            }else {
                dp[j]=dp[j]+dp[j-1];
            }
        }
    }
    return dp[width-1];
};
```

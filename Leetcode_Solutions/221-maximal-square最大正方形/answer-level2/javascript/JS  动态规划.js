### 解题思路
1. 找状态
       要想使 一个点为正方形的最右边下角，那么他的上面一点，左边一点，斜上方一点，也应该是一个正方形的右下角。
```
         if dp[i][j] == 1
          dp[i][j] = Math.min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1 
```
2. 转移方程
```
          if dp[i][j] == 1
                  dp[i][j] = Math.min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + parseInt(dp[i][j]) + 1
          else
                  dp[i][j] = 0     
```
3. 初始条件和边界值  
```
      max = 0;
      dp[0][0] = maxrix[0][0]
      dp[0][j] = maxrix[0][j]
      dp[i][0] = maxrix[i][0]
```
 4. 顺序 从小到大

### 代码

```javascript

var maximalSquare = function(matrix) {
    let dp = [];
    let len = matrix.length;
    if(len == 0){
        return 0;
    }
    let len2 = matrix[0].length;
    let i,j;
    let max = 0;
    for(i = 0 ; i<len; i++){
        dp[i] = [];
    }
    dp[0][0] = parseInt(matrix[0][0]);
    max = Math.max(max, dp[0][0]);
    for(i = 0; i < len; i++){
        for(j = 0; j < len2; j++){
            if(i == 0 || j == 0){
                dp[i][j] = parseInt(matrix[i][j])
                max = Math.max(max, dp[i][j])
                continue;
            }
            if(matrix[i][j] == '1'){
                dp[i][j] = Math.min(Math.min(dp[i-1][j-1],dp[i-1][j]), dp[i][j-1]) + 1
                max = Math.max(max,dp[i][j])
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return max * max;
 };
```
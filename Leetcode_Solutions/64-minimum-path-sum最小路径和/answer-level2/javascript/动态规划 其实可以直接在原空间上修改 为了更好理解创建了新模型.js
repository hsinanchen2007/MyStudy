//最小路径和
//动态规划

var minPathSum = function(grid) {
    //1.建立模型 这里不需要更多辅助空间了 和题目模型一样大就行
    var dp = new Array(grid.length)
    for(var i=0;i<dp.length;i++){
        dp[i]=new Array(grid[0].length)
    }

    //2.求已知部分
    dp[0][0] = grid[0][0]
    for(var i=1;i<dp.length;i++){
        dp[i][0] = dp[i-1][0]+grid[i][0]
    }

    for(var i=1;i<dp[0].length;i++){
        dp[0][i] = dp[0][i-1]+grid[0][i]
    }
    //3.推导未知
    for(var i=1;i<dp.length;i++){
        for(var j=1;j<dp[0].length;j++){
            if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j]=dp[i][j-1]+grid[i][j]
            } else{
                dp[i][j]=dp[i-1][j]+grid[i][j]
            }
        }
    }

    return dp[dp.length-1][dp[0].length-1]
    
};
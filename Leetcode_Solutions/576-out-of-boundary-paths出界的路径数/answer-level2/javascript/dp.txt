
```
//dp[step][x][y]表示在（x，y）坐标处，在step步数内可以到达边界的路径数目
//状态转移：dp[step][x][y]=dp[step-1][x-1][y]+dp[step-1][x+1][y]+dp[step-1][x][y-1]+dp[step-1][x][y+1]；
var findPaths = function(m, n, N, i, j) {
    var dp=[[[]]];
    for(var step=0;step<=N;step++){
        dp[step]=[];
        for(var x=0;x<m;x++){
            dp[step][x]=[]
            for(var y=0;y<n;y++){
                dp[step][x][y]=0;
                if(step!==0){
                    if(x===0){
                        dp[step][x][y]+=1;
                    }
                    if(y===0){
                        dp[step][x][y]+=1;
                    }
                    if(x===m-1){
                        dp[step][x][y]+=1;
                    }
                    if(y===n-1){
                        dp[step][x][y]+=1;
                    }
                    if(x-1>=0){
                        dp[step][x][y]+=dp[step-1][x-1][y];
                    }
                    if(x+1<m){
                        dp[step][x][y]+=dp[step-1][x+1][y];
                    }
                    if(y-1>=0){
                        dp[step][x][y]+=dp[step-1][x][y-1];
                    }
                    if(y+1<n){
                        dp[step][x][y]+=dp[step-1][x][y+1];
                    }
                    dp[step][x][y]%=1000000007;
                }
            }
        }
    }
    return dp[N][i][j];
};
```

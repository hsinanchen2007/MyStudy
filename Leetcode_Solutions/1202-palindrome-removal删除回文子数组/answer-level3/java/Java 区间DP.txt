参考了其他大佬的题解，状态转移方程是一样的，分成区间首尾元素相等和不等
又因为是从左下，左， 下三个方向的状态得到当前状态，故采用反向遍历，代码如下：
```
public int minimumMoves(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];

        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
       
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(arr[i] == arr[j]){
                    if(j == i + 1) 
                        dp[i][j] = 1;
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }else{
                    dp[i][j] = Integer.MAX_VALUE;
                    for(int k = i; k < j; k++){
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
        
    }
```

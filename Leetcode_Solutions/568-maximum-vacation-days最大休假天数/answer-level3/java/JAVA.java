
        int n = flights.length;
        int k = days[0].length;
        int res = 0;
        int[][] dp = new int[k][n];
        for (int[] row: dp) Arrays.fill(row, -1);
        
        for(int i = 0;i < n; ++i){
            flights[i][i] = 1;
        }
        
        /*intial*/
        for(int i = 0; i < n; ++i){
            if(flights[0][i]!=0){
                dp[0][i] = days[i][0];
            }
        }
        
        for(int i = 1; i < k; ++i){
            for(int j = 0; j < n; ++j){
                for(int m = 0; m < n; ++m){
                    if(flights[m][j]!=0 && dp[i-1][m] >= 0){
                       dp[i][j] = Math.max(dp[i][j],dp[i-1][m] + days[j][i]); 
                    }
                }
            }
        }
        
        for(int i = 0;i < n; ++i){
            res = Math.max(res,dp[k-1][i]);
        }
        
        return res;
    
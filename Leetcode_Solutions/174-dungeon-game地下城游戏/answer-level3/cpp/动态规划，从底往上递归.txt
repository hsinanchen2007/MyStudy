// 一个原则： 到达任意一个方格的血量最少是 1
//dp[i] 中的数， 是到达此方块最少需要的血量

```
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0)
            return 0;
        
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n, 0));
        
        dp[m-1][n-1] = 1; // 初始化最后一个方格，即到达最后一个方格最少需要 1 个血量
        
        for(int i = m-2; i >= 0; i--)   // 生成最后一列的情况
        {
            int minval = max(dp[i+1][n-1] - dungeon[i+1][n-1], 1);
            dp[i][n-1] = minval;
      
        }
        for(int j = n-2; j >= 0; j--)   //生成最后一行的情况
        {
            int minval = max(dp[m-1][j+1] - dungeon[m-1][j+1], 1);
            dp[m-1][j] = minval;
        }
        
        for(int i = m-2; i >= 0; i--)   //从 第 m-2 行  n-2 列 向前进行递归求解
        {
            for(int j = n-2; j >= 0; j--)
            {
                int right = max(1, dp[i][j+1] - dungeon[i][j+1]);
                int down  = max(1, dp[i+1][j] - dungeon[i+1][j]);

                dp[i][j] = min(right, down);
            }
        }
        
        int res = max(1,dp[0][0] - dungeon[0][0]);
        
        return res;
        
    }

```

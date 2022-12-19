```
    /**
     * 动态规划 如果从左上开始算 则遇到正值时就需要计算正值的盈余 因为需要累计往下计算
     * 如果从右下开始往上算 遇到正的盈余就不用接着往下累计 直接更新成0就好
     * @param dungeon
     * @return
     */
    public int calculateMinimumHP(int[][] dungeon) {
        if(dungeon == null || dungeon.length == 0 || dungeon[0].length == 0){
            return 1;
        }
        int row = dungeon.length;
        int col = dungeon[0].length;
        int[][] dp = new int[row][col];
        dp[row - 1][col - 1] = dungeon[row - 1][col - 1] >= 0 ? 0 : -dungeon[row - 1][col - 1];
        for(int i = row - 2; i >= 0; i--){
            dp[i][col - 1] = Math.max(0, dp[i + 1][col - 1] - dungeon[i][col - 1]);
        }
        for(int i = col - 2; i >= 0; i--){
            dp[row - 1][i] = Math.max(0, dp[row - 1][i + 1] - dungeon[row - 1][i]);
        }
        for(int i = row - 2; i >= 0; i--){
            for(int j = col - 2; j >= 0; j--){
                dp[i][j] = Math.max(0, Math.min(dp[i + 1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0] + 1;
    }
```

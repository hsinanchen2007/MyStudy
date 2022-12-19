    
    //递归+剪枝
    class Solution {
    private:
        vector<vector<int>> memo;
        //找到从[x,y]点到终点的最小路径和
        int findminval(vector<vector<int>>& grid,int x,int y){
            if(x == grid.size()-1 && y == grid[0].size()-1)
                return grid[x][y];
            
            if(memo[x][y] != -1)  //如果此点已经计算过，直接返回其值，避免重复计算
                return memo[x][y];
            
            int val = grid[x][y];
            int right = -1,down = -1;
            if(y+1 < grid[0].size())
                right = findminval(grid,x,y+1);//向右递归
            if(x+1 < grid.size())
                down  = findminval(grid,x+1,y);//向下递归
            if(right == -1)
                memo[x][y] = val + down;
            if(down == -1)
                memo[x][y] = val + right;
            if(right != -1 && down != -1)
                memo[x][y] = val + min(right,down);
            return memo[x][y];  //保存本次计算的值，并返回
        }
    public:
        int minPathSum(vector<vector<int>>& grid) {
            if(grid.size() == 0)
                return 0;
            int m = grid.size();
            int n = grid[0].size();
            
            memo = vector<vector<int>>(m,vector<int>(n,-1));
            
            return findminval(grid,0,0);
        }
    };
    //动态规划解法
    class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            if(grid.size() == 0)
                return 0;
            int m = grid.size();
            int n = grid[0].size();
            //dp[i][j]表示从坐标[i,j]到达右下角的最短路径
            //那么dp[i][j] = grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            //特殊情况下，i表示最后一行，则只能向右，j为最后一列，则只能向下，直至终点
            vector<vector<int>> dp(m,vector<int>(n,-1));
            
            for(int i = m-1;i >= 0;i--){
                for(int j = n-1;j >= 0;j--){
                    if(j == n-1 && i == m-1)
                        dp[i][j] = grid[i][j];
                    else if(j == n-1)
                        dp[i][j] = grid[i][j] + dp[i+1][j];
                    else if(i == m-1)
                        dp[i][j] = grid[i][j] + dp[i][j+1];
                    else
                        dp[i][j] = grid[i][j] + min(dp[i][j+1],dp[i+1][j]);
                }
            }
            return dp[0][0];
        }
    };
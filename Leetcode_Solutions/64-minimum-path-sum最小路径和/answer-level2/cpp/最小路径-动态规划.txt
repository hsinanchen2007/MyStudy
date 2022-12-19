动态规划，关键是理解路径流程，该题较为简单。代码如下：
    /* 
    一样使用动态规划 
    i≠0 j≠0 dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j] 
    i=0 j≠0 dp[i][j] = dp[i][j-1] + grid[i][j]
    i≠0 j=0 dp[i][j] = dp[i−1][j] + grid[i][j] 
    i=0,j=0 dp[i][j] = grid[i][j]
    时间复杂度 O(MxN) ： 遍历整个 grid 矩阵元素。
    空间复杂度 O(MxN) ： 
    */

    int min(int a, int b)
    {
        return a>b?a:b;
    }

    class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            if(grid.empty() || grid[0].empty()) return 0;
            int m = grid.size(), n = grid[0].size();
            vector<vector<long>> dp(m, vector<long>(n,0));//M*N的vector二维数组，扩大数组类型防止溢出

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 && j==0) dp[i][j] = grid[i][j];            //只有向右向下两条路，以此判定
                    else if(i==0) dp[i][j] = dp[i][j-1] + grid[i][j];
                    else if(j==0) dp[i][j] = dp[i-1][j] + grid[i][j];
                    else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
            return dp.back().back();    //得到最后一个位置的值
        }
    };

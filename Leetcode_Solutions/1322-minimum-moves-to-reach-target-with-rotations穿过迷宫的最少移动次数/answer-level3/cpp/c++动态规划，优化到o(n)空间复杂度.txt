1. 由于到达（i，j）的最小次数由二维坐标和方向唯一确定，所以如果要动态规划，肯定是三维dp

2. 用right_dpi存尾巴到达(i,j)且🐍为水平方向的最少次数，用down_dpi存尾巴到达(i,j)q且🐍为垂直方向的最少次数。

3. 初始化条件在左上角，终止条件在右下角，转移条件有[右移，下移，选择]三种，扣好操作可行的边界条件和障碍条件。

4. 时间复杂度o(n^2),空间复杂度o(n^2),由于动态规划转移条件只依赖上一行，所以空间复杂度可最优化为o(n)
- 空间复杂度o(n^2)解法：
```
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> right_dp(n,vector<int>(n,4*n));
        vector<vector<int>> down_dp(n,vector<int>(n,4*n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                //左上角初始化
                if(i == 0 && j == 0){
                    right_dp[i][j] = 0;
                    if(i+1 < n && j+1 < n && grid[i][j] == 0 && grid[i+1][j] ==0 && grid[i+1][j+1]==0 && grid[i][j+1]==0)
                        down_dp[i][j] = 1;
                }
                else{//操作有左移，下移，旋转，要扣一下可操作的条件（不超出边界，无障碍）
                    if(j+1 < n && j-1 >= 0 && grid[i][j+1] == 0)
                        right_dp[i][j] = min(right_dp[i][j],1+right_dp[i][j-1]);
                    if(j+1 < n && i-1 >= 0 && grid[i][j] == 0 && grid[i][j+1] == 0)
                        right_dp[i][j] = min(right_dp[i][j],1+right_dp[i-1][j]);
                    if(i+1 < n && i-1 >= 0 && grid[i+1][j] == 0)
                        down_dp[i][j] = min(down_dp[i][j],1+down_dp[i-1][j]);
                    if(i+1 < n && j-1>=0 && grid[i][j] == 0 && grid[i+1][j] == 0)
                        down_dp[i][j] = min(down_dp[i][j],1+down_dp[i][j-1]);
                    if(i+1 < n && j+1 < n && grid[i][j] == 0 && grid[i+1][j] ==0 && grid[i+1][j+1]==0 && grid[i][j+1]==0){
                        right_dp[i][j] = min(right_dp[i][j],1+down_dp[i][j]);
                        down_dp[i][j] = min(down_dp[i][j],1+right_dp[i][j]);
                    }
                }   
            }
        }
        return (right_dp[n-1][n-2] < 4 * n) ? right_dp[n-1][n-2] : -1;
    }
};
```
- 优化到o(n)空间复杂度解法：
```
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> right_dp(n,4*n);
        vector<int> down_dp(n,4*n);
        for(int i = 0;i < n;i++){
            vector<int> next_right_dp(n,4*n);
            vector<int> next_down_dp(n,4*n);
            for(int j = 0;j < n;j++){
                //左上角初始化
                if(i == 0 && j == 0){
                    next_right_dp[0] = 0;
                    if(i+1 < n && j+1 < n && grid[i][j] == 0 && grid[i+1][j] ==0 && grid[i+1][j+1]==0 && grid[i][j+1]==0)
                        next_down_dp[0] = 1;
                }
                else{//操作有左移，下移，旋转，要扣一下可操作的条件（不超出边界，无障碍）
                    if(j+1 < n && j-1 >= 0 && grid[i][j+1] == 0)
                        next_right_dp[j] = min(next_right_dp[j],1+next_right_dp[j-1]);
                    if(j+1 < n && i-1 >= 0 && grid[i][j] == 0 && grid[i][j+1] == 0)
                        next_right_dp[j] = min(next_right_dp[j],1+right_dp[j]);
                    if(i+1 < n && i-1 >= 0 && grid[i+1][j] == 0)
                        next_down_dp[j] = min(next_down_dp[j],1+down_dp[j]);
                    if(i+1 < n && j-1>=0 && grid[i][j] == 0 && grid[i+1][j] == 0)
                        next_down_dp[j] = min(next_down_dp[j],1+next_down_dp[j-1]);
                    if(i+1 < n && j+1 < n && grid[i][j] == 0 && grid[i+1][j] ==0 && grid[i+1][j+1]==0 && grid[i][j+1]==0){
                        next_right_dp[j] = min(next_right_dp[j],1+next_down_dp[j]);
                        next_down_dp[j] = min(next_down_dp[j],1+next_right_dp[j]);
                    }
                }   
            }
            swap(right_dp,next_right_dp);
            swap(down_dp,next_down_dp);
        }
        return (right_dp[n-2] < 4 * n) ? right_dp[n-2] : -1;
    }
};
```

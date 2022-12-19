### 解题思路
这种类型的题挺好玩的。。代码不知不觉就写长了

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dpi[m+2][n+2];
        for(int i = 0;i < m+2;i++){
            for(int j = 0;j < n+2;j++){
                if(i >=1 && i <= m && j >= 1 && j <= n){
                    if(grid[i-1][j-1] == 2) dpi[i][j] = 0;
                    else if(grid[i-1][j-1] == 1) dpi[i][j] = -1;
                    else dpi[i][j] = -2;
                }
                else dpi[i][j] = -2;
            }
        }
        int maxday = 0;
        bool fresh = false;
        bool next = true;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(next){
            next = false;
            fresh = false;
            int dp[m+2][n+2];
            for(int i = 0;i < m+2;i++){
                for(int j = 0;j < n+2;j++){
                    if(dpi[i][j] == -1){
                        int minday = INT_MAX;
                        for(int k = 0;k < 4;k++){
                            if(dpi[i + dir[k][0]][j + dir[k][1]] >= 0 && dpi[i + dir[k][0]][j + dir[k][1]] < minday){
                                minday = dpi[i + dir[k][0]][j + dir[k][1]] + 1;
                            }
                        }
                        next = minday == INT_MAX ? next : true;
                        dp[i][j] = minday == INT_MAX ? dpi[i][j] : minday;
                        maxday = maxday < dp[i][j] ? dp[i][j] : maxday;
                        fresh = minday == INT_MAX ? true : false;
                    }
                    else dp[i][j] = dpi[i][j];
                }
            }
            for(int i = 0;i < m+2;i++){
                for(int j = 0;j < n+2;j++){
                    dpi[i][j] = dp[i][j];
                }
            }
        }
        if(fresh) return -1;
        else return maxday;
    }
};
```
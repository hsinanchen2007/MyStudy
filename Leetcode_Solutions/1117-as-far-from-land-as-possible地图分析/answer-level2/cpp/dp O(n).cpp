1. 统计四个方向的mahaton距离；
2. 通过递推公式 dp[i][j] = min(dp[i-1][j]+1,dp[i+1][j]+1,dp[i][j+1]+1,dp[i][j-1]+1);

```c++ []
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = -1;
        vector<vector<int>> lup(r,vector<int>(c,r+c));
        vector<vector<int>> rup(r,vector<int>(c,r+c));
        vector<vector<int>> ldown(r,vector<int>(c,r+c));
        vector<vector<int>> rdown(r,vector<int>(c,r+c));
        
        
        for(int i = 0;i < r; ++i){
            /*left up*/
            for(int j = 0; j < c; ++j){
                if(grid[i][j] == 0){
                    if(i > 0){
                        if(grid[i-1][j] == 1){
                            lup[i][j] = 1;
                        }else{
                            lup[i][j] = min(lup[i][j],lup[i-1][j]+1);
                        }
                    }
                    if(j > 0){
                        if(grid[i][j-1] == 1){
                            lup[i][j] = 1;
                        }else{
                            lup[i][j] = min(lup[i][j],lup[i][j-1]+1);
                        }
                    }
                }
            }
            /*right up*/
            for(int j = c-1; j >= 0; --j){
                if(grid[i][j] == 0){
                    if(i > 0){
                        if(grid[i-1][j] == 1){
                            rup[i][j] = 1;
                        }else{
                            rup[i][j] = min(rup[i][j],rup[i-1][j]+1);
                        }
                    }
                    if(j < c-1){
                        if(grid[i][j+1] == 1){
                            rup[i][j] = 1;
                        }else{
                            rup[i][j] = min(lup[i][j],lup[i][j+1]+1);
                        }
                    }
                }
            }
        }
        
        for(int i = r-1;i >= 0; --i){
            /*left down*/
            for(int j = 0; j < c; ++j){
                if(grid[i][j] == 0){
                    if(i < r-1){
                        if(grid[i+1][j] == 1){
                            ldown[i][j] = 1;
                        }else{
                            ldown[i][j] = min(ldown[i][j],ldown[i+1][j]+1);
                        }
                    }
                    if(j > 0){
                        if(grid[i][j-1] == 1){
                            ldown[i][j] = 1;
                        }else{
                            ldown[i][j] = min(ldown[i][j],ldown[i][j-1]+1);
                        }
                    }
                }
            }
            /*right down*/
            for(int j = c-1; j >= 0; --j){
                if(grid[i][j] == 0){
                    if(i < r-1){
                        if(grid[i+1][j] == 1){
                            rdown[i][j] = 1;
                        }else{
                            rdown[i][j] = min(rdown[i][j],rdown[i+1][j]+1);
                        }
                    }
                    if(j < c-1){
                        if(grid[i][j+1] == 1){
                            rdown[i][j] = 1;
                        }else{
                            rdown[i][j] = min(rdown[i][j],rdown[i][j+1]+1);
                        }
                    }
                }
            }
      }
    
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(grid[i][j] == 0){
                    int res = r+c;
                    res = min(res,lup[i][j]);
                    res = min(res,rup[i][j]);
                    res = min(res,ldown[i][j]);
                    res = min(res,rdown[i][j]);
                    if(res < r+c){
                        ans = max(ans,res);
                    }
                }            
            }
        }

        return ans;
    }
};
```


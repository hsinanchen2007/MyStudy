复杂度O(mn)
dp[i][j]表示炸弹在(i,j)位置时能炸多少人

//对于每一行，统计任意两个相邻的墙壁之间的人数，则炸弹置于墙壁之间的任意一个空格均可炸伤这么多人
//同理，对于每一列也如此
```
    int maxKilledEnemies(vector<vector<char>>& grid) {
        
        // 每个位置能炸到的人为4个方向的人的总和
        int m = grid.size(); if(m<=0) return 0;
        int n = grid[0].size(); if(n<=0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            // 计算当前行相邻两个墙壁之间人的个数
            int s = -1;
            int j = s+1;
            while(j<n){
                int count = 0;
                while(j<n && grid[i][j]!='W'){
                    count += (grid[i][j]=='E');
                    j++;
                }
                for(int k=s+1; k<j; k++){
                    if(grid[i][k]=='0'){
                        dp[i][k] += count;
                    }
                }
                s = j;
                j = s+1;
            }
        }
        for(int i=0; i<n; i++){
            int s = -1;
            int j = s+1;
            while(j<m){
                int count = 0;
                while(j<m && grid[j][i]!='W'){
                    count += (grid[j][i]=='E');
                    j++;
                }
                for(int k=s+1; k<j; k++){
                    if(grid[k][i]=='0'){
                        dp[k][i] += count;
                    }
                }
                s = j;
                j = s+1;
            }
        }
        int ans = -1;
        for(auto row : dp){
            for(auto val : row){
                ans = max(ans, val);
            }
        }
        return ans;
    }
```
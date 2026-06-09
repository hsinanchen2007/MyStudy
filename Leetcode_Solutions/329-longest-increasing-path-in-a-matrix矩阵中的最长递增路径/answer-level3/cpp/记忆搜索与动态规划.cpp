方法一：dfs+记忆矩阵
这里dfs搜索中并不需要flag数组来记录已经访问的元素，访问过的元素已经包含在大小关系中了
```
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int x, int y){
        
        if(memo[x][y]!=-1) return memo[x][y];
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int ans = 1;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                int tx = x+dx[i], ty = y+dy[i];
                if(tx<memo.size() && tx>=0 && ty>=0 && ty<memo[0].size() && matrix[x][y]>matrix[tx][ty]){
                    ans = max(ans, 1+dfs(matrix, memo, tx, ty));
                }
            }
        }
        return memo[x][y]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        // 方法一：给定初始节点，dfs搜索
        int m = matrix.size(); if(m==0) return 0;
        int n = matrix[0].size(); if(n==0) return 0;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int ans = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }
        return ans;
    }
```

方法二：动态规划
```
    // dp[i][j][k]表示matrix[i][j]结尾且数组长度不超过k时的最长递增路径长度
    // 利用滚动数组为dp[i][j][2]
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        // 方法二：动态规划 复杂度O(m*n*max_path_len), 与Floyd算法类似
        //         ** 复杂度可以进一步改进为原来的一半，ans为最后dp的最大值
        int m = matrix.size(); if(m==0) return 0;
        int n = matrix[0].size(); if(n==0) return 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>{1,1}));
        int cur = 0;
        int ans = 1;
        while(1){
            bool is_change = false;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    // 给定matrix[i][j], 选择其前面最近邻的节点使得dp[i][j]最大
                    int old = dp[i][j][cur];
                    if(i-1>=0 && matrix[i][j]>matrix[i-1][j] && 1+dp[i-1][j][cur]>dp[i][j][1-cur]) dp[i][j][1-cur] = 1+dp[i-1][j][cur];
                    if(i+1<m  && matrix[i][j]>matrix[i+1][j] && 1+dp[i+1][j][cur]>dp[i][j][1-cur]) dp[i][j][1-cur] = 1+dp[i+1][j][cur];
                    if(j-1>=0 && matrix[i][j]>matrix[i][j-1] && 1+dp[i][j-1][cur]>dp[i][j][1-cur]) dp[i][j][1-cur] = 1+dp[i][j-1][cur];
                    if(j+1<n  && matrix[i][j]>matrix[i][j+1] && 1+dp[i][j+1][cur]>dp[i][j][1-cur]) dp[i][j][1-cur] = 1+dp[i][j+1][cur];
                    if(old!=dp[i][j][1-cur]) is_change = true;
                }
            }
            if(is_change){
                ans++;
                cur = 1-cur;
            }else{
                return ans;
            }
        }
        return ans;
    }
```
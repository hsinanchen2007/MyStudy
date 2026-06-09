### 解题思路
动态规划

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1&&j==1) dp[i][j]=1;
                else if(i==1&&j==2) dp[i][j]=1;
                else if(i==2&&j==1) dp[i][j]=1;
                else if(i==2&&j==2) dp[i][j]=2;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
```
### 这是一开始的，超时，看得出来有很多重复计算
```cpp
class Solution {
public:
    int res=0;
    int uniquePaths(int m, int n) {
        dfs(1,1,m,n);
        return res;
    }
    void dfs(int x,int y, int m, int n){
        if(x==m && y==n){
            res++;
            return;
        }
        if(x+1<=m) dfs(x+1,y,m,n);
        if(y+1<=n) dfs(x,y+1,m,n);
    }
};
```

```
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        memset(dp, -1, size(dp));
        int res=dfs(mat, m, n);
        return res==INT_MAX?-1:res;
    }
private:
    int dp[2050];
    int trans(vector<vector<int>>& mat, int m, int n) {
        int mul=1;
        int cnt=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cnt+=mul*mat[i][j];
                mul<<=1;
            }
        }
        return cnt;
    }
    void solve(vector<vector<int>>& mat, int m, int n, int i, int j) {
        mat[i][j]^=1;
        if(i-1>=0) {
            mat[i-1][j]^=1;
        }
        if(j-1>=0) {
            mat[i][j-1]^=1;
        }
        if(i+1<m) {
            mat[i+1][j]^=1;
        }
        if(j+1<n) {
            mat[i][j+1]^=1;
        }
    }
    int dfs(vector<vector<int>>& mat, int m, int n) {
        int snap=trans(mat, m, n);
        if(snap==0) {
            return 0;
        }
        if(dp[snap]>=0) {
            return dp[snap];
        }
        int res=INT_MAX;
        dp[snap]=res;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                solve(mat, m, n, i,j);
                int tmp=dfs(mat,m,n);
                if(tmp!=INT_MAX) {
                    res=min(res,(tmp+1));
                }
                solve(mat, m, n, i,j); 
            }
        }
        dp[snap]=res;
        return res;
    }
};
```

```
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        for(int i=0;i<n;i++) {
            dp[i][0]=A[0][i];
        }
        for(int i=1;i<m;i++) {
            for(int j=0;j<n;j++) {
                dp[j][i%2]=dp[j][(i-1)%2];
                if(j-1>=0) {
                    dp[j][i%2]=min(dp[j][i%2], dp[j-1][(i-1)%2]);
                }
                if(j+1<n) {
                    dp[j][i%2]=min(dp[j][i%2], dp[j+1][(i-1)%2]);
                }
                dp[j][i%2]+=A[i][j];
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++) {
            res=min(res,dp[i][(m-1)%2]);
        }
        return res;
    }
};
```

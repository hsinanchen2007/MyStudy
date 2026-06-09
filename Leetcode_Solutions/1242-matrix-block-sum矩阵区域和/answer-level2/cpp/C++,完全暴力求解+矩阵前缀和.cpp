解法一：暴力
```
class Solution {
public:
//题目的意思就是：求出mat的某一个范围的和，将其放入到ans中
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r_low=(i-K>=0?i-K:0);
                int r_high=(i+K>=m?m-1:i+K);
                int c_low=(j-K>=0?j-K:0);
                int c_high=(j+K>=n?n-1:j+K);
                int cnt=0;
                for(int r=r_low;r<=r_high;r++){
                    for(int c=c_low;c<=c_high;c++){
                        cnt+=mat[r][c];
                    }
                }
                ans[i][j]=cnt;
            }
        }
        return ans;
    }
};
```
解法二：矩阵前缀和：
```
int dp[105][105];
class Solution {
public:
//矩阵前缀和。。。
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n));

        for(int i=1;i<=m;i++){//这一步主要是进行初始化
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i-1][j-1];
                //dp[i][j]总是与mat[i-1][j-1]对应的
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r_low=(i-K>=0?i-K:0);
                int r_high=(i+K>=m?m-1:i+K);
                int c_low=(j-K>=0?j-K:0);
                int c_high=(j+K>=n?n-1:j+K);
                ans[i][j]=dp[r_high+1][c_high+1]-dp[r_low][c_high+1]-dp[r_high+1][c_low]+dp[r_low][c_low];
            }
        }
        return ans;
    }
};
```

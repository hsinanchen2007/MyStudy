不管咋说，我感觉这个题转换为最长公共子序列我是没有想到的。哎
```
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int alen=A.size(),blen=B.size();
        vector<vector<int>>dp(alen+1,vector<int>(blen+1,0));
        for(int i=0;i<alen;i++){
            for(int j=0;j<blen;j++){
                if(A[i]==B[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[alen][blen];
        
    }
};
```

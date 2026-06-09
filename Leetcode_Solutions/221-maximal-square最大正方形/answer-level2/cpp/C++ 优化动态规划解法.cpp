```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        int dp[n+1];
        fill(dp,dp+n+1,0);
        int pre=0,maxlen=0;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                int temp=dp[j];
                if(matrix[i-1][j-1]=='1'){
                    int a=min(dp[j-1],pre);
                    dp[j]=min(a,temp)+1;
                    maxlen=max(maxlen,dp[j]);
                }else dp[j]=0;
                pre=temp;
            }
        }
        return pow(maxlen,2);
    }
};
```

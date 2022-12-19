```
//常规做法，时间复杂度为O(n*n)
//思路就是min(dp[j]+1 if vaild(j+1,i));

class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>>vaild(n,vector<int>(n,1));
        for(int l=2;l<=n;l++){
            for(int i=0,j=l-1;j<n&&i<n;i++,j++){
                vaild[i][j]=(s[i]==s[j]&&vaild[i+1][j-1]);
            }
        }
        vector<int>dp(n,n);
        for(int i=0;i<n;i++){
            if(vaild[0][i]==1){
                dp[i]=0;
                continue;
            }
            for(int j=0;j<i;j++){
                if(vaild[j+1][i]){
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
        
    }
};
```

### 解题思路
走折线，判断每一步是从上往下走还是从左往右走

### 代码

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1+n2!=n3) return false;
        //存储s3前i+j位是否是s1前i位和s2前j位交错
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n1;i++)
            if(s3[i-1] == s1[i-1])
                dp[i][0] = dp[i-1][0];
        for(int i=1;i<=n2;i++)
            if(s3[i-1] == s2[i-1])
                dp[0][i] = dp[0][i-1];

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int l = i+j;
                //left:dp[i][j-1] && s3[l-1] == s2[j-1]
                //up :dp[i-1][j] && s3[l-1] == s1[i-1]
                if((dp[i][j-1] && s3[l-1] == s2[j-1]) || (dp[i-1][j] && s3[l-1] == s1[i-1])){
                    dp[i][j] = 1;
                }
            }
        }
    
        return dp[n1][n2];
    }
};
```
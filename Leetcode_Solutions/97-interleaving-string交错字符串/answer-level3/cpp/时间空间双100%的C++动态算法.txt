非常传统的字符串动态规划算法，时间跟空间都能击败100%的C++用户

```
// a dp solution
// beat 100% C++ users in both time and space overheads

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 极端测试样例判断
        if(s3.size()!=s1.size()+s2.size())
            return false;
        if(s1.empty())
            return s2==s3;
        if(s2.empty())
            return s1==s3;
            
            
        int n = s1.size();
        int m = s2.size();
        
        // dp[i][j] 值为true，当且仅当s1[0,...,i-1] 与 s2[0,...,j-1] 能够交错为 s3[0,...,i-1+j-1];
        bool dp[n+1][m+1];
        memset(dp, false, (n+1)*(m+1)*sizeof(false));
        
        // 设置dp的base case，即s3完全由s1或者s2组成
        dp[0][0] = true;
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = dp[i-1][0]&&s3[i-1]==s1[i-1];
        }
        for(int j=1;j<=m;j++)
        {
            dp[0][j] = dp[0][j-1]&&s3[j-1]==s2[j-1];
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                // 考虑s1[i-1]
                bool state1 = dp[i-1][j]&&s1[i-1]==s3[i-1+j];
                // 考虑s2[j-1]
                bool state2 = dp[i][j-1]&&s2[j-1]==s3[i-1+j];
                dp[i][j]=state1||state2; 
            }
        }
        
        return dp[n][m];
    }
};
```

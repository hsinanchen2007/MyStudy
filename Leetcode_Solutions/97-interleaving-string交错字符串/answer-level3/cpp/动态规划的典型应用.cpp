### 解题思路
1、dp[i][j],表示s1[i-1]与s2[j-1]，是否可以构成s3[i+j+1]。（注意：必须要加个1，因为s1和s2都是从0开始的）
2、初始化dp[0][j]和dp[i][0],此时假设其中一个字符串为空，dp[0][j+1]取决于dp[0][j]和s2[j]和s3[j]。
3、dp[i+1][j+1]表示是s1[i]和s2[j]是不是可以组成s3[i+j+1],取决于dp[i][j+1]和s1[i]==s3[i+j+1]或者。。

### 代码

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+ s2.length() != s3.size()){
            return false;
        }
        int m = s1.length();
        int n = s2.length();
        vector<vector<bool>> dp(m+1, vector(n+1, false));
        dp[0][0] = true;
        for(int i = 0; i<m; i++){
            dp[i+1][0] = dp[i][0]&&(s1[i] == s3[i]);
        }
        for(int j = 0; j<n; j++){
            dp[0][j+1] = dp[0][j]&&(s2[j] == s3[j]);
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                dp[i+1][j+1] = (dp[i][j+1]&&s1[i] == s3[i+j+1]) || (dp[i+1][j]&&s2[j] ==s3[j+i+1]);
            }
        }
        return dp[m][n];
    }
};
```
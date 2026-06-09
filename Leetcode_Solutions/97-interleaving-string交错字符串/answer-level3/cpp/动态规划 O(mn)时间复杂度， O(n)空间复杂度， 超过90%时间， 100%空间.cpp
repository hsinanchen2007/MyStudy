### 解题思路
dp[i][j]表示 s1的前i个和s2的前j个， 能否交错形成s2的前i+j个

如果 s1[i] == s3[i+j] == s2[j]，那么s3[i+j]的字符可以来自s1[i]也可以来自s2[j]
        如果来自s1[i], 则dp[i][j] = dp[i-1][j]， 否则dp[i][j] = dp[i][j-1]
        dp[i][j] = dp[i-1][j] || dp[i][j-1]
如果 s1[i] == s3[i+j] != s2[j]，那么s3[i+j]的字符可以来自s1[i]
        dp[i][j] = dp[i-1][j]，
如果 s1[i] != s3[i+j] == s2[j]，那么s3[i+j]的字符可以来自s2[j]
        dp[i][j] = dp[i][j-1]，
否则dp[i][j] = false

因为dp[i][j]只和上方和左方有关，所以用两个翻转的数组轮流保存，只需要O(n)空间。

### 代码

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //dp[i][j] s1[0..i],s1[0..j]是否交错
        //if(s3[i+j+1] == s1[i+1] != s2[j+1])
        // dp[i+1][j] = dp[]
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> dp(2, vector<bool>(s2.size()+1, false));
        int k = 0;
        for(int i = 0;i <= s1.size();i++){
            for(int j = 0;j <= s2.size();j++){
                if(i == 0 && j == 0)
                    dp[k][j] = true;
                else if(i == 0) {
                    dp[k][j] = s2[j-1] == s3[j-1] ? dp[k][j-1] : false;
                }else if(j == 0) {
                    dp[k][j] = s1[i-1] == s3[i-1] ? dp[1-k][j] : false;
                }else {
                    dp[k][j] = s2[j-1] == s3[i+j-1] && s1[i-1] != s3[i+j-1] ? dp[k][j-1] :
                               s2[j-1] != s3[i+j-1] && s1[i-1] == s3[i+j-1] ? dp[1-k][j] :
                               s2[j-1] == s3[i+j-1] && s1[i-1] == s3[i+j-1] ? dp[1-k][j] || dp[k][j-1]:
                               false;
                }
            }   
            k = 1-k;
        }
        return dp[1-k][s2.size()];
    }
};
```
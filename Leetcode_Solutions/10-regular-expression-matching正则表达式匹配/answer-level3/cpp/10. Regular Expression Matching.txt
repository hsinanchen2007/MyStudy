### 解题思路
DP. 
二维的状态表达式，一个维度描述一个字符串的状态。

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int j = 1; j <= n; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j - 2];
            }
            cout << j << " "<< dp[0][j] << endl;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '.' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*' && j - 2 >= 0){
                    //if(j - 3 >= 0 && s[i-1] == p[j - 3]){ 
                        dp[i][j] = dp[i][j] || dp[i][j-2];
                    //}
                    if(s[i-1] == p[j - 2] || p[j - 2] == '.'){
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
                cout << i << " " << j << " "<< dp[i][j] << endl;
            }
        }
        return dp[m][n];
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        const int len_s = s.size();
        const int len_p = p.size();
        // bool *dp = new bool[len_s+1][len_p+1];
        vector<vector<bool>> dp(len_s+1, vector<bool>(len_p+1, false));
        dp[len_s][len_p] = true;
        for(int i = len_s; i >= 0; i--){
            for(int j = len_p-1; j >= 0; j--){
                dp[i][j] = false;
                if(p[j] == '*'){
                    dp[i][j] = dp[i][j+1] || (i < len_s && dp[i+1][j] );
                }
                if((p[j] == '?' || p[j] == s[i])&& i < len_s){
                    dp[i][j] = dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];

    }
};
```
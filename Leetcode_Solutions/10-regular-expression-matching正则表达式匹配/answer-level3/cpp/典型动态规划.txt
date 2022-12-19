### 解题思路
1、1）创建dp数组，为了方便dp的数组大小比字符串长度多一（为了方便dp[j-1]不需要进行判断j的大小）
   2）数组的第i个数对应dp[i+1],即dp[i][j]对应s[i-1]与p[j-1]是否匹配。
2、初始化
   1）、dp[0][0] = 1(即两个空字符串相匹配)
   2）、若p[i-1]=='*',匹配前面零个字符，即可以干掉i-1和i-2的字符，dp[0][j] == dp[0][i-2]。
3、递归
   1）若p[j-1]==s[i-1],则dp[i][j]=dp[i-1][j-1];或者p[j-1]=='.',也满足。
   2）若p[j-1] == '*'：
      s[i-1] != p[j-2],匹配前面零个字符(ab和abc*)，则dp[i][j] = dp[i][j-2];
      s[i-1] == p[j-2](或者 p[j-2] ==‘.’),匹配前面一个字符(abb和ab*)，则dp[i][j] = dp[i-1][j];
### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i = 2; i <= n; i++){
            dp[0][i] = dp[0][i-2]&&(p[i-1] =='*');
        }
        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                if(p[j-1] == '.' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2]||(s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
```
### 解题思路
动态规划  状态转移

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        // 状态dp[i][j]:表示s的前i个字符和p的前j个字符是否匹配(true:表示匹配)
        // 状态转移方程：
        //  1.当s[i] == p[j],或者p[j] == ? 那么dp[i][j] = dp[i-1][j-1];
        //  2.当p[j] == * 那么dp[i][j] = dp[i][j-1] || dp[i-1][j] 其中:
        //    dp[i][j-1] 表示 * 表示的是空字符，例如ab,ab*
        //    dp[i-1][j] 表示 * 代表的是非空字符，例如abcd,ab*
        // 初始化：
        //  1. dp[0][0]表示什么都没有，其值为true
        //  2. 第一行dp[0][j],换句话说,s为空，与p匹配，所以只要p开始为*才为true
        //  3. 第一列dp[i][0],当然全为false
        int m = s.size();
        int n = p.size();
        vector<bool> col(n+1);
        vector<vector<bool> > dp(m+1,col);
        
        //初始化
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            dp[0][i] = dp[0][i-1] && (p[i-1] == '*');
        }

        //状态转移
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }

        //返回结果
        return dp[m][n];
    }
};
```
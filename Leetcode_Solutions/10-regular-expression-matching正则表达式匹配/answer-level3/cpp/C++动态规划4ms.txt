时间复杂度O(m*n)

dp[i][j]表示模式串前i个字符"p.substr(0,i)"与待匹配串前j个字符"s.substr(0,j)"的匹配状态

```
class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[0 ~ p.length()] [0 ~ s.length()]
        vector<vector<bool>> dp(p.length()+1, vector<bool>(s.length()+1, false));

        // 两个字符串均为空时，为匹配状态
        dp[0][0] = true;

        // 模式串循环
        for(int i=0; i<p.length(); ++i) {
            // 当待匹配字符串为空时，模式字符串长度必为偶数
            // 任意字符与*成对出现，例如：".*x*a*"
            // 需要注意"**"是不合法的模式。
            dp[i+1][0] = i%2 && (dp[i-1][0] && p[i-1] != '*' && p[i] == '*');

            // 匹配串循环
            for(int j=0; j<s.length(); ++j) {
                if(p[i] == '*'){
                    // 当模式串当前字符为*时
                    // *不能为模式串首个字符，且前一个字符不能为*
                    if(i==0 || p[i-1] == '*') return false;

                    // 可能该模式未匹配任何字符，模式串回滚两个字符仍然匹配
                    dp[i+1][j+1] = dp[i-1][j+1] || 
                                    // 或者模式串匹配了不小于一个字符
                                    //   那么模式串也匹配了不包含最后一个字符的待匹配串
                                    //   并且模式串的上一个字符为'.'或与待匹配串最后一个字符相同
                                    (dp[i+1][j] && (p[i-1] == '.' || p[i-1] == s[j]));
                } else {
                    // 模式串最后一个字符不是'*'
                    // 那么匹配条件为：两串各退一个字符是匹配的，并且最后一个字符是匹配的
                    dp[i+1][j+1] = dp[i][j] && (p[i] == '.' || p[i] == s[j]);
                }
            }
        }
        return dp[p.length()][s.length()];
    }
};
```
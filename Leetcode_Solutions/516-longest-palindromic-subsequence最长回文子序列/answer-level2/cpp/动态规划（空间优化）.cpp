这个问题可以转化为原字符串s和其逆序r的最长公共子序列问题。

若用f[i][j]表示字符串s前i个字符构成的字符串，与r前j个字符构成的字符串的最长公共子序列。
那么状态传递函数可以表示为：
f[i][j] = f[i-1][j-1] + 1, 如果 s[i] == r[j]
f[i][j] = max(f[i-1][j], f[i][j-1]), 如果 s[i] != r[j]

代码如下：
int longestPalindromeSubseq(string s) {：
    int len = (int)s.length();
    string r(s);
    reverse(s.begin(), s.end());
    vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) {
            if(s[i-1] == r[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[len][len];
}

其实可以不用多一个逆序的字符串，只需要将按照一定的逆序进行读取原字符串就可以，这样可以减少空间的使用。
其次就是通过保存之前的数据，可以进行进一步的空间优化，代码如下：
int longestPalindromeSubseq(string s) {
    int len = static_cast<int>(s.length());
    vector<int> dp(len+1, 0);
    for(int i = 1; i <= len; i++) {
        int pre = dp[0];
        for(int j = 1; j <= len; j++) {
            if(s[i-1] == s[len-j]) {
                int tmp = dp[j];    // 保存f[i-1][j]
                dp[j] = pre + 1;    // 此时pre == f[i-1][j-1]
                pre = tmp;
            }
            else {
                pre = dp[j];    // 保存f[i-1][j]
                dp[j] = max(pre, dp[j-1]);  // 此时 pre == f[i-1][j], dp[j-1] == f[i][j-1]
            }
        }
    }
    return dp[len];
}
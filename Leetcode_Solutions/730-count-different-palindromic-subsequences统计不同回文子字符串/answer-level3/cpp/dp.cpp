dp(i, j)表示从i到j的子串的不同回文子序列的个数,那么可以对原串正反都做序列自动机，用left_x表示x字符的最左下标,right_x表示x字符的最右下标,那么答案就是dp(left_a, right_b) +...dp(left_d, right_d),那么这个dp怎么做呢，对于一个dp(i, j),默认s[i] == s[j],以s[i] = s[j] = 'a'为例，找i左边的b,c,d,找j右边的b, c, d,单后dp(i, j) = 这些位置的dp值求和,当下一个为a的时候加上2即可。为了方便用了记忆化搜索。
```
long long dp[1002][1002];
int per[1002][4], suf[1002][4];
const int mod = 1e9 + 7;
class Solution {
public:
    long long dfs(int l, int r, string &s) {
        if (l > r || l == -1) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        else if (l + 1 == r) return dp[l][r] = 2;
        else if (l == r) return dp[l][r] = 1;
        long long ret = 0;
        if (s[l] != s[r]) {
            for (int i = 0; i < 4; ++i) {
                ret = ret + dfs(suf[l][i], per[r][i], s);
                ret %= mod; 
            }
        } 
        else {
            for (int i = 0; i < 4; ++i) {
                ret = ret + dfs(suf[l][i], per[r][i], s);
                ret %= mod;
                if (i == s[l] - 'a') {
                    ret = ret + 2;
                    ret %= mod;    
                }
            } 
        }
        return dp[l][r] = ret;
    }
    void getper(string s) {
        memset(per[1], -1, sizeof(per[1]));
        int len = s.length();
        for (int i = 2; i < len; ++i) {
            for (int j = 0; j < 4; ++j) {
                per[i][j] = per[i - 1][j];
            }
            per[i][s[i - 1] - 'a'] = i - 1;
        }
    }
    void getsuf(string s) {
        int len = s.length();
        memset(suf[len - 2], -1, sizeof(suf[len - 2]));
        for (int i = len - 3; i >= 0; --i) {
            for (int j = 0; j < 4; ++j) {
                suf[i][j] = suf[i + 1][j];
            }
            suf[i][s[i + 1] - 'a'] = i + 1;
        }
    }
    int countPalindromicSubsequences(string S) {
        S = " " + S + "&";
        getper(S);getsuf(S);
        memset(dp, -1, sizeof(dp));
        return dfs(0, S.length() - 1, S);
    }
};
```

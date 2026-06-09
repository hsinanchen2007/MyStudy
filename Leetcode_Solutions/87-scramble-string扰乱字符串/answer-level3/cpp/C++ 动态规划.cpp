# 思路：
1，`dp[len][i][j]`代表`s1`与`s2`的两个长度为`len`的片段是否是为扰乱字符串对
其中，`s1`以`i`起始，`s2`以`j`起始，也就是`s1[i:(i + len - 1)]`, `s2[j:(j + len - 1)]`这两段。
2，状态转移方程为：
`dp[len][j][j] ||= (dp[k][i][j]&& dp[len - k][i + k][j + k]) || (dp[k][i][j + len - k] && dp[len - k][i + k][j])`
其中`k>=1 且 k < len`
空间复杂度`O(N^3)`，时间复杂度`O(N^4)`
```
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        int N = s1.size();
        vector<vector<vector<bool> > > dp(N + 1, vector<vector<bool> >(N, vector<bool>(N, false)));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i < N && i + len - 1 < N; ++i) {
                for (int j = 0; j < N && j + len - 1 < N; ++j) {
                    for (int k = 1; k < len; ++k) {
                        if (dp[k][i][j] && dp[len - k][i + k][j + k]) {
                            dp[len][i][j] = true;
                            break;
                        }
                        if (dp[k][i][j + len - k] && dp[len - k][i + k][j]) {
                            dp[len][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[N][0][0];
    }
};
```

![image.png](https://pic.leetcode-cn.com/5c71f480d37bb620845b2a52491e18813ef138508d7f5d5497786a747ad52a6e-image.png)

# 解法一：
二维动态规划
```
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int> > dp(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) dp[i][i] = 1;
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i + len - 1 < N; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][N - 1];
    }
};
```
![image.png](https://pic.leetcode-cn.com/c9baa6ad3d21774fd0fd3c7740335e9750772c804fdb90e54430cd3c244f7a3f-image.png)


# 解法二：
状态压缩为一维的动态规划
```
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<int> dp(N, 1);
        for (int i = N - 1; i >= 0; --i) {
            int prev = 0;
            for (int j = i + 1; j < N; ++j) {
                int temp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = 2 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[N - 1];
    }
};
```

![image.png](https://pic.leetcode-cn.com/067676a7f3400ee93757c1136a846579cfa2c4a910bdff2ae549c876269c2b9d-image.png)

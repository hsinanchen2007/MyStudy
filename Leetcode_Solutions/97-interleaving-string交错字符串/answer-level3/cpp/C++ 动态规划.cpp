# 解法一：
原始动态规划
```c++ []
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int N1 = s1.size();
        int N2 = s2.size();
        int N3 = s3.size();
        if (N1 + N2 != N3) return false;
        vector<vector<bool> > dp(N1 + 1, vector<bool>(N2 + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= N1; ++i) {
            for (int j = 0; j <= N2; ++j) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[N1][N2];
    }
};
```

![image.png](https://pic.leetcode-cn.com/d31d037498023415ada5676a7df80feaf7bbba9baa6b042550cec67e23179e18-image.png)

# 解法二：
状态压缩动态规划

``` c++ []
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int N1 = s1.size();
        int N2 = s2.size();
        int N3 = s3.size();
        if (N1 + N2 != N3) return false;
        vector<bool> dp(N2 + 1, false);
        dp[0] = true;
        for (int i = 0; i <= N1; ++i) {
            for (int j = 0; j <= N2; ++j) {
                if (i > 0 && s1[i - 1] != s3[i + j - 1]) {
                    dp[j] = false;
                }
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[j] = dp[j] || dp[j - 1];
                }
            }
        }
        return dp[N2];
    }
};
```

![image.png](https://pic.leetcode-cn.com/f5ebd60511f287d9917ae9fb1442a17168a446bc1de5a47d1b8700914b9f69f1-image.png)

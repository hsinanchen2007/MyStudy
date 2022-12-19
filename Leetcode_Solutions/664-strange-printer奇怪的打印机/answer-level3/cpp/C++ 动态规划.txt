# 解法一：
直接动态规划

```C++ []
class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<vector<int> > dp(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) dp[i][i] = 1;
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i < N && i + len - 1 < N; ++i) {
                int j = i + len - 1;
                dp[i][j] = 1 + dp[i + 1][j];
                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] == s[i]) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][N - 1];
    }
};
```
![image.png](https://pic.leetcode-cn.com/a7e9a5db0af5180f67e31de90998276ad6e707d2fbb65f751a1ee4fdf6e8bd84-image.png)

# 解法二：
记忆化深度优先搜索
```C++ []
class Solution {
public:
    vector<vector<int> > dp;
    int dfs(const string& s, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        int res = 1 + dfs(s, i + 1, j);
        for (int k = i + 1; k <= j; ++k) {
            if (s[k] == s[i]) {
                res = min(res, dfs(s, i + 1, k) + dfs(s, k + 1, j));
            }
        }
        dp[i][j] = res;
        return res;
        
    }
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        dp = vector<vector<int> >(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            dp[i][i] = 1;
        }
        return dfs(s, 0, N - 1);
    }
};
```

![image.png](https://pic.leetcode-cn.com/3194bf33ac713db57777f01e84d14fe341bb899345c8b1270adeb4bf1b18618a-image.png)

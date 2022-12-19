```
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int N = str1.size();
        int M = str2.size();
        vector<vector<int> > dp(N + 1, vector<int>(M + 1, 0));
        vector<vector<int> > path(N + 1, vector<int>(M + 1, 0));
        for (int i = 1; i <= N; ++i) path[i][0] = 1;
        for (int j = 1; j <= M; ++j) path[0][j] = 2;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = 1;
                if (dp[i][j - 1] > dp[i][j]) {
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = 2;
                }
                if (str1[i - 1] == str2[j - 1] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    path[i][j] = 3;
                }
            }
        }
        string res;
        int i = N;
        int j = M;
        while (path[i][j] != 0) {
            if (path[i][j] == 1) {
                res += str1[--i];
            } else if (path[i][j] == 2) {
                res += str2[--j];
            } else {
                res += str1[--i];
                --j;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/985a90a49bc00fde7166161f3b2b0be4cf7071a4625f36f09df67dbb9d4ada8b-image.png)

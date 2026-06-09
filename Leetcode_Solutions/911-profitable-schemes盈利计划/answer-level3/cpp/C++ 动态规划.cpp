# 解法一：
三维动态规划
1，`dp[i][j][k]`代表考虑前`i`个profit的情况下，在可用人数为`j`个情况下，能获取利润至少为`k`的情况数
2，状态转移方程为：
令`g = group[i - 1];`
令`p = profit[i - 1];`
则`dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - g][max(k - p, 0)];`

```C++ []
class Solution1 {
public:
    const long M = 1e9 + 7;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int N = profit.size();
        vector<vector<vector<long> > > dp(N + 1, vector<vector<long> >(G + 1, vector<long>(P + 1, 0)));
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= G; ++j) {
                dp[i][j][0] = 1;
            }
        }
        for (int i = 1; i <= N; ++i) {
            int g = group[i - 1];
            int p = profit[i - 1];
            for (int j = 1; j <= G; ++j) {
                for (int k = 0; k <= P; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= g) {
                        dp[i][j][k] += dp[i - 1][j - g][max(k - p, 0)];
                    }
                    dp[i][j][k] %= M;
                }
            }
        }
        return dp[N][G][P];
    }
};
```
![image.png](https://pic.leetcode-cn.com/a13198e9597f5d6ca1ceab87eb51b4c543405b997cc76191af2f3bdabddd4aa6-image.png)


# 解法二：
状态压缩动态规划
滚动利用dp
```C++ []
class Solution {
public:
    const long M = 1e9 + 7;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int N = profit.size();
        vector<vector<long> > dp(G + 1, vector<long>(P + 1, 0));
        for (int j = 0; j <= G; ++j) {
            dp[j][0] = 1;
        }
        for (int i = 1; i <= N; ++i) {
            int g = group[i - 1];
            int p = profit[i - 1];
            auto dp1 = dp;
            for (int j = G; j >= g; --j) {
                for (int k = 0; k <= P; ++k) {
                    dp[j][k] += dp[j - g][max(k - p, 0)];
                    dp[j][k] %= M;
                }
            }
        }
        return dp[G][P];
    }
};
```

![image.png](https://pic.leetcode-cn.com/289c2289f31e9f1fca7dadce664be96bc633e1be5add2eef71c5fdbb3cca297f-image.png)

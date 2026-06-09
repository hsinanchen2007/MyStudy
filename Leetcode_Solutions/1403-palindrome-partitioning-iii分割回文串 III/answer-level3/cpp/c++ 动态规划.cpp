动态规划：

首先，计算从i到j替换字符串为回文串的代价，保存数组

然后使用动态规划计算结果。

状态转移

0~n切分成k个子串均为回文串的最小代价为

取最小值：

- 0~1切分成k-1个子串的最小代价 + 1~n为回文串的最小代价
- 0~2切分成k-1个子串的最小代价 + 2~n为回文串的最小代价
- 0~3切分成k-1个子串的最小代价 + 3~n为回文串的最小代价
- ....
- 0~n-2切分成k-1个子串的最小代价 + n-2~n为回文串的最小代价
- 0~n-1切分成k-1个子串的最小代价 + n-1~n为回文串的最小代价

```c++
class Solution {
public:
    int palindromePartition(string s, int k) {
        int len = s.size();
        if (len == k) return 0;
        vector<vector<int>> cost(len, vector<int>(len));
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                int l = i, r = j;
                while (l < r) {
                    cost[i][j] += s[l] != s[r];
                    ++l;
                    --r;
                }
            }
        }
        vector<vector<int>> dp(len + 1, vector<int>(k + 1, 99999));
        dp[0][0] = 0;
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int x = 0; x < i; ++x) {
                    dp[i][j] = min(dp[i][j], dp[x][j - 1] + cost[x][i - 1]);
                }
            }
        }
        return dp[len][k];
    }
};
```
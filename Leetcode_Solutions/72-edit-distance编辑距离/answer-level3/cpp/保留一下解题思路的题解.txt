```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 0; i <= n; ++i) dp[0][i] = i;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                f[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        }
        return dp[m][n];
    }
};
```
首先看到长成这样的题目，脑海中就要有用动态规划思路来做的意识，要不容易把自己绕蒙。
这道题的难点是怎么构造状态转移方程，也就是：$dp[i] = f(dp[i - 1])$.
这道题的状态转移思路是：用一个数组dp[m][n]来表示：word1的前m个数可以用word2的前n个数表示的最小操作数。
由于把word2转换为word1可以用三种办法，只要求出这三种办法操作数的最小值，就可以作为dp[i][j]。
当采用删除操作时, 说明word2的第j个数是多余的，只需要前j-1个数即可：dp[i][j] = dp[i][j - 1] + 1
当采取增加操作时：dp[i][j] = dp[i - 1][j] + 1, word2前j个数可以表示word1的i - 1个数，1为这一步的操作
当采取替换操作时:如果word2[j] = word1[i]，那么就不用替换，有dp[i][j] = dp[i - 1][j - 1] + (word2[j] != word1[i])
最后返回dp[m][n], 意义为：word2的n个字母替换为word1的m个字母需要的最小操作数。
当然，也可以在每一步先判断一下word2[j]和word1[i]是否相等。
代码变成如下：
```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) f[i][0] = i;
        for (int i = 0; i <= n; ++i) f[0][i] = i;
        for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) f[i][j] = word2[j - 1] == word1[i - 1] ?  f[i][j] = f[i - 1][j - 1] : min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) +1;
        return f[m][n];
    }
};
```

对了，需要指明的一点是：
dp[i - 1][j - 1] <= min(dp[i][j - 1], dp[j - 1][i])
也就是说dp[i - 1][j - 1]比dp[i][j - 1]和dp[j - 1][i]都要小，
看完这篇题解，如果能理解上面这个式子，也就证明理解了状态转移方程，这个题也就理解了。


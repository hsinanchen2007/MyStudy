### 解题思路
dp[i][j]表示word1的前i个元素转换成word2的前j个元素需要的最小操作数
则，结果为：dp[word1.size()][word2.size()]

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // 有一个字符串为空时，操作次数为另一个字符串的长度
        if (n1 == 0 || n2 == 0) return n1 + n2;
        // 一般情况使用dp，处理边界
        // word1为空时，变为word2需要一直添加元素
        for (int i = 0; i <= n1; i++) dp[i][0] = i;
        // word2为空时，word1需要一直删除元素
        for (int i = 0; i <= n2; i++) dp[0][i] = i;
        // 一般情况下：对于i, j，word1[i - 1] == word2[j - 1]时，
        // dp[i][j]取插入、删除和不替换中的最小值
        // 不相等时，取插入、删除和替换中的最小值
        // 插入情况下，对应dp[i][j - 1]
        // 删除情况下，对应dp[i - 1][j]
        // 替换情况下，对应dp[i - 1][j - 1]
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int t1 = dp[i][j - 1] + 1;
                int t2 = dp[i - 1][j] + 1;
                int t3 = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) t3++;
                dp[i][j] = min(t1, min(t2, t3));
            }
        }

        return dp[n1][n2];
    }
};
```
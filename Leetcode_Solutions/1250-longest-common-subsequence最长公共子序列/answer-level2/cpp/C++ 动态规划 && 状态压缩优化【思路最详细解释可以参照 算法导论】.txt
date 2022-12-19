## 直接动态规划
时间复杂度：O(MN)
空间复杂度: O(MN)
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int rows = text1.size();
        const int cols = text2.size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        // 求解边界 BEGIN
        if (text1[0] == text2[0])
            dp[0][0] = 1;
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0];
            if (text1[i] == text2[0]) {
                dp[i][0] = 1;
            }
        }
        for (int j = 1; j < cols; j++) {
            dp[0][j] = dp[0][j - 1];
            if (text1[0] == text2[j]) {
                dp[0][j] = 1;
            }
        }
        // 求解边界 END

        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++) {
                if (text1[i] == text2[j]) { // 遇到匹配字符
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else { // 不匹配时，继承左上中的较大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        return dp[rows - 1][cols - 1];
    }
};
```

## 状态压缩后
时间复杂度：O(MN)
空间复杂度: O(N)
因为状态转移至涉及左、上、左上三个点，所以可以压缩成一维数组

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int cols = text2.size();
        vector<int> dp(cols, 0);
        // 一次性将text1的当前字符值取出来，避免重复数组操作
        // 优化到这里终于双100%击败其他用户了 ORZ
        for (const auto ti : text1) {
            int last = dp[0];
            if (ti == text2[0]) {
                dp[0] = 1;
            }

            for (int j = 1; j < cols; j++) {
                if (ti == text2[j]) {
                    swap(dp[j], last);
                    dp[j]++;
                } else {
                    last = dp[j];
                    if (dp[j - 1] > dp[j])
                        dp[j] = dp[j - 1];
                }
            }
        }
        return dp[cols - 1];
    }
};
```
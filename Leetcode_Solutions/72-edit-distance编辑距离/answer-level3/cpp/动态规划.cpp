### 解题思路

动态规划

### 代码

```cpp
class Solution {
public:
    static int minDistance(string word1, string word2) {
        vector<vector<int> > dp;
        for (int i = 0; i <= word1.length(); ++i) {
            vector<int> vec_tmp(word2.length() + 1);
            dp.push_back(vec_tmp);
        }

        for (int j = 0; j <= word2.length(); ++j) {
            dp[0][j] = j;
        }
        for (int i = 0; i <= word1.length(); ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= word1.length(); ++i) {
            for (int j = 1; j <= word2.length(); ++j) {
                if (i - 1 >= 0 && j - 1 >= 0 && word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
};
```
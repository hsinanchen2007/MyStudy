### 状态转移方程
```cpp
f(i, j) 代表 word1[0...i] 和 word2[0...j] 的编辑距离 
f(i, j) = f(i-1, j-1),                                  word1[i] == word2[j]
f(i, j) = min(f(i, j-1), f(i-1, j), f(i-1, j-1)) + 1,   word1[i] != word2[j]
```

### 迭代
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() || word2.empty()) return word1.size() + word2.size();
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
        dp[0][0] = word1[0] == word2[0] ? 0 : 1;
        for (int j = 1; j < word2.size(); j++) {
            dp[0][j] = word2[j] == word1[0] ? j : dp[0][j-1]+1;
        }
        for (int i = 1; i < word1.size(); i++) {
            dp[i][0] = word1[i] == word2[0] ? i : dp[i-1][0]+1;
        }
        for (int i = 1; i < word1.size(); i++) {
            for (int j = 1; j < word2.size(); j++) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp.back().back();
    }
};
```
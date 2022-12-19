### 解题思路
动态规划

### 代码

```cpp
class Solution {
public:
    // 动态规划dp
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) {return false;}
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int right = 0; right <= n; right++) {
            for (int left = 0; left < right; left++) {
                if (dp[left] && find(wordDict.begin(), wordDict.end(), s.substr(left, right - left)) != wordDict.end()) {
                    dp[right] = true;
                }
            }
        }
        return dp[n];
    }
};
```

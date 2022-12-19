```
class Solution {
public:
    int longestPalindrome(string str) {
        vector<int> dp(128);
        int ret = 0;
        for (char ch: str) if (!(dp[ch] = !dp[ch])) ret += 2;
        return ret == str.size() ? ret : ret + 1;
    }
};
```

### 解题思路
s[0, len]，标识原始字符串s；s[i, len]标识以s[i]开头的子串。
s[0, len]可以由wordDict拆分， 其子问题是s[i, len]可以被wordDict拆分。
每一步的处理是在wordDict中找出当前s[i,len]可以从头匹配的字符串s[i,j-1]，然后递归到子问题s[j,len]中处理。
递归终点是s[len,len]

这里使用了一个dp数组来记录当前s[i,len]是否已经计算过

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<char> dp(s.size(), -1);
        return wordBreak(s, wordDict, dp, 0);
    }

    bool wordBreak(string& s, vector<string>& wordDict, vector<char>& dp, int pos) {
        if (pos == s.size()) return true;
        if (-1 != dp[pos]) return dp[pos];                    // 记忆化搜索加速
        for (int i = 0; i < wordDict.size(); ++i) {
            int j = pos;
            int k = 0;
            while (k < wordDict[i].size() && j < s.size()) {
                if (wordDict[i][k] != s[j]) break;
                k++;
                j++;
            }
            if (k != wordDict[i].size()) continue;
            if (wordBreak(s, wordDict, dp, j)) {
                dp[pos] = 1;
                return true;
            }
        }
        dp[pos] = 0;
        return false;
    }
};
```
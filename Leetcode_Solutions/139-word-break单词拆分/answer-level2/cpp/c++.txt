### 解题思路
思路见注释

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] : s的前i个字符可以用字典里的单词表示
        int size = s.size();
        vector<bool> dp(size + 1, false);
        dp[0] = true; // 空字符串可以用字典里的单词表示

        unordered_set<string> us;
        for (string word : wordDict) {
            us.insert(word);
        }
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j <= size; j++) {
                if (dp[i] == true && us.count(s.substr(i, j - i))) {
                    // dp[i] == true: 之前i个字符可以用字典里的词表示(索引:0~i-1)
                    // us.count(s.substr(i, j - i)) : 索引ｉ开始，长度j-i的子串，可以用字典里的单词表示
                    // 也就是前j个字符可以用字典里单词表示
                    dp[j] = true;
                }
            }
        }
        return dp[size];
    }
};
```
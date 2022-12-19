### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        queue<string> que;
        vector<int> dp(s.length() + 1, 0);
        for (string w: wordDict) {
            if (s.compare(0, w.length(), w) == 0) {
                if (s == w) {
                        return true;
                    }
                que.push(s.substr(w.length()));
            }
        }
        while (!que.empty()) {
            string str = que.front();
            que.pop();
            cout << s.length() - str.length() << endl;
            if (dp[s.length() - str.length()]) {
                continue;
            }
            for (string w: wordDict) {
                if (str.compare(0, w.length(), w) == 0) {
                    if (str == w) {
                        return true;
                    }
                    dp[s.length() - str.length()] = 1;
                    que.push(str.substr(w.length()));
                }
            }
        }
        return false;
    }
};
```
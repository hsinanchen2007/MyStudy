### 解题思路
回溯+剪枝+记忆化+map存储键值对

### 代码

```cpp
class Solution {
public:
    vector<string> backtrack(string s, vector<string>& wordDict, map<string, vector<string>>& result) {
        if (result.count(s)) {return result[s];}
        if (s.empty()) {return {""};}
        vector<string> curStr;
        for (auto word: wordDict) {
            if (s.substr(0, word.size()) != word) {
                continue;
            }
            vector<string> temp = backtrack(s.substr(word.size()), wordDict, result);
            for (auto tmp: temp) {
                curStr.push_back(word + (tmp.empty()?"":" " + tmp));
            }
        }
        result[s] = curStr;
        return curStr;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, vector<string>> result;
        return backtrack(s, wordDict, result);
    }
};
```

### 解题思路
采用bfs策略，考虑当前词的所有可能的下一个候选词，这样的候选词满足在字典中，并且没有被访问过。

### 代码

```cpp
class Solution {
public:
    using Node = pair<string, int>;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<Node> q;
        q.push({beginWord, 1});
        
        while (!q.empty()) {
            auto [word, len] = q.front();
            q.pop();
            
            for (int i = 0; i != word.size(); i++) {
                for (const char& ch : "abcdefghijklmnopqrstuvwxyz") {
                    if (ch != word[i]) {
                        string tmp = word;
                        tmp[i] = ch;
                        if (dict.find(tmp) != dict.end()) {
                            if (tmp == endWord) return len + 1;
                            dict.erase(tmp);
                            q.push({tmp, len + 1});
                        }
                    }
                }
            }
        }
        return 0;
    }
};
```
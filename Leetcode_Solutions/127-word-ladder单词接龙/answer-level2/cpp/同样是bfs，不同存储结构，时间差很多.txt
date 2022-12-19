### 解题思路

### 代码

```cpp
class Solution {
public:
    bool Cmp(const string &s1, const string &s2)
    {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
            }
        }
        return true;
    };
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, vector<int>> m;        
        int len = wordList.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (Cmp(wordList[i], wordList[j]) == true) {
                    m[wordList[i]].push_back(j);
                    m[wordList[j]].push_back(i);
                }
            }
        }
        queue<int> q;
        int layer = 1;
        vector<int> vis(len, 0);
        for (int i = 0; i < len; i++) {
            if (wordList[i] == beginWord) {
                vis[i] = 1;
            }
            if (Cmp(wordList[i], beginWord) == true) {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (q.empty() == false) {
            layer++;
            int k = q.size();
            for (int i = 0; i < k; i++) {
                int curr = q.front();
                q.pop();
                if (wordList[curr] == endWord) {
                    return layer;
                }
                for (auto i : m[wordList[curr]]) {
                    if (vis[i] == 0) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
        return 0;
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
        void FindWords(unordered_set<string > &mset, unordered_set<string > &mset2, string &words, string &endWord){
            if (ok) return;
            res.push_back(words);
            for (int i = 0; i < words.size(); ++i){
                char base = words[i];
                for (int j = 'a'; j <= 'z'; ++j){
                    if (j == base) continue;
                    if (ok) break;
                    words[i] = j;
                    if (mset.find(words) == mset.end()) continue;
                    if (mset2.find(words) != mset2.end()) continue;
                    if (words == endWord) {
                        res.push_back(words);
                        ok = true; return;
                    }

                    mset2.insert(words);
                    FindWords(mset, mset2, words, endWord);
                }
                words[i] = base;
            }
            if (!ok)
                res.pop_back();
    }
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        static auto speedup = [](){ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();
        unordered_set<string > mset(wordList.begin(), wordList.end()), mset2;
        mset2.insert(beginWord);
        ok = false;
        FindWords(mset, mset2, beginWord, endWord);
        return res;
    }
    vector<string> res;
    bool ok;
};
```
将单词列表转化为无向图，然后从beginWord开始遍历，直到找到endWord，递归返回时记录经过的节点。
（注意处理特殊情况。）

```
class Solution {
    int Dif(string& a, string& b) {
        int count = 0;
        for(size_t i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                count++;
            }
        }
        return count;
    }
    bool Dfs(map<string, list<string>>& m, map<string, bool>& f, string& pre, vector<string>& res, string& endWord) {
        for(auto& s : m[pre]) {
            if(f[s]) {
                f[s] = false;
                if(s.compare(endWord) == 0) {
                    res.push_back(endWord);
                    res.push_back(pre);
                    return true;
                }
                if(Dfs(m, f, s, res, endWord)) {
                    res.push_back(pre);
                    return true;
                }
            }
        }
        return false;
    }
    void Insert(map < string, list<string> & m, string & key, string & value) {
        if(m.find(key) == m.end()) {
            m[key] = list<string>();
        }
        m[key].push_back(value);
    }
    void Graph(map < string, list<string> & m, vector<string> & wordList) {
        if(wordList.size() == 1) {
            m[wordList[0]] = list<string>();
            return;
        }
        for(size_t i = 0; i < wordList.size(); i++) {
            for(size_t j = i + 1; j < wordList.size(); j++) {
                if(Dif(wordList[i], wordList[j]) == 1) {
                    Insert(m, wordList[i], wordList[j]);
                    Insert(m, wordList[j], wordList[i]);
                }
            }
        }

    }
    int Judeg(vector<string>& wordList, size_t& i, map < string, list<string> & m) {
        if(m.find(endWord) == m.end()) {
            return INT_MAX;
        }
        int count = 0;
        for(i = 0; i < wordList.size(); i++) {
            count = Dif(wordList[i], beginWord);
            if(count <= 1) {
                break;
            }
        }
        if(i >= wordList.size()) {
            return INT_MAX;
        }
        return count;
    }
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, list<string>> m;
        Graph(m, wordList);
        size_t i = 0;
        int count = Judeg(wordList, i, m);
        if(count > 1) {
            return {};
        }

        vector<string> res;
        if(wordList[i].compare(endWord) == 0) {
            res.push_back(endWord);
        } else {
            map<string, bool> f;
            for(auto& word : wordList) {
                f[word] = true;
            }
            f[wordList[i]] = false;
            if(Dfs(m, f, wordList[i], res, endWord) && (count == 1)) {
                res.push_back(beginWord);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

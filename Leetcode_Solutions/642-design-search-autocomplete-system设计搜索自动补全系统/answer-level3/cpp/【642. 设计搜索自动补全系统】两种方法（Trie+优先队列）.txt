## 思路一：Trie
### 代码
```c++
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count;    
};

class AutocompleteSystem {
    void insert(const string &word, int time) {
        TrieNode *p = root;
        for (auto ch : word) {
            if (p->children.count(ch) == 0) {
                p->children[ch] = new TrieNode();
            }
            p = p->children[ch];
        }
        p->count += time;        
    }

    void search(TrieNode *node, string res, vector<pair<string, int>> &vec) {
        if (node->count > 0) {
            vec.push_back({res, node->count});
        }
        for (auto &it : node->children) {
            search(it.second, res + it.first, vec);
        }
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {        
        res = "";
        cur = root = new TrieNode;
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            ++cur->count;
            cur = root;
            res = "";
            return {};
        }
        if (cur->children.count(c) == 0) {
            cur->children[c] = new TrieNode();
        }
        cur = cur->children[c];
        res += c;
        vector<pair<string, int>> vec;
        search(cur, res, vec);
        sort(vec.begin(), vec.end(), [this](const pair<string, int> &p1, const pair<string, int> &p2) { 
            return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
        });
        vector<string> ret;
        for(const auto &p : vec) {
            ret.push_back(p.first);
            if (ret.size() >= 3) break;
        }
        return ret;
    }
private:
    TrieNode *root;
    TrieNode *cur;
    string res = "";
};
```
## 思路二：map+优先级队列
### 代码
```c++
class AutocompleteSystem {
    map<string, int> freq;
    string data;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {        
        for (int i = 0; i < sentences.size(); ++i) {
            freq[sentences[i]] += times[i];
        }
        data = "";
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            ++freq[data];
            data = "";
            return {};
        }
        data += c;
        auto cmp = [](pair<string, int> &a, pair<string, int> &b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto &f : freq) {
            bool matched = true;
            auto &s = f.first;
            for (int i = 0; i < data.size(); ++i) {
                if (i > s.size() || data[i] != s[i]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                pq.push(f);
            }
        }
        vector<string> res;
        while (!pq.empty() && res.size() < 3) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
```
### 另一种写法
优先级队列为小顶堆。
```c++
class AutocompleteSystem {
    unordered_map<string, int> freq;
    string data;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {        
        for (int i = 0; i < sentences.size(); ++i) {
            freq[sentences[i]] += times[i];
        }
        data = "";
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            ++freq[data]; 
            data = "";
            return {};
        }
        data += c;
        auto cmp = [](pair<string, int> &a, pair<string, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto &f : freq) {
            bool matched = true;
            auto &s = f.first;
            for (int i = 0; i < data.size(); ++i) {
                if (i > s.size() || data[i] != s[i]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                pq.push(f);
                if (pq.size() > 3) {
                    pq.pop();
                }
            }
        }
        vector<string> res(pq.size());
        for (int i = pq.size() - 1; i >= 0; --i) {
            res[i] = pq.top().first;            
            pq.pop();
        }
        return res;
    }
};
```



### 解题思路
1. 定义了 PriorityQueue 确保插入结果时保序。
2. 先定义了字典树 Trie
3. 然后使用 Trie构建字典
4. 重要的是 startsWith 函数，对每一种输入的可能进行深度遍历（用递归），找到匹配的答案，然后放入 m 中。如果m的size > 3 ，那么pop出一个最小的。

### 代码

```cpp
const int R = 26 + 1;
const int maxResult = 3;

using PriorityQueue = priority_queue<pair<int, string>, vector<pair<int, string>>, std::function<bool(pair<int, string>, pair<int, string>)>>;

class Trie {
private:
    vector<Trie*> nodes{R, nullptr};
    bool end{false};
    int times{0};

public:
    void insert(string s, int times) {
        Trie* node = this;
        for (auto w : s) {
            int ind = w==' '? R-1 : w-'a';
            if (!node->nodes[ind]) node->nodes[ind] = new Trie();
            node = node->nodes[ind];
        }
        node->end = true;
        node->times += times;
    }

    vector<string> startsWith(string s) {
        if (!s.size()) return {};

        PriorityQueue m([](pair<int, string> a, pair<int, string> b) -> bool {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        
        Trie* node = this;
        for (int i = 0; i < s.size(); i++) {
            int ind = s[i]==' ' ? R-1 : s[i]-'a';
            if (node->nodes[ind]) node = node->nodes[ind];
            else { node = nullptr; break; }
        }
    
        startsWith(s, node, m);
        
        vector<string> res;
        while (!m.empty()) {
            res.insert(res.begin(), m.top().second);
            m.pop();
        }
        return res;
    }

    void startsWith(string suffix, Trie* node, PriorityQueue& m) {
        if (!node) return;
        if (node && node->end) {
            m.push({node->times, suffix});
            if (m.size() > maxResult) {
                m.pop();
            }
        }

        for (int i = 0; i < R; i++) {
            if (node->nodes[i]) {
                string ns = suffix; ns.push_back(i==R-1? ' ' : i+'a');
                startsWith(ns, node->nodes[i], m);
            }
        }
    }
};

class AutocompleteSystem {
private:
    Trie* trie{nullptr};
    string s;

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        for (int i = 0; i < sentences.size(); i++) {
            trie->insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            trie->insert(s, 1); // Add into record for later search, it's a history too.
            s.clear();
            return {};
        }

        s.push_back(c);
        return trie->startsWith(s);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
```
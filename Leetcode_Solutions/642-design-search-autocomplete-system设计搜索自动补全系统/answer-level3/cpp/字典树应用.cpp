### 解题思路

获取所有以 prefix 开头的句子，需要在 startsWith 的 终结节点做一次 DFS。

### 代码

```cpp
class TrieNode {
private:
    TrieNode *children[27];
    bool isEnd;
    int freq;
public:
    TrieNode(): isEnd(false), freq(0) {
        for(int i=0; i<27; i++)
            children[i] = nullptr;
    }
    ~TrieNode() {
        for(int i=0; i<27; i++) {
            if(children[i])
                delete(children[i]);
        }
    }
    friend class Trie;
};

typedef pair<int, string> pis;

class PisCompare {
    public:
        bool operator()(const pis& lhs, const pis& rhs) {
            if(lhs.first != rhs.first)
                return lhs.first < rhs.first;
            else
                return lhs.second > rhs.second;
        }
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word, int times) {
        TrieNode *p = root;
        for(char c: word) {
            if(c == ' ')
                c = 'z' + 1;
            if(p->children[c - 'a'] == nullptr)
                p->children[c - 'a'] = new TrieNode;
            p = p->children[c - 'a'];
        }
        p->isEnd = true;
        p->freq += times;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(char c: word) {
            if(c == ' ')
                c = 'z' + 1;
            if(p->children[c - 'a'] == nullptr)
                return false;
            p = p->children[c - 'a'];
        }
        return p->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix, priority_queue<pis, vector<pis>, PisCompare>& res) {
        TrieNode *p = root;
        for(char c: prefix) {
            if(c == ' ')
                c = 'z' + 1;
            if(p->children[c - 'a'] == nullptr)
                return false;
            p = p->children[c - 'a'];
        }
        string tmp = prefix;
        dfs(p, tmp, res);
        return true;
    }
    
    void dfs(TrieNode *node, const string& cur, priority_queue<pis, vector<pis>, PisCompare>& res) {
        // 匹配后不返回，继续搜索
        if(node->freq > 0) {
            res.push(make_pair(node->freq, cur));
        }
        for(char c='a'; c <= 'z'; c++) {
            if(node->children[c-'a'] != nullptr) {
                dfs(node->children[c - 'a'], cur + c, res);
            }
        }
        if(node->children[26] != nullptr) {
            dfs(node->children[26], cur + ' ', res);
        }
    }
};

class AutocompleteSystem {
private:
    Trie trie;
    priority_queue<pis, vector<pis>, PisCompare> pq;
    string in;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        int n = sentences.size();
        for(int i=0; i<n; i++) {
            trie.insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> res;
        
        if(c == '#') {
            trie.insert(in, 1);
            in = "";
        } else {
            in.push_back(c);
            trie.startsWith(in, pq);
            for(int i=0; i<3 && !pq.empty(); i++) {
                auto p = pq.top();
                pq.pop();
                res.push_back(p.second);
            }
            while(!pq.empty()) {
                pq.pop();
            }
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
```
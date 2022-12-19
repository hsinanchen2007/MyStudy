在前缀树中插入键值对。
调用sum时，如果给定的prefix不在前缀树中，返回0。
否则找到前缀树中与prefix匹配完毕后的子树，对子树中的单词求和。
```
struct Trie {
    bool is_end;
    int val;
    unordered_map<char, Trie *> links;
    void insert(const string& word, const int val) {
        Trie *cur = this;
        for (const char ch : word) {
            if (!cur->links.count(ch)) cur->links.insert({ch, new Trie()});
            cur = cur->links[ch];
        }
        cur->val = val;
        cur->is_end = true;
    }
    
    int eval() {
        Trie *cur = this;
        int v = cur->is_end ? cur->val : 0;
        for (const auto& l : links)
            v += l.second->eval();
        return v;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Trie();
    }
    
    void insert(const string& key, const int val) {
        root->insert(key, val);
    }
    
    int sum(const string& prefix) {
        Trie* node = root;
        for (const char ch : prefix) {
            if (!node->links.count(ch)) return 0;
            node = node->links[ch];
        }
        return node->eval();
    }
private:
    Trie* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```

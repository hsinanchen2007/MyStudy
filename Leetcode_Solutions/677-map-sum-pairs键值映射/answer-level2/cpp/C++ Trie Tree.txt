用字典树存储，求 sum 的时候先判断是否存在这个前缀，若存在，从末尾字符开始 DFS 即可

```c++
class Trie {
private:
    struct TrieNode {
        TrieNode *son[26];
        int num;
    };
    TrieNode *root = new TrieNode();

public:
    void insert(string s, int num) {
        auto node = root;
        for (int i =  0; i < s.size(); i ++) {
            auto t = s[i] - 'a';
            if (!(node -> son[t])) 
                node -> son[t] = new TrieNode();
            node = node -> son[t];
        }
        node -> num = num;
    }

    int find(string s) {
        TrieNode *node = root;
        int res = 0;
        for (int i = 0; i < s.size(); i ++) {
            auto t = s[i] - 'a';
            if (!node -> son[t]) return res;
            node = node -> son[t];
        }
        res += dfs(node);
        return res;
    }

    int dfs(TrieNode *node) {
        int res = 0;
        res += node -> num;
        for (int i = 0; i < 26; i ++) 
            if (node -> son[i]) 
                res += dfs(node -> son[i]);
        return res;
    }
};

class MapSum {
private: 
    Trie *trie = new Trie();
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        trie -> insert(key, val);
    }
    
    int sum(string prefix) {
        return trie -> find(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```
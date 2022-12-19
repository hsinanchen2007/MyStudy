## 思路：Trie树
### 代码
```c++
struct TrieNode {
    TrieNode *children[26];
    bool flag;
    TrieNode() : flag(false) {
        for (auto &child : children) child = nullptr;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (const auto &c : word) {
            int i = c - 'a';
            if (p->children[i] == nullptr) {
                p->children[i] = new TrieNode();
            }
            p = p->children[i];
        }     
        p->flag = true; 
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(root, word, 0);
    }

    bool searchWord(TrieNode *p, const string &word, int i) {
        if (i == word.size()) return p->flag;
        if (word[i] != '.') {
            int t = word[i] - 'a';
            return p->children[t] && searchWord(p->children[t], word, i + 1);
        } else {
            for (auto &child : p->children) {
                if (child && searchWord(child, word, i + 1)) return true;
            }
            return false;
        }
    }
private:
    TrieNode *root;
};
```


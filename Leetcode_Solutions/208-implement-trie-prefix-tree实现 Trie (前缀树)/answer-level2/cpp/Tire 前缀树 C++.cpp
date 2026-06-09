```cpp []
class Trie {
    bool isWord;
    unordered_map<char, Trie*> children;

    // search a prefix or whole key in trie and
    // returns the node where search ends
    Trie* searchPrefix(string &word) {
        Trie *cur = this;
        for (auto &c : word) {
            if (not cur->children.count(c)) {
                return nullptr;
            } else {
                cur = cur->children[c];
            }
        }
        return cur;
    }

public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur = this;
        for (auto &c : word) {
            if (not cur->children.count(c)) {
                cur->children[c] = new Trie();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = searchPrefix(word);
        return node != nullptr and node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
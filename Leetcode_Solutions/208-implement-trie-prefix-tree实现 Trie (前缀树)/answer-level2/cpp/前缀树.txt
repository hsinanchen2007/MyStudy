### 解题思路
树形结构，每一个节点都是一个节点数组，因为节点值有26种可能(26个分支)。

![image.png](https://pic.leetcode-cn.com/9b75d5bc53c69b09c120064e5a07b3a41e3c19d0709e3e4fc4fa39433295c103-image.png)


### 代码

```cpp
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root_(new TrieNode()){
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root_.get();
        for (const char c : word) {
            if (!p->children[c-'a'])
                p->children[c-'a'] = new TrieNode();
            p = p->children[c-'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p && p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = find(prefix);
        return p != nullptr;
    }
private:
    struct TrieNode{
        TrieNode(): is_word(false), children(26, nullptr){}

        ~TrieNode() {
            for (const TrieNode *child : children) {
                if(child) delete child;
            }
        }

        bool is_word;
        vector<TrieNode *> children;
    };

    TrieNode * find(string word) {
        TrieNode *p = root_.get();
        for (const char c : word) {
            if (!p->children[c-'a'])
                return nullptr;
            p = p->children[c-'a'];
        }
        return p;
    }

    std::unique_ptr<TrieNode> root_;
};

```
```C++
class TrieNode {
public:
    char val;
    bool hasWord;
    TrieNode **child;
    TrieNode(): val('\0'), child(new TrieNode *[26] { nullptr }), hasWord(false) {}
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            delete child[i];
        }
        delete [] child;
    } 
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie();
    /** Inserts a word into the trie. */
    void insert(string word);
    /** Returns if the word is in the trie. */
    bool search(string word);
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);
    ~Trie();
private:
    TrieNode *root;
};

Trie::Trie() : root(new TrieNode()) { }

void Trie::insert(string word) {
    // Trie树中插入字符串
    TrieNode *ptr = root;
    for (auto val : word) {
        if (ptr->child[val-'a'] == nullptr) {
            ptr->child[val-'a'] = new TrieNode();
        }
        ptr = ptr->child[val-'a'];
    }
    ptr->hasWord = true;
}

bool Trie::search(string word) {
    TrieNode *ptr = root;
    for (auto val : word) {
        if (ptr->child[val-'a'] != nullptr)
            ptr = ptr->child[val-'a'];
        else
            return false;
    }
    if (ptr->hasWord)
        return true;
    return false;
}

bool Trie::startsWith(string prefix) {
    TrieNode *ptr = root;
    for (auto val : prefix) {
        if (ptr->child[val-'a'] != nullptr)
            ptr = ptr->child[val-'a'];
        else
            return false;
    }
    return true;
}

Trie::~Trie() {
    delete root;
}

```

简单的用valgrind测了一下内存泄漏情况
![屏幕快照 2020-03-31 下午10.37.05 上午.png](https://pic.leetcode-cn.com/676a136e4f5435c33622c5beaa1139d6d808e1e720d81f327c9996186b4711a5-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-31%20%E4%B8%8B%E5%8D%8810.37.05%20%E4%B8%8A%E5%8D%88.png)

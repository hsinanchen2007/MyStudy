## 思路一：数组
字典树的每个节点定义为一个大小为26的子节点指针数组，用一个标记符标记到当前位置为止是否为有一个单词。
### 代码
```c++
class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for (auto &a : child) {
            a = nullptr;
        }
    }   
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->child[i] == nullptr) {
                p->child[i] = new TrieNode();
            }
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->child[i] == nullptr) {
                return false;
            }
            p = p->child[i];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto &a : prefix) {
            int i = a - 'a';
            if (p->child[i] == nullptr) {
                return false;
            }
            p = p->child[i];
        }
        return true;
    }
};
```

## 思路二：map
### 代码
```c++
struct TrieNode {
    map<char, TrieNode*> next;
    bool flag;    
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (const auto &c : word) {
            if ((p->next).count(c) <= 0) {
                (p->next).insert({c, new TrieNode()});
            }
            p = (p->next)[c];
        }
        p->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (const auto &c : word) {
            if ((p->next).count(c) <= 0) {
                return false;
            }
            p = (p->next)[c];
        }
        return p->flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (const auto &c : prefix) {
            if ((p->next).count(c) <= 0) {
                return false;
            }
            p = (p->next)[c];
        }
        return true;
    }
};
```

## 对比
时间：法一查找较快
空间：法二更节省空间


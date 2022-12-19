### 解题思路
数据结构用了set和map来存储，其中set里面存储的内容是表示当前结点有哪些字母是单词结尾，map用来存储当前结点包含的字母及其子结点指针

### 代码

```cpp
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new trieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode *cur = root;

        for (int i = 0; i < word.size(); ++i) {
            if (cur->alpha.count(word[i]) == 0) {
                cur->alpha[word[i]] = new trieNode();
            }

            if (i == word.size() - 1) {
                cur->isWord.insert(word[i]);
            }

            cur = cur->alpha[word[i]];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->alpha.count(word[i]) == 0) {
                return false;
            }

            if (i == word.size() - 1 && cur->isWord.count(word[i]) != 0) {
                return true;
            }

            cur = cur->alpha[word[i]];
        }

        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trieNode *cur = root;

        for (int i = 0; i < prefix.size(); ++i) {
            if (cur->alpha.count(prefix[i]) == 0) {
                return false;
            }
            cur = cur->alpha[prefix[i]];
        }

        return true;
    }
private:
    struct trieNode {
        unordered_set<char> isWord;
        unordered_map<char, trieNode*> alpha;
    };

    trieNode *root;
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
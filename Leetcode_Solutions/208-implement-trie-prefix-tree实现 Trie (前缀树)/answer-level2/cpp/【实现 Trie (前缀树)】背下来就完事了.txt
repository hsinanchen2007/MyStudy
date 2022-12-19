### 思路
1. 前缀树
2. 背下来

### 答题
```C++
class Trie 
{
public:
    /** Initialize your data structure here. */
    Trie() {}

    ~Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            if (next[i] == nullptr) continue;
            delete(next[i]);
            next[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_string = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return node->is_string;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie *node = this;
        for (auto c : prefix)
        {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return true;        
    }
    
private:
    bool is_string = false;
    Trie* next[26] = {nullptr};
};
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


## [Trie模板](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)
```cpp
class Trie
{
private:
    bool isEnd;
    Trie *nxt[26];

public:
    /** Initialize your data structure here. */
    Trie()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            nxt[i] = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            if (!node->nxt[ch - 'a'])
                node->nxt[ch - 'a'] = new Trie();
            node = node->nxt[ch - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            if (!node->nxt[ch - 'a'])
                return false;
            node = node->nxt[ch - 'a'];
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            if (!node->nxt[ch - 'a'])
                return false;
            node = node->nxt[ch - 'a'];
        }
        return true;
    }
};
```
## [Trie上搜索](https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 `.` 或 `a-z` 。 `.` 可以表示任何一个字母。

### `.`可以表示任何一个字母，遇到到`.`的时候怎么办？

遇到`.`表示可以通向任何一个连接的字母  
`node->nxt[j] if node->nxt[j]!=nullptr`  

接着搜索剩下的字符串`word.substr(i+1)`  
只要至少一个分支匹配成功，就算成功`isMatch|=`

`this`指向当前引用的对象  
所以需要用`node->nxt[j]->search`来引用`node->nxt[j]`
```cpp
for (int j = 0; j < 26; j++)
{
    if (node->nxt[j])
    {
        isMatch |= node->nxt[j]->search(word.substr(i + 1));
    }
}
```
### code
```cpp
class WordDictionary
{
public:
    bool isEnd;
    WordDictionary *nxt[26];
    
    WordDictionary()
    {
        isEnd = 0;
        for (int i = 0; i < 26; i++)
            nxt[i] = nullptr;
    }

    void addWord(string word)
    {
        auto node = this;
        for (auto ch : word)
        {
            if (!node->nxt[ch - 'a'])
            {
                node->nxt[ch - 'a'] = new WordDictionary;
            }
            node = node->nxt[ch - 'a'];
        }
        node->isEnd = 1;
    }

    bool search(string word)
    {
        auto node = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                // . can represent any word exist
                bool isMatch = 0;
                for (int j = 0; j < 26; j++)
                {
                    if (node->nxt[j])
                    {
                        isMatch |= node->nxt[j]->search(word.substr(i + 1));
                    }
                }
                return isMatch;
            }
            node = node->nxt[word[i] - 'a'];
            if (!node)
                return false;
        }
        return node->isEnd;
    }
};
```
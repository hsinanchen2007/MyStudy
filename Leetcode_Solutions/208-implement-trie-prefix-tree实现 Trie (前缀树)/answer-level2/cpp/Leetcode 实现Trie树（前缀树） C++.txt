### 解题思路
需要注意几个地方：
1、每个节点数据结构的设计
2、根节点不保存任何字符
3、每个节点最多有26个儿子节点（只包含小写英文字母的情况）
4、插入某个字符时如果不存在保存该字符的节点则创建之
5、每个单词结尾的节点要用个标志位标识一下（用来search）
6、区分search 和 startWith的区别

![image.png](https://pic.leetcode-cn.com/ab8db5e4f62df9076e2746e91fd5b64c653216ee59770048e2f6547f1d90ea37-image.png)


### 代码

```cpp
struct TrieNode
{
public:
    char value;
    bool flag; 
    TrieNode* children[26]; 
    TrieNode()
    {
        value = 0;
        flag = false;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) { 
        if (word.length() == 0) return;

        TrieNode* pCur = &m_root; 
        for (int i = 0; i < word.length(); ++i)
        {
            int c = word[i] - 'a';
            if (!pCur->children[c])
            {
                pCur->children[c] = new TrieNode();
            }
            if (pCur->children[c]->value == 0)
            { 
                pCur->children[c]->value = 1;
            }
            if (i == word.length() - 1)
            {
                pCur->children[c]->flag = true;
            }
            pCur = pCur->children[c];          
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) { 
        if (word.length() == 0) return false;
        TrieNode* pCur = &m_root;
        int i = 0;
        for (i = 0; i < word.length() && pCur; ++i)
        {
            int c = word[i] - 'a';
            if (pCur->children[c] && pCur->children[c]->value == 1)
            {
                pCur = pCur->children[c];
            } 
            else
            {
                return false;
            }
        } 
        if (i == word.length() && pCur && pCur->flag) return true;
        else return false;  
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { 
        if (prefix.length() == 0) return false;
        TrieNode* pCur = &m_root;
        int i = 0;
        for (i = 0; i < prefix.length() && pCur; ++i)
        {
            int c = prefix[i] - 'a';
            if (pCur->children[c] && pCur->children[c]->value == 1)
            {
                pCur = pCur->children[c];
            } 
            else
            {
                return false;
            }
        } 
        if (i == prefix.length() && pCur) return true;
        else return false;
    }

private:
    TrieNode m_root;
};


 

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
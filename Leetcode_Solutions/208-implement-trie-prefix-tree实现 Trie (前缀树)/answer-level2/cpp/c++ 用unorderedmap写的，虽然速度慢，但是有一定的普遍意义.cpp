### 解题思路
首先说明下，我好想有点理解错题意了，题目的意思应该是把Trie当一个节点吧。我自己建了一个节点,Trie存root；
![image.png](https://pic.leetcode-cn.com/e2a5c9d4b69a2cfda718efb9e6991c0d0c40c86fd61bc0ed1d2dcb499c477be6-image.png)

我这个方法的核心就在于建立一个TrieNode的节点。val存字符，is_end用来表示当前节点是不是最后一个字符，可以用它来判断一个字符串。mp是一个hash表，存下一个字符对应的节点。
具体的做法，我直接注释
### 代码

```cpp
struct TrieNode
{
    char val;
    bool is_end;
    unordered_map<char,TrieNode*> mp;
    TrieNode():val(' '),is_end(false) {};
    TrieNode(char ch):val(ch),is_end(false) {};
};

class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        root=new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* p=root;
        for(int i=0; i<int(word.size()); ++i)
        {
            if((p->mp).count(word[i])==1)//当前字符存在，直接下一位
            {
                if(i==int(word.size())-1)
                    ((p->mp)[word[i]])->is_end=true;
                p=(p->mp)[word[i]];
            }
            else//当前字符不存在，需要插入
            {
                TrieNode* tmp=new TrieNode(word[i]);
                if(i==int(word.size())-1)
                    tmp->is_end=true;
                (p->mp)[word[i]]=tmp;
                p=tmp;
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* p=root;
        for(int i=0; i<int(word.size()); ++i)
        {
            if((p->mp).count(word[i])==1)
            {
                p=(p->mp)[word[i]];
            }
            else
                return false;
        }
        if(p->is_end)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* p=root;
        for(int i=0; i<int(prefix.size()); ++i)
        {
            if((p->mp).count(prefix[i])==1)
            {
                p=(p->mp)[prefix[i]];
            }
            else
                return false;
        }
        return true;
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
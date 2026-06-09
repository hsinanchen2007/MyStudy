### 解题思路
采用字典树，在建树的过程中直接出答案，省去后面遍历的过程，可能会快些。
结点额外存储单词长度和是否为叶子结点。在插入单词过程中，如果新创建了结点，则结束时自动将该单词长度计入，并标记为叶子结点；如果过程中从叶子结点创建新结点，则抹去该叶子结点标记，同时减去该结点单词长。
。。。因为懒，用数组建树的，内存消耗可能大点

### 代码

```cpp
class Solution {
    struct node
    {
        int word_len = 0;
        bool is_leaf = false;
        int next[27] = {0};
    }trie[14000];
    int cur = 2;
    int cnt = 0;
public:
    void insert(string word)
    {
        int p = 1;
        bool flag = false;
        for(int i=word.size()-1; i>=0; i--)
        {
            int ch = word[i] -'a' + 1;
            if(trie[p].next[ch] == 0)
            {
                trie[p].next[ch] = cur++;
                flag = true;
                if(trie[p].is_leaf)
                {
                    cnt -= trie[p].word_len + 1;
                    trie[p].is_leaf = false;
                }
            }
            p = trie[p].next[ch];
        }
        trie[p].word_len = word.size();
        if(flag)
        {
            trie[p].is_leaf = true;
            cnt += trie[p].word_len + 1;
        }
    }

    int minimumLengthEncoding(vector<string>& words) {
        for(int i=0; i<words.size(); i++)
        {
            insert(words[i]);
        }
        return cnt;
    }
};
```
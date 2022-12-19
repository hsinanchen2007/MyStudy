### 解题思路
字符串查找的场景，前缀树的搜索效率是大于哈希表的。而且本提用hash表也免不了遍历，其实搜索效率还是很低的。

利用前缀树，构建树的过程不多说了，这里需要判断是否是介绍，所以需要有endFlag标记。
其次，还需要查找，所以在里面加了GetContain和Insert操作。

建好树之后，就可以利用前缀树进行查找，遇到'.'的时候直接使用DFS进行遍历即可。

### 代码

```cpp
class WordDictionary
{
   public:
    struct node
    {
        node* mapNode[26];
        bool endFlag;
        node()
        {
            for (int i = 0; i < 26; i++) {
                mapNode[i] = NULL;
            }
            endFlag = false;
        }

        bool IsEnd()
        {
            return endFlag;
        }

        void SetEndFlag()
        {
            endFlag = true;
        }

        node* GetContain(char chr)
        {
            return mapNode[chr - 'a'];
        }

        node* InsertNextNode(char chr)
        {
            if (mapNode[chr - 'a'] == NULL) {
                mapNode[chr - 'a'] = new node();
            }
            return mapNode[chr - 'a'];
        }
    };
    /* * Initialize your data structure here. */
    WordDictionary()
    {
        headerNode = new node();
    }

    /* * Adds a word into the data structure. */
    void addWord(string word)
    {
        node* tempNode = headerNode;
        for (auto item : word) {
            tempNode = tempNode->InsertNextNode(item);
        }
        tempNode->SetEndFlag();
    }

    /* * Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return searchWithWord(headerNode, word, 0);
    }

    bool searchWithWord(node* headerNode, string& word, int index)
    {
        if (index == word.size()) {
            if (headerNode->IsEnd()) {
                return true;
            }
            return false;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (headerNode->mapNode[i] != NULL && searchWithWord(headerNode->mapNode[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        }

        node* nextNode = headerNode->GetContain(word[index]);
        if (nextNode == NULL) {
            return false;
        }
        return searchWithWord(nextNode, word, index + 1);
    }

   private:
    node* headerNode;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
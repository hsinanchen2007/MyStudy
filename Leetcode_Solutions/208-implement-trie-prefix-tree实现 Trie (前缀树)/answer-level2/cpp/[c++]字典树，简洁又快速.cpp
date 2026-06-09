### 解题思路
站在各位大佬的肩膀上

### 代码

```cpp
class Trie {
public:
    /** Initialize your data structure here. */
    Trie():isStr(false),next(branchNum, nullptr){
    }
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        Trie * root = this;
        for(const auto & w: word)
        {
            if(root->next[w-'a']  == nullptr)
                root->next[w-'a'] = new Trie();
            root = root->next[w-'a'];
        }
        root->isStr = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        auto node = locate(word);
        return node && node->isStr; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string & prefix) {
        return locate(prefix) ;
    }
private:
    Trie * locate(const string & prefix)
    {
        Trie *root = this;
        for(const auto& w : prefix)
        {
            if(root->next[w -'a'] == nullptr)
                return nullptr;
            root = root->next[w -'a'];
        }  
        return root;     
    }

private:
    static const int branchNum=26;
    bool isStr;
    vector<Trie *> next;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
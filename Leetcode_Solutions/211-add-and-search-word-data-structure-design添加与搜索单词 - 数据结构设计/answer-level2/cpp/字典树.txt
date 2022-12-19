### 解题思路
- 关键是如何处理.
- 暴力搜索所有子串

### 代码

```cpp
class WordDictionary {
struct Trie{
    bool is_end = false;
    Trie* next[26] = {nullptr};
    void insert(string word){
        Trie* t = this;
        for(auto c:word){
            if(t->next[c-97] == nullptr) t->next[c-97] = new Trie();
            t = t->next[c-97];
        }
        t->is_end = true;
    }
    bool search(string word){
        Trie* t = this;
        for(int j = 0; j<word.size(); ++j){
            int c = word[j] - 97;
            if(word[j] == '.'){
                for(int i=0; i<26; ++i){
                    if(t->next[i] != nullptr && t->next[i]->search(word.substr(j+1, word.size() - j - 1))) return true;
                }
                return false;
            }//检测所有后续字符串
            if(t->next[c] == nullptr) return false;
            t = t->next[c];
        }
        return t->is_end;
    }
}; // 字典树
public:
    Trie* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
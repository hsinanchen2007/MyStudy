```cpp []
class Trie {
    Trie* Node[26];
    bool is_end;
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i=0;i<26;i++) Node[i]=NULL;
        is_end=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* now=this;
        for(char chr:word){
            int idx=chr-'a';
            if(now->Node[idx]==NULL) now->Node[idx]=new Trie();
            now=now->Node[idx];
        }
        now->is_end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* now=this;
        for(char chr:word){
            int idx=chr-'a';
            if(now->Node[idx]==NULL) return false;
            now=now->Node[idx];
        }
        return now->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* now=this;
        for(char chr:prefix){
            int idx=chr-'a';
            if(now->Node[idx]==NULL) return false;
            now=now->Node[idx];
        }
        return true;
    }
};
```


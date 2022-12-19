### 解题思路
map,效率很低哈哈哈

### 代码

```cpp
class Trie {
public:
    map<string,int> mp;
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        mp[word]++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(mp.count(word)) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len=prefix.size();
        for(auto s=mp.begin();s!=mp.end();s++){
            if(s->first.size()>=len&&memcmp(&s->first[0],&prefix[0],len)==0) return true;
        }
        return false;
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
构建一个26叉树，分别表示字母a-z.当遇到'.'时，表示任何一个字母，遍历26个子树。
```
class WordDictionary {
    static const int SIZE = 26;
    bool isEnd;
    WordDictionary *children[SIZE];
    bool search(WordDictionary *node, string &word){
        for(int i=0; i<word.length(); ++i){
            if (node==NULL) return false;
            if (word[i]=='.'){
                string part = word.substr(i+1);
                for(int j=0; j<SIZE; ++j)
                    if (search(node->children[j], part)) return true;
                return false;
            }
            else node = node->children[word[i]-'a'];
        }
        return node && node->isEnd;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        for(int i=SIZE; i--; children[i]=NULL);
        isEnd = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *node = this;
        for(const auto &ch:word){
            if(node->children[ch-'a']==NULL) node->children[ch-'a'] = new WordDictionary();
            node = node->children[ch-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(this, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```

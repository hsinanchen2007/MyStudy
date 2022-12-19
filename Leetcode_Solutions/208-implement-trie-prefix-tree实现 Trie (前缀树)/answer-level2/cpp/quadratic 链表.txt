### 解题思路
此处撰写解题思路

### 代码

```cpp
const int alphebatCount = 26;
struct TrieNode{
    TrieNode* child[alphebatCount];
    bool isEndOfWord;
    TrieNode(){
        isEndOfWord = false;
        for (int i = 0; i < alphebatCount; ++i) {
            child[i] = nullptr;
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */


    TrieNode* root;
    Trie(){
        root = new TrieNode;
    };

    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.empty()){
            return;
        }
        TrieNode* myNode = root;
        for (int i = 0; i < word.size(); ++i) {
            int tmpIndex = word[i] - 'a';
            if(myNode->child[tmpIndex] == nullptr){
                myNode->child[tmpIndex] = new TrieNode;
            }
            myNode = myNode->child[tmpIndex];
        }
        myNode->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* myNode = root;
        for (int i = 0; i < word.size(); ++i) {
            int tmpIndex = word[i] - 'a';
            if(myNode->child[tmpIndex] == nullptr){
                return false;
            }
            myNode = myNode->child[tmpIndex];
        }
        if(myNode->isEndOfWord == false){
            return false;
        }
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* myNode = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int tmpIndex = prefix[i] - 'a';
            if(myNode->child[tmpIndex] == nullptr){
                return false;
            }
            myNode = myNode->child[tmpIndex];
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
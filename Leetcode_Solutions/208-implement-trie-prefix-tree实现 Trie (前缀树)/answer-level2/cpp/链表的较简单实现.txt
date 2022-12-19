使用递归可以更简单的实现Trie，代码量较少。
```
struct node {
    node *ch[26];
    bool isEnd;
    node();
    void insert(const string &s, int i);
    bool search(const string &s, int i);
    bool startsWith(const string &s, int i);
};
node::node() : isEnd(false) { memset(ch, NULL, sizeof ch); }
void node::insert(const string &s, int i = 0) {
    if (!ch[s[i] - 'a']) ch[s[i] - 'a'] = new node();
    if (i == s.size() - 1) { ch[s[i] - 'a']->isEnd = true; return; }
    return ch[s[i] - 'a']->insert(s, i + 1);
}
bool node::search(const string &s, int i = 0) {
    if (!ch[s[i] - 'a']) return false;
    if (i == s.size() - 1) return ch[s[i] - 'a']->isEnd;
    return ch[s[i] - 'a']->search(s, i + 1);
}
bool node::startsWith(const string &s, int i = 0) {
    if (!ch[s[i] - 'a']) return false;
    if (i == s.size() - 1) return true;
    return ch[s[i] - 'a']->startsWith(s, i + 1);
}
class Trie {
public:
    node *rt;
    /** Initialize your data structure here. */
    Trie() {
        rt = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        return rt->insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return rt->search(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return rt->startsWith(prefix);
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

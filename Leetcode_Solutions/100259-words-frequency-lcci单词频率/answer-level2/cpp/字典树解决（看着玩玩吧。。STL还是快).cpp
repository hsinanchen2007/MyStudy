暴力字典树，，算了算复杂度过得去。。但是确实太慢了。。。内存虽然小了点但是速度不敢恭维。。。
直接把单词建字典树，节点记录书名出现次数，总是效率不高最坏的话 接近 book.size() * book[i].size()
```
struct TrieNode {
    unordered_map<char, TrieNode*> ch;
    int ct;
    TrieNode() {
        ch.clear();
        ct = 0;
    }
};
class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        root = new TrieNode();
        for (auto word : book) {
            Insert(word);
        }
    }
    
    int get(string word) {
        auto now = root;
        for (auto c : word) {
            if (!now->ch.count(c))
                return 0;
            now = now->ch[c];
        }
        return now->ct;
    }
private:
    TrieNode* root;
    void Insert(string str) {
        auto now = root;
        for (auto c : str) {
            if (!now->ch.count(c)) {
                now->ch[c] = new TrieNode();
            }
            now = now->ch[c];
        }
        now->ct ++;
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
```

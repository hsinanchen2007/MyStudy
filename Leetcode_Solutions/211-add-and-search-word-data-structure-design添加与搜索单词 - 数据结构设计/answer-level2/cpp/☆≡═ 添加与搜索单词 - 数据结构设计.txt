1. 把加入的单词保存在字典树中。
2. 查找时，在字典树中逐层匹配字符。
3. 非通配符 '.' 在对应子树匹配剩下的字符。
4. 遇到'.'对每个子树递归匹配，寻找一个匹配的子树。
```
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        is_end = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(const string& word) {
        WordDictionary *cur = this;
        for (const auto& ch : word) {
            if (!cur->links.count(ch)) cur->links.insert({ch, new WordDictionary()});
            cur = cur->links[ch];
        }
        cur->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string& word) {
        return search(word.begin(), word.end(), this);
    }
    
private:
    bool is_end;
    unordered_map<char, WordDictionary*> links;
    
    template<typename ForwardIt>
    bool search(ForwardIt first, ForwardIt last, WordDictionary* root) {
        if (first == last) {
            return root->is_end;
        } else if (*first == '.') {
            for (auto& link : root->links)
                if (search(1 + first, last, link.second))
                    return true;
        } else if (root->links.count(*first)) {
            return search(1 + first, last, root->links[*first]);
        }
        return false;
    }
};
```

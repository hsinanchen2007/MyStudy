### 解题思路
# 前缀树
前缀树是基础，做此题来了解前缀树：[208.实现前缀树](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)
[208.实现前缀树题解（适合初学者）](https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/)
此题与前缀树相比，仅查询部分复杂了一些，加上了'.'，可以表示任何一个字母。
查询部分可以用递归回溯解决，其余部分和实现前缀树完全一样。
**因此只解释查询的做法，最后给出完整代码。**
# 思路：递归回溯
1. **递归边界**：**单词长度为1时：**
    - **若是字母，则查找next[]中对应位置是否不为空并且是结束标志；**
    - **若是'.'，则查找next[]中是否存在非空并且是结束标志者。**
    ```
    if(word.size()==1) {  //边界
        if(isalpha(word[0])) {  //是单词
            if(node->next[word[0]-'a'] && node->next[word[0]-'a']->isEnd)
                return true;
            return false;
        }
        else {  //是 . 
            for(int i=0; i<26; i++)
                if(node->next[i] && node->next[i]->isEnd)
                    return true;
            return false;
        }
    }
    ```

2. **递归思路**：
只处理word字符串的第一个元素，剩下元素递归解决，两种情况：
    1. **首元素是字母:**
        1. 若相应的next[]不空，则word[0]匹配成功，继续匹配word剩下的串    
        ```
        if(node->next[word[0]-'a'])
            return searchWord(node->next[word[0]-'a'], word.substr(1, word.size()-1));
        ```
        2. 否则匹配失败，返回false
        ```
        else
            return false;
        ```
    2. **首元素是'.':**
        若存在next[]不空，则word[0]（也就是 . ）匹配成功，继续匹配word剩下的串。因为.是任意匹配，所以要尝试所有的next[]，直到返回值为true。 循环结束则意味着没有匹配的，返回false
        ```
        bool b;
        for(int i=0; i<26; i++) {      
            if(node->next[i]){
                b = searchWord(node->next[i], word.substr(1, word.size()-1));
                if(b)   return true;
            }
        }
        return false;
        ```


### 代码

```cpp
class WordDictionary {
public:
    bool isEnd;
    WordDictionary* next[26];
    /** Initialize your data structure here. */
    WordDictionary() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* p = this;
        for(auto c : word) {
            if(p->next[c-'a'] == nullptr) 
                p->next[c-'a'] = new WordDictionary();
            p = p->next[c-'a'];
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(this, word);
    }
    bool searchWord(WordDictionary* node, string word) {
        if(word.size()==1) {  //边界
            if(isalpha(word[0])) {
                if(node->next[word[0]-'a'] && node->next[word[0]-'a']->isEnd)
                    return true;
                return false;
            }
            else {
                for(int i=0; i<26; i++)
                    if(node->next[i] && node->next[i]->isEnd)
                        return true;
                return false;
            }
        }
        else {
            if(isalpha(word[0])) {
                if(node->next[word[0]-'a'])
                    return searchWord(node->next[word[0]-'a'], word.substr(1, word.size()-1));
                else
                    return false;
            }
            else {
                bool b;
                for(int i=0; i<26; i++) {      
                    if(node->next[i]){
                        b = searchWord(node->next[i], word.substr(1, word.size()-1));
                        if(b)   return true;
                    }
                }
                return false;
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
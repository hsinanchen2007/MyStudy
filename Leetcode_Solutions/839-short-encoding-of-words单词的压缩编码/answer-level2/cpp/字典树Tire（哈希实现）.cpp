### 解题思路
单词倒过来存到字典树里，这样同样的后缀就可以存在一起

### 代码

```cpp
struct node{
    bool isWord;
    unordered_map<char,node *> next;
    node():isWord(false){}
};
class Trie{ 
private:
    node* root;
public:
    Trie(){root = new node;}
    void insert(const string& word){
        node* cur = root;
        for(int i = word.size() - 1;i >= 0;--i){
            char c = word[i];
            if(cur->next.find(c) == cur->next.end())
                cur->next[c] = new node;
            cur = cur->next[c];
        }
        cur->isWord = true;
    }

    int cal_length(const string& word){
        node* cur = root;
        int len = 0;
        for(int i = word.size() - 1;i >= 0;--i){
            char c = word[i];
            cur = cur->next[c];
            len += 1;
        }
        bool flag = cur->isWord; //防止重复的单词
        cur->isWord = false;
        return (cur->next.empty() && flag) ? len + 1 : 0;
        //如果没有下一个，说明不是某个后缀，而是一个新单词，这是长度还要加上#
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if(words.empty()) return 0;
        Trie * trie = new Trie;
        for(int i = 0;i < words.size();++i){
            trie->insert(words[i]);
        }
        int ans = 0;
        for(int i = 0;i < words.size();++i)
            ans += trie->cal_length(words[i]);
        return ans;
    }
};
```
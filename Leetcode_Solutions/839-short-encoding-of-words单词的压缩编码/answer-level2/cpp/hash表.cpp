### 解题思路
此处撰写解题思路
用一个unordered_set<string>将words数组存下来，
然后遍历每个字符串，遍历其子串是否在res数组中出现，出现就用erase方法将其抹去，
最后把剩下的每个字符串的长度+1再相加。（每个字符串都是唯一的，且没有重复后缀的，+1是加上分隔符#的长度）
### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> res(words.begin(),words.end());
        for(const string& word: words){
            for(int k = 1; k < word.size(); k++){
                res.erase(word.substr(k));
            }
        }
        int ans = 0;
        for(const string& word: res){
            ans += word.size() + 1;
        }
        return ans;
    }
};

字典树：
存储时必须逆序存储，并且得按照字符串长度从大到小的顺序，否则会出现有后缀相同的字符串也能被插入。
class TrieNode{
public:
    bool isEnd;
    TrieNode* next[26];
public:
    TrieNode(){
    isEnd = false;
    memset(next,0,sizeof(next));
}
};
class Trie{
    TrieNode* root;
public:
    Trie(){
        this->root = new TrieNode();
    }
    int insert(string word){
        TrieNode* cur = root;
        int len = word.length();
        bool flag = false;
        for(int i = len - 1; i >= 0; i--){
            if(cur->next[word[i] - 'a'] == NULL){
                cur->next[word[i] - 'a'] = new TrieNode();
                flag = true;
            }
            cur = cur->next[word[i] - 'a'];
        }
        return flag ? len + 1 : 0;
    }
};
class Solution {
public:
    static bool less(const string& s1, const string& s2){
        return s1.length() > s2.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        int len = 0;
        Trie* cur = new Trie();
        sort(words.begin(),words.end(),less);
        for(int i = 0; i < words.size(); i++){
            len += cur->insert(words[i]);
        }
        return len;
    }
};




```
### 解题思路
![leetcode.png](https://pic.leetcode-cn.com/f605d17135ef9e4a130834ccf9a206a02c1fcca299b41a053315a8dd7aaab917-leetcode.png)
思想：只要长度匹配不上就白搭
所以建立了key为长度的map
同时也建立了key为string的map,这样查找不带通配符的字符串的时间复杂度为O(1)，
对于待通配符的字符串就在长度对应的字符串列表里查找是否有match的字符串即可。
事实证明不光速度挺快，内存消耗的也挺少 =w=

### 代码

```cpp
class WordDictionary {
public:
    vector<string> list;
    map<string,int> m;
    map<int,vector<string>> len2str;
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    bool match(string a,string b){
        for(int i = 0 ;i < a.size() ;i++){
            if(b[i]!='.'&&b[i]!=a[i])return false;
        }
        return true;
    }
    bool findre(string word){
        vector<string> l = len2str[word.size()];
        int llen = l.size();
        if(llen == 0)return false;
        for(int i = 0 ;i < llen ;i++){
            if(match(l[i],word))return true;
        }
        return false;
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
        list.push_back(word);
        m[word] = 1;
        len2str[word.size()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.find('.')>=0){
            return findre(word);
        }
        else return m[word]==1;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
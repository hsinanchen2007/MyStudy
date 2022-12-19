本人总结的前缀树习题：[leetcode刷题总结之前缀树](https://blog.csdn.net/qq_43152052/article/details/101109415)

起初使用前缀树导致内存爆了，后改用后缀树顺利通过，不过就是时间有点吃不消了。（后缀树就是每个字符串反向后建立的前缀树，本质还是前缀树。）

**解题思路：**
* 1）从words中提取word，将word反向，建立后缀树。
* 2）在查询的时候，我们将每个字符保存在一个字符串中，每次每个字符都插入到该字符串的首部。然后我们直接在后缀树中查找该字符串的最短前缀能否表示成一个字符串就行了。
```
//前缀树模板
class Trie{
private:
    bool is_string=false;
    Trie* next[26]={nullptr};
public:
    Trie(){}
    void insert(string& word){
        Trie* root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->is_string=true;
    }
    bool startsWith(string& word){
        Trie* root=this;
        for(const auto& w:word){
            if(root->next[w-'a']!=nullptr){
                root=root->next[w-'a'];
                if(root->is_string)return true;//最短前缀是一个单词，就直接返回true
            }
            else return false;
        }
        return false;
    }
};

class StreamChecker {
private:
    Trie* root;
    string word;
public:
    StreamChecker(vector<string>& words) {
        root=new Trie();
        for(auto word:words){
            reverse(word.begin(),word.end());
            root->insert(word);
        }
    }
    
    bool query(char letter) {
        Trie* note=root;
        word.insert(word.begin(),letter);
        return note->startsWith(word);
    }
};

```
***
应下面网友的提醒，将代码优化后，时间效率大大提升了。

**字符串单词word每次在尾部添加字符，在查询的时候，由后向前查询即可**，优化版如下：
```
class Trie{
private:
    bool is_string=false;
    Trie* next[26]={nullptr};
public:
    Trie(){}
    void insert(string& word){
        Trie* root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->is_string=true;
    }
    bool startsWith(string& word){
        Trie* root=this;
        for(int i=word.size()-1;i>=0;--i)
        {
            if(root->next[word[i]-'a']!=nullptr){
                root=root->next[word[i]-'a'];
                if(root->is_string)return true;
            }
            else return false;
        }
        return false;
    }
};

class StreamChecker {
private:
    Trie* root;
    string word;
public:
    StreamChecker(vector<string>& words) {
        root=new Trie();
        for(auto word:words){
            reverse(word.begin(),word.end());
            root->insert(word);
        }
    }
    
    bool query(char letter) {
        Trie* note=root;
        //word.insert(word.begin(),letter);
        word.push_back(letter);
        //string temp(word.rbegin(),word.rend());
        return note->startsWith(word);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
```
两次提交记录如下：
![image.png](https://pic.leetcode-cn.com/a84cf3b13396ee39b6cf1fd99e48a5227f55c37773fe3d3ef825823bed310d8c-image.png)

由题意可知，本题使用前缀树最为合适不过了。
* 1）首先分析一下题意：**从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成**。这句话的意思是说，最长单词的每个字符在前缀中对应的节点都能表示一个字符串，还有一点需要注意的是在最长单词相等时，我们需要选择字典序小的单词，明白这两点，接下来解题就是套用板子了。板子：[这里](https://blog.csdn.net/qq_43152052/article/details/100586268)。
* 2）然后就是两次遍历字符串数组，第一次遍历是建立前缀树，第二次遍历是寻找最长单词了。

**代码如下：**
```cpp
class Trie{
private:
    bool is_string;
    Trie *next[26];
public:
    Trie(){
        is_string=false;
        memset(next,0,sizeof(next));
    }
    
    void insert(string word){
        Trie *root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->is_string=true;
    }
    
    bool search(string word){
        Trie *root=this;
        for(const auto& w:word){
            //当节点值存在时，判断该节点是否表示为一个字符串，不是的话，直接返回false,否则继续循环;当节点值不存在时直接返回false
            if(root->next[w-'a']==nullptr||root->next[w-'a']->is_string==false)return false;
            root=root->next[w-'a'];
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        if(words.size()==0)return "";
        Trie* root=new Trie();
        //第一次遍历，建立前缀树
        for(const auto& word:words)
            root->insert(word);
        string result="";
        //第二次遍历，寻找最长单词
        for(const auto& word:words){
            if(root->search(word))
            {
                if(word.size()>result.size())result=word;//更新最长单词
                else if(word.size()==result.size()&&word<result)result=word;//长度相等的单词，取字典序小的单词
            }    
        }
        return result;
    }
};
```

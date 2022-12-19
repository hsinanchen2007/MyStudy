前缀树模板：[这里](https://blog.csdn.net/qq_43152052/article/details/100586268)
这里简单讲解一下搜索单词，例如寻找`catsdogcats`，当i为2时，我们在前缀树发现cat是一个子单词，然后开始search(sdogcats)，然而发现这个并不是子单词，那就证明以cat作为分界词就错了。我们继续for循环，然后匹配到cats时，在递归匹配dogcats，直到for循环结束！
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
    
    bool search(string word,int index,int count){
        Trie *root=this;//每次从根节点开始寻找
        for(int i=index;i<word.size();++i){
            if(root->next[word[i]-'a']==nullptr)return false;//word的某个字符不在前缀树中
            root=root->next[word[i]-'a'];
            if(root->is_string){//到达某个单词尾
                if(i==word.size()-1)return count>=1;//count的数量至少为2个，若遍历到最后只有一个单词，则count的值还是为0
                //已前count位的单词作为分解词继续匹配下一个单词,下个单词满足count才能返回ture,否则继续寻找下一个分界单词
                if(search(word,i+1,count+1))return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie *root=new Trie();
        for(const auto &word:words){
            root->insert(word);
        }
        vector<string> result;
        for(const auto &word:words){
            if(root->search(word,0,0))
                result.push_back(word);
        }
        return result;
    }
};
```

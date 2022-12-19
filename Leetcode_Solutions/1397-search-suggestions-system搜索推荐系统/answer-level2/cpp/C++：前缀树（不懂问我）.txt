**前言：**
此题一看就是前缀树，贴了板子，然后修修改改，正AC时，居然到12.01了，我的排名又下降了，我好菜啊呜呜呜（哭有什么用。

**题解：**
1）[前缀树板子](https://blog.csdn.net/qq_43152052/article/details/101109415)，需要改动。插入单词：每个节点还需要存放单词。查找前缀：直接返回单词前缀的前3个单词（不足三个单词的，返回全部单词）。
2）遍历`products`，建立前缀树。
3）遍历`searchWord`，加入前缀词。

**代码如下：**
```cpp
class Trie
{
private:
    Trie *next[26]={nullptr};
    vector<string> words;
public:
    Trie(){}

    void insert(const string& word)//插入单词
    {
        Trie *root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
            root->words.push_back(word);
        }
    }

    vector<string> startsWith(string prefix)//查找前缀
    {
        Trie* root=this;
        for(const auto& p:prefix){
            if(root->next[p-'a']==nullptr)return {};
            root=root->next[p-'a'];
        }
        if(root->words.size()<=3)return vector<string> (root->words.begin(),root->words.end());
        else return vector<string> (root->words.begin(),root->words.begin()+3);
    }    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        Trie *root=new Trie();
        for(const auto& product:products)
            root->insert(product);
        vector<vector<string>> result;
        for(int i=0;i<searchWord.size();++i)
        {
            result.push_back(root->startsWith(searchWord.substr(0,i+1)));
        }
        return result;
    }
};
```

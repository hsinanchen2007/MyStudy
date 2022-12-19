### 解题思路
![image.png](https://pic.leetcode-cn.com/c8068a4b7d641222a866f64096b8b4df1497429c57d6de2672a6b8932ce4e5d6-image.png)
参考208题-实现前缀树的思路，实现了后缀树的功能。
主要的一点就是在将字符串插入前缀树的过程中，从字符串的末尾往前遍历，这样就能将前缀树完美地变成后缀树了。
然后就是遍历后缀树，将树的叶子节点的深度逐个相加，就好了。
看一下代码吧

### 代码

```cpp
struct Trie
{
    Trie *child[26];//只有26个英文小写字母
    Trie()
    {
        for(int i=0;i<26;i++)
            child[i]=nullptr;
    }
};

class Solution {
public:
    void insert(Trie* root,string word)
    {
        Trie* tmp=root;
        for(int i=word.length()-1;i>=0;i--)//从末尾往前遍历字符串的字符
        {
            if( tmp->child[word[i]-'a']==NULL ) 
                tmp->child[word[i]-'a'] = new Trie();
            tmp=tmp->child[word[i]-'a'];
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        Trie * root=new Trie();//树根
        for(int i=0;i<words.size();i++)
        {
            insert(root,words[i]);//插入
        }
        int res=0;
        d(root,res,1);//求结果
        return res;
    }
    void d(Trie *root,int &res,int deep)
    {   
        bool f=true;
        for(int i=0;i<26;i++)
        {
            if(root->child[i]!=NULL)
            {
                d(root->child[i],res,deep+1);//递归调用，记得深度+1
                f=false;
            }
        }
        if(f) res+=deep;//叶子节点，结果加上当前深度
    }
};
```
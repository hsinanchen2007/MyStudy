### 解题思路
此处撰写解题思路
代码区就是我对全部前缀树的看法和理解,
总的来说不难,
也就是链表处理而已.
但是涉及的思想是很值得思考和玩味的.
首先,它的搜索是很节省时间的,这比n或者logn显然是要好的多.
大致上搜索时间只跟所搜索的内容的长度有关.可以想象,对大多数集合的元素,如若满足那种可以拆分的性质,那么前缀树既可以缩短我们的空间,也可以缩短我们的时间.而且还便于组织和管理.
### 代码

```cpp
class node{
    public:
    node* a[26];
    int sign;
    node(){
        for(int i=0;i<26;i++) a[i]=NULL;
        sign=0;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    node* root;
    Trie() {
        root=new node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* ind=root;
        for(int i=0;i<word.length();i++)
        {
            if(ind->a[word[i]-'a'])ind=ind->a[word[i]-'a'];
            else {
                node*temp=new node;
                ind->a[word[i]-'a']=temp;
                ind=temp;
            }
        }
        ind->sign=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* ind=root;
        for(int i=0;i<word.length();i++)
        {
            if(!ind->a[word[i]-'a']) return false;
            ind=ind->a[word[i]-'a'];
        }
        return ind->sign==1;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* ind=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!ind->a[prefix[i]-'a']) return false;
            ind=ind->a[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
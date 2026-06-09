**方法1：动态规划**
因为是正则表达式，我第一反应想到 [10.正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/) 
所以就想到了用 [unordered_set集合](https://blog.csdn.net/qq_32172673/article/details/85160180) 
1. 在addWord(string word)中采用集合set存储每一个单词
2. 在search(string word)中采用动态规划思想去匹配每一个单词
3. 在第2步中可加一点优化：先比较当前字典中单词*i的长度和word的长度
*但是以上还是会超时(gg)*
采用测试案例一看，测试案例是加了一堆长度大于1的单词，然后不断搜索"."
4. 所以就想到了再加一个是set用来存储单词表中的长度
5. 这样在search(string word)时，如果word的长度在辅助集合helper_size中没有找到，也就不用一个一个比较了

**方法2：前缀树/Trie/字典树**
想起了 [208.实现Tire(前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)
稍微修改下208题代码即可
1. 在search(string word)中
2. 如果遍历时发现了'.'，那么就用当前树节点的所有子节点的值来替代这个'.'，构建很多个新的word
3. 将新的word重新执行search(string 新的word)即可

稍微举个例子吧
假设一颗字典树
addWord(string "ba");
addWord(string "bc");
![字典树.png](https://pic.leetcode-cn.com/c933690218ab3e259d9f173520ed1e407150bbb6c84de4579d2d7f43ee31f996-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191215162109.png)

1. 假设要找的是"b."即search(string "b.");
2. 已经匹配了'b',发现当前字符是'.'
3. 去找'b'节点的所有子节点，也就是'a'和'c'
4. 将word中的当前的'.'替换成'a'和'c'
5. 即两个新的word为"ba"、"bc"
6. 将他们重新执行search即可
7. 也就是search(string "ba");search(string "bc");

**代码**

1. dp
```
class WordDictionary {
    unordered_set<string> helper_set;
    unordered_set<int> helper_size;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        //因为是unordered_set，所以重复字符不会重复加入
        helper_set.insert(word);
        helper_size.insert(word.size());
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int word_size=word.size();
        if (helper_size.find(word_size)==helper_size.end())
            return false;
        bool judge;
        for (unordered_set<string>::iterator i=helper_set.begin();i!=helper_set.end();++i)
        {
            judge=true;
            if ((*i).size()==word_size)
            {
                for (int j=0;j<word_size;++j)
                    if (word.at(j)!='.' && word.at(j)!=(*i).at(j))
                    {
                        judge=false;
                        break;
                    }
                if (judge)
                    return true;
            }
        }
        return false;
    }
};
```

2. Trie
```
class WordDictionary {
private:
    bool is_leaf=false;
    //数组初始化只有全为0才能这样写
    WordDictionary* arc[26]={NULL};
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* p=this;
        for (char &i:word)
        {
            if (p->arc[i-'a']==NULL)
                p->arc[i-'a']=new WordDictionary;
            p=p->arc[i-'a'];
        }
        p->is_leaf=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary* p=this;
        int word_size=word.size(),i;
        for (i=0;i<word_size;++i)
        {
            if (word.at(i)=='.')
                break;
            if (p->arc[word.at(i)-'a']==NULL)
                return false;
            else
                p=p->arc[word.at(i)-'a'];
        }
        if (i<word_size)
        {
            vector<char> helper_replace;
            for (int j=0;j<26;++j)
                if (p->arc[j]!=NULL)
                    helper_replace.push_back('a'+j);
            if (!helper_replace.empty())
            {
                bool judge=false;
                for (char &j:helper_replace)
                    if (!judge)
                        judge=this->search(string(word.begin(),word.begin()+i)+j+string(word.begin()+i+1,word.end()));
                    else
                        return true;
                return judge;
            }
            else
                return false;
        }
        return p->is_leaf;
    }
};
```

如果觉得好的可以去[个人github仓库给个星星](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution)，还有不懂可以评论区问
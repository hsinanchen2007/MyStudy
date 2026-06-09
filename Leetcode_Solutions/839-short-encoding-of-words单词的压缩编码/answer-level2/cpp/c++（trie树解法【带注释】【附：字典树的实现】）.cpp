- 思路：
  - 对字典中的每个单词倒着插入字典树，树中所有叶子结点的单词的长度加一之和，即为所求
- 时间复杂度：
  - o(sum(word_len_i))
- 空间复杂度：
  - o(len(char)*sum(word_len_i))
- 结果:
  - 用时：83%（88ms）
  - 内存：12%
```cpp []
class Solution {
    struct TrieNode{
        TrieNode *child[26];
    };
    void insert(TrieNode* root, string word){
        TrieNode* now=root;
        for(char chr:word){
            int idx=chr-'a';
            if(now->child[idx]==NULL) now->child[idx]=new TrieNode();
            now=now->child[idx];
        }
    }
    int count(TrieNode* root, int depth){ 
        /* count函数解读，返回值（表示该结点下层数值之和）为两类：
            如果是叶子结点，则返回结点深度（单词长度）+1
            如果是非叶结点，则返回子结点返回值之和（即收集下层的数值，也是该结点为根的树的所有叶结点之和）
        */
        bool is_leaf=true;
        int sum=0;
        for(int i=0;i<26;i++){
            if(root->child[i] != NULL){
                sum += count(root->child[i], depth+1);
                is_leaf = false;
            }
        }
        if(is_leaf) return depth+1; //深度即为单词长度，加上‘#’结束符，返回 单词长度+1
        return sum;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(string word:words){ //因为要检测后缀，所以单词要倒着插入trie树
            reverse(word.begin(), word.end());
            insert(root, word);
        }
        return count(root, 0);
    }
};
```
- 字典树实现 - [208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)
```cpp []
class Trie {
    Trie* Node[26];
    bool is_end;
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i=0;i<26;i++) Node[i]=NULL;
        is_end=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* now=this;
        for(char chr:word){
            int idx=chr-'a';
            if(now->Node[idx]==NULL) now->Node[idx]=new Trie();
            now=now->Node[idx];
        }
        now->is_end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* now=this;
        for(char chr:word){
            int idx=chr-'a';
            if(now->Node[idx]==NULL) return false;
            now=now->Node[idx];
        }
        return now->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* now=this;
        for(char chr:prefix){
            int idx=chr-'a';
            if(now->Node[idx]==NULL) return false;
            now=now->Node[idx];
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
> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------


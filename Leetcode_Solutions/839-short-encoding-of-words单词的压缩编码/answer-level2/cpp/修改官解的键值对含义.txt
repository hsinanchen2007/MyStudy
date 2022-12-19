### 解题思路
学习管解之下， 做出的修改
区别在于 键值对<trieNode*, int> 的int 的含义变为 trieNode* 所在的深度（词的长度）

实际上吧，还不如官解，因为这里需要在插入节点的时候 计算深度
而 官解利用的词的下标，进而利用 word.size() 来获取词的长度
两者之间时间、空间复杂度没有区别

仅仅作为拓展想法而已

### 代码

```cpp
// 模仿官方题解
class trieNode {
    trieNode * children[26];                        // 26个字母对于的子树
   
public:

    int cntChildren;
    trieNode (){
        for (int i=0; i<26; i++){
            children[i] = NULL;
        }

        cntChildren = 0;                            // 子节点数量 0 
    }

    trieNode * rootChild(char ch){                  
                                                    // 基于当前节点，字符所在的子树的root
        if (children[ch - 'a'] == NULL){            // 之前没有建立该子节点
            children[ch - 'a'] = new trieNode();        // 新建子节点
            cntChildren ++;                         // 子节点数 +1
        }

        return children[ch - 'a'];                   // 返回该字符应在的子树的root           
    }                      
};


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        trieNode *head = new trieNode();            // 创建一个字典树 头
        unordered_map<trieNode*,int> wordRoot;      // 每个词对应的子树的 root 指针,以及深度

        for (int i=0; i<words.size(); i++){
            trieNode *child = head;                 // 插入的初始位置当然是 头了
            int deep = 0;
            for (int j=words[i].size()-1; j>=0; j--){// 每个词逆序的每个字符
               child = child->rootChild(words[i][j]);
               // 基于当前的子树位置，根据字符获取下一个子树的root
               deep ++;                              // 记录深度（词长度）
              
            }
            wordRoot[child] = deep;
        }


        // 计算：每个词对应的是叶子节点，则+words[i].size() +1;
        // !! 一个节点对应的词不是唯一的！ 可以是多个相同的词
        // 所以，以词对应节点是不合理的==》私用键值对来就行

        // 或者，遍历字典树，同样也是唯一的
        int len = 0;
        auto pw = wordRoot.begin();
        for (; pw != wordRoot.end(); pw++) if (pw->first->cntChildren == 0){
            len += pw->second  +1;   
        }
        
        return len;

    }
};

/*
// 官方题解： 字典树
class TrieNode{
    TrieNode* children[26];
public:
    int count;
    TrieNode() {                                // 所有孩子节点初始化为 空； 计数为0
        for (int i = 0; i < 26; ++i) children[i] = NULL;
        count = 0;
    }
    TrieNode* get(char c) {                     // 获取以字符c结尾的的子树
        if (children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();                // 创建一棵字典树（已经初始化了）
        unordered_map<TrieNode*, int> nodes;

        for (int i = 0; i < (int)words.size(); ++i) {   // 对每一个词
            string word = words[i];
            TrieNode* cur = trie;
            for (int j = word.length() - 1; j >= 0; --j)// 逆序的每一个字符
                cur = cur->get(word[j]);                // 逐渐深入的插入子树
            nodes[cur] = i;                             // 每个词的首字符所在的子树的root
        }

        int ans = 0;
        for (auto& [node, idx] : nodes) {               // 每个词所在的子树
            if (node->count == 0) {                     // 叶子节点
                ans += words[idx].length() + 1;
            }
        }
        return ans;
    }
};

*/




/*  方法一 暴力法：
class Solution {
public:

    bool isInOther(int w, vector<string>& words){
        string wd = words[w];
        int j;

        for (int i=0; i<words.size(); i++) if (words[i].size() >= wd.size() && w != i){
            // 比目标词 长的词中
            int begin = words[i].size() - wd.size() ;
            
            for (j=0; j<wd.size(); j++){
                if (words[i][begin+j] != wd[j])
                    break;
            }
            if (j == wd.size()){
                if (begin == 0)         // 连长度都是一样的 ==》完成相同
                    words[i] = "";      // 删掉这个词，避免重复
                else
                    return true;        // 不是完成相同的词，而是包含关系
            }
                
        }

        return false;
    }

    int minimumLengthEncoding(vector<string>& words) {
        int len = 0;
        // 如果词被包含在其他词的尾串里，则该词被忽略掉
        // 否则 len += 词.size()+1;
        for (int i=0; i<words.size(); i++){
            if (!isInOther(i, words))
                len += words[i].size() +1;
        }

        return len;
    }

};

*/
```
### 解题思路
方法1：后缀查找（先查找长度大的string， 短string为长string的子串）
1、自定义排序compare函数，按string长度大小递减排序；
2、遍历words数组，如果word#不在str中，将word#加入str中；最后str的长度为返回值。

方法2：字典树
1、定义字典树，并在构造函数中初始化成员变量
2、遍历字符串数组，逆序构造每个字符串的字典数，并统计当前字符出现的次数；同时将字典树的叶子节点和对应的字符串索引加入map。
3、遍历map，统计所有叶子节点cnt为0的长度。

### 代码

```cpp
class Trie{
private:
    Trie *child[26];
public:
    int cnt;
    Trie(){
        cnt = 0;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }

    Trie* next(char ch){
        if(child[ch - 'a'] == NULL){
            child[ch - 'a'] =  new Trie();
            cnt++;
        }

        return child[ch - 'a'];
    }
};


class Solution {
public:

int minimumLengthEncoding(vector<string>& words) {
    Trie* root = new Trie();
    unordered_map<Trie*, int> umap;
    for(int index = 0; index < words.size(); index++){
        Trie* cur = root;
        string word = words[index];
        for(int i = word.size() - 1; i >= 0; i--){
            cur = cur->next(word[i]);
        }
        umap[cur] = index;
    }
    
    int total = 0;
    /*for(auto& it : umap){
        if(it.first->cnt == 0){
            total += 1 + words[it.second].size();
        }
    }*/
    for(auto& [node, index]: umap){
        if(node->cnt == 0)
            total += 1 + words[index].size();
    }
    
    return total;
}
    /*bool static compare(const string& str1, const string& str2)  
    {  
        return str1.size() > str2.size();  
    }

    int minimumLengthEncoding(vector<string>& words) {
        int total = 0;
        sort(words.begin(), words.end(), compare);
        string str = "";
        for(string word: words){
            if(str.find(word + "#") == str.npos){
                total += word.size() + 1;
                str.append(word + "#");
            }
        }
        
        return total;
    }*/
};
```
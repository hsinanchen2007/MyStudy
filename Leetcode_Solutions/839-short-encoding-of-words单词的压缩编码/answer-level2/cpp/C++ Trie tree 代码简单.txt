### 解题思路
1. 创建Trie Tree
2. 如果全新创建或是和原来不同的word, 计算length + 1
2. 如果在之前的扩展,记录并清除之前的isEnd 标记， 计算新word和原有的差值


### 代码

```cpp
struct TrieNode{
    TrieNode* next[26] = {nullptr};
    bool isEnd = false;
};

class Solution {
public:
    int len = 0;
    TrieNode root;
    bool addNode(string& word){
        if(word.empty()){
            return true;
        }
        TrieNode* node = &root;
        bool iscnt = false;
        int cnt = 0;
        int preEnd = 0;
        for(int i=word.length()-1; i>=0; i--){
         
            int index = word[i]-'a';
            if(node->next[index] == nullptr){
                 node->next[index] = new TrieNode();
                 iscnt = true;
            }
            if(node->isEnd == true){
                preEnd = cnt;
                node->isEnd = false;
            }
             node = node->next[index];
             cnt++;
        }
        
        if(iscnt){
            node->isEnd = true;
            if(preEnd == 0)
                len += word.length() + 1 ;
            else
                len += word.length() - preEnd;
        }
        return true;
    };

    int minimumLengthEncoding(vector<string>& words) {
        if(words.empty()){
            return 0;
        }        
        for(auto& s:words){
            addNode(s);
        }        
        return len;
 
    }
};
```
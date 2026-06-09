### 解题思路
- 核心思路：遍历字符串，在hashmap中存储各字符与字符出现的次数，第二次遍历字符串，返回第一个只出现一次的字符
- 执行用时：296 ms, 在所有 C++ 提交中击败了5.22%的用户
- 内存消耗：10.9 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int>umap;
        for(int i=0;i<s.size();i++){
            if(umap.find(s[i])!=umap.end()){
                umap[s[i]]+=1;
            }
            else{
                umap[s[i]]=1;
            }
        }
        for(auto c:s){
            if(umap[c]==1)return c;
        }
        return ' ';
    }
};
```
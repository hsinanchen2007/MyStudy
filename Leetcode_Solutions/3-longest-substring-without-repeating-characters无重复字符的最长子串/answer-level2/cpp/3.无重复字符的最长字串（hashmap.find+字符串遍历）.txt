### 解题思路
代码要点：设置i，j遍历字符串，随j递增找i和j之间有无重复字符
特例：空串和单字符
提示：此代码过于麻烦，t=880(>6.47%)，m=142.7MB(>8.45%)
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0||s.size()==1){
            return s.size();
        }
        int result=0;
        unordered_map<char,int>umap;
        int i=0;
        umap[s[i]]=i;    
        for(int j=i+1;j<s.size();j++){
            if(umap.find(s[j])!=umap.end()){
                result=max(result,j-i);
                i=j=umap.find(s[j])->second+1;
                umap.clear();
                umap[s[i]]=i;
            }
            else{
                umap[s[j]]=j;
            }
        }
        if(result>umap.size()){
            return result;
        }
        else{
            return umap.size();
        }
    }
};
```
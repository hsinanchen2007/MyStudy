### 解题思路
核心要点：维护i、j这个滑动窗口，找窗口内有无j位置处的字符j'，有则i=j'+1（前提是j'得在窗口内！这是hashmap无删除操作的关键）。
执行用时 :20 ms, 在所有 C++ 提交中击败了60.51%的用户
内存消耗 :10.1 MB, 在所有 C++ 提交中击败了57.51%的用户
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0;
        unordered_map<char,int>umap;      
        for(int i=0,j=0;j<s.size();j++){
            if(umap.find(s[j])!=umap.end()){
                i=i>umap.find(s[j])->second?i:umap.find(s[j])->second+1; 
            }
            result=max(result,j-i+1);
            umap[s[j]]=j;
        }
        return result;
    }
};
```
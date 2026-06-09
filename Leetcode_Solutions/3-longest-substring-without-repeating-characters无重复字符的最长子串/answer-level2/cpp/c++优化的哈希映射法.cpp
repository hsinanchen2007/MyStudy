### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        int left=0,right=0;
        int sublen=0;
        unordered_map<char,int> hash;
        for(right;right<s.size();right++){
            if(hash.count(s[right])){
                left=max(hash[s[right]],left);
            }
            sublen=max(right-left+1,sublen);
            hash[s[right]]=right+1;
        }
        return sublen;
        
    }
};
```
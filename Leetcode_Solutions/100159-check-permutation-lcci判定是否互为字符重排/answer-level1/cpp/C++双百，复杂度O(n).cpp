### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        int a[26]={};
        int b[26]={};
        for(char c:s1){
            a[c-'a']++;
        }
        for(char c:s2){
            b[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
};
```
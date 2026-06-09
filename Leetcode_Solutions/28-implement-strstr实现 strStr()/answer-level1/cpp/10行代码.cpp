### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.size()<needle.size())
            return -1;
        int lenhay=haystack.size();
        int lennee=needle.size();
        for(int i=0;i<=lenhay-lennee;++i){
            if(haystack.substr(i,lennee)==needle)
                return i;
        }
        return -1;
    }
};
```
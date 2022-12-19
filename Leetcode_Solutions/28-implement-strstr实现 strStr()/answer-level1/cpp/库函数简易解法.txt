执行用时 :4 ms
在所有 C++ 提交中击败了93.31%的用户
内存消耗 :9.2 MB, 
在所有 C++ 提交中击败了76.60%的用户
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack.find(needle)!=haystack.npos)return haystack.find(needle);
        return -1;
    }
};
```

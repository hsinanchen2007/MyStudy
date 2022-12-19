### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)!=string::npos)
        return haystack.find(needle);
        else
        return -1;
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        auto it = haystack.find(needle);
        if(it == haystack.npos)
        return -1;
        return it;
    }
};

```
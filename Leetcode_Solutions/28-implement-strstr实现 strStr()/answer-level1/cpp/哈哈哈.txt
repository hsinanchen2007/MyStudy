### 解题思路
皮一下也很开心，当然这种字符串匹配一般用KMP较好。
![捕获.PNG](https://pic.leetcode-cn.com/d2ba970a8a9e902582168464892bf12abb1c79107a9cdc5ab11af0041f57f71f-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) == string::npos)return -1;
        else return haystack.find(needle);
    }
};
```
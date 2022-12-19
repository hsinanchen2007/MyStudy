### 解题思路
![image.png](https://pic.leetcode-cn.com/05266918cf86ce9b00c591bde31c68ad4097dc687fe4d31a5fae934908baa436-image.png)
### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();

        if(!size2) return 0;

        for(int i = 0 ; i <= size1 - size2 ; i++) {
            if(haystack.substr(i , size2) == needle) return i;
        }

        return -1;
    }
};
```
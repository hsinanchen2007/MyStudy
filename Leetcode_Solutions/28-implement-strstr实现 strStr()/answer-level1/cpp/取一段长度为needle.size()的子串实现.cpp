### 解题思路
在haystack中取一段长度为needle.size()的子串，依次与needle比较就可以了。

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(needle.size() > haystack.size()) return -1;
        for (int i=0;i <= haystack.size()-needle.size();i++){
            if(haystack.substr(i,needle.size()) == needle)
                return i;
        }
        return -1; 
    }
};
```
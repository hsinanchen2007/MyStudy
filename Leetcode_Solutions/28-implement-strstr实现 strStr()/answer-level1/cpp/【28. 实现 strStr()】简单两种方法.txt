## 思路一：暴力
### 代码
```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        int index = -1;
        if (len2 == 0) {
            return 0;
        }
        int i = 0, j = 0;
        while (i < len1 && j < len2) {     
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                i = i - j + 1;
                j = 0;
            }            
        }
        if (j == len2) {
            index = i - j;
        } 
        return index;
    }
};
```

## 思路二：库函数
### 代码
```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int index = haystack.find(needle);
        return index;
    }
};
```


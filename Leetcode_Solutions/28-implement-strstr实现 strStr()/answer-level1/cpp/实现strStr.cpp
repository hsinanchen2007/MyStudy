### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(),len2 = needle.size();
        for(int i = 0;i < len1 - len2 + 1;i++){
            int j = 0;
            while(j < len2){
                if(haystack[i+j] != needle[j])
                    break;
                j++;
            }
            if(j == len2)
                return i;
        }
        return -1;
    }
};
```
# 解题思路
4ms，和暴力解速度差不多？
![image.png](https://pic.leetcode-cn.com/ff0dfbeaf7fb8cc93c13d4fbf341c2c4031438d7e6a7803dc9337a6acee1de1a-image.png)
# 代码
```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        vector<int> next(needle.size());
        next[0] = -1;
        int j = -1;
        for (size_t i = 1; i < needle.size(); i++)
        {
            while(j != -1 && needle[j+1] != needle[i]) {
                j = next[j];
            }
            if(needle[j+1] == needle[i]) j++;
            next[i] = j;
 
        }
        int i = 0;
        j = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            while(j != -1 && haystack[i] != needle[j + 1]){
                j = next[j];
            }
            if(haystack[i] == needle[j + 1]) j++;
            if(j == needle.size() - 1) {
                return i - j;
            }

        }
        
        return -1;
    }
};
```
### 解题思路
KMP 主要是计算匹配失败后，目标字符串的下一个起始匹配点
对于 next 数组的计算，主要是通过当前目标字符串位置前面的最长公共前缀和后缀
对于计算最长公共前缀和后缀的过程，其实也是一个子串的匹配过程
next 数组中首元素为 -1

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int src_len = haystack.size();
        int dst_len = needle.size();

        if (dst_len == 0)
            return 0;
        if (dst_len > src_len)
            return -1;
        
        vector<int> next(dst_len, 0);
        next[0] = -1;
        int e = 0;
        int f = -1;
        while (e < dst_len - 1) {
            if (f == -1 || needle[e] == needle[f]) {
                f++;
                e++;
                next[e] = f;
            } else {
                f = next[f];
            }
        }

        int i = 0, j = 0;
        while (i < src_len && j < dst_len) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == dst_len)
            return i - j;
        else
            return -1;
    }
};
```
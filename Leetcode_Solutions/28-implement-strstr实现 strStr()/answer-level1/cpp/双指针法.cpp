### 解题思路
用两个指针来指向needle和haystack，如果匹配则两个指针都指向下一个，如果不匹配，则将needle指针变回指向第一个字符，haystack指针指向上一次第一个匹配字符的下一个字符。

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0; // i指向haystack，j指向needle
        int H = haystack.length();
        int N = needle.length();
        // 先处理特殊情况
        if(N == 0) return 0;
        if(H < N) return -1;
        // 处理正常情况
        while(j<H)
        {
            if(needle[i] == haystack[j])
            {
                i++;
                j++;
                // 判断遍历到边界的情况
                if(i>=N) return j-N;
            }
            else
            {
                j = j-i+1;
                i = 0;
            }
        }
        return -1;
    }
};
```
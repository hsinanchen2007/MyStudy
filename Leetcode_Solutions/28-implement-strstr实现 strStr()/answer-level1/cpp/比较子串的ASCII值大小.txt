### 解题思路
难度简单的话，采用暴力法，时间复杂度O(M*N)。
采用KMP方法的话，时间复杂度O(M+N)，但是难度应该为困难吧。
网上看到一种思路，通过计算haystack中对应长度的ASCII值之和，与needle进行比较，如果两者相等的话，再进行每一个字符的比较。时间复杂度应该在上述两种方法之间，也比较容易理解。

### 代码

```cpp
class Solution {
public:

//  计算模式串的ASCII值大小比较
    int strStr(string haystack, string needle)
    {
        int len1 = haystack.size();
        int len2 = needle.size();
        int haystack_count = 0;
        int needle_count = 0;

        if(len2 == 0) return 0;
        if(len1 < len2) return -1;

        for(int i = 0; i < len2; i++)
        {
            needle_count += (int)needle[i];
        }

        for(int m = 0; m < len2; m++)
        {
            haystack_count += (int)haystack[m];
        }

        for(int j = 0; j <= len1-len2; j++)
        {
            if(j > 0)
            {
                haystack_count = haystack_count - haystack[j-1] + haystack[j+len2-1];
            }
            
            if(haystack_count == needle_count)
            {
                for(int n = 0; n < len2; n++)
                {
                    if(haystack[j+n] != needle[n])
                    {
                        break;
                    }
                    else if(n == len2 - 1)
                    {
                        return j;
                    }
                }
            }
        }
        return -1;       
    }
};
```
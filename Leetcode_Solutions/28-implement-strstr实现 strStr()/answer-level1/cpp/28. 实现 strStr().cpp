### 解题思路
题目虽然简单，由于轻敌了，没考虑清楚；罗列如下
1. 特殊情况的处理
2. c++库函数
3. 列举两个串的情况：
haystack    needle  结果
空串        空串     0
空串        非空     -1
非空        空串     0
非空        非空     调用库函数find

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        bool bHay = haystack.empty();
        bool bNeed = needle.empty();

        //特殊情况1：needle为空串，则返回0，即空串是任意字符串的子串
        if (bNeed)
        {
            return 0;
        }
        else if (bHay)  //特殊情况2：needle非空串 且 haystack空串，则返回-1
        {
            return -1;
        }

        int i = (int)haystack.find(needle);
        return i;
    }
};
```
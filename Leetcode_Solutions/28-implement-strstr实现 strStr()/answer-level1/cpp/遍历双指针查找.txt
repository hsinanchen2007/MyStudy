### 解题思路
如果采用暴力搜索的方式，也可以计算，但是时间和内存消耗会比较大（136ms, 645M）
本题目采用双指针的方案

![双指针.png](https://pic.leetcode-cn.com/eebc7762c579aa73f8813c00c719bacbaf54eb469835473dfc918b6f5eef0d1c-%E5%8F%8C%E6%8C%87%E9%92%88.png)
1. idx1从haystack开始遍历，如果haystack的当前字母和needle的一致，则两者(idx1,idx2)均+1；
2. 如果idx2的大小和needle的长度一致，说明查找结束，返回idx1 - idx2即可；
3. 如果出现idx1和idx2不一致，则将idx1重新从idx1 - idx2 开始遍历，并将idx2设置为0



### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (needle.length() == 0)
            return 0;
        int idx1 = 0;
        int idx2 = 0;
        while(idx1 < haystack.length())
        {
            if (haystack[idx1] == needle[idx2])
            {
                idx2 ++;
                idx1 ++;
                if (idx2 == needle.length())
                    return idx1 - idx2;
            }
            else
            {
                idx1 = idx1 - idx2 + 1;
                idx2 = 0;
            }
        }
        return -1;
    }
};
```
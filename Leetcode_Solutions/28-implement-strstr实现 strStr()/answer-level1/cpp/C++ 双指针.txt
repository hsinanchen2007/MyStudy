### 解题思路
双指针，当第一次字符相等时，记录开始匹配的位置。一旦不等了，重置为匹配位置的下一个值继续循环
![image.png](https://pic.leetcode-cn.com/0079a804f1f45ce45a68cbf02e5c9bec56c5d15299cd75bcd91f1152acb332a9-image.png)

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
        {
            return 0;
        }
        if(haystack.empty())
        {
            return -1;
        }

        int p1 = 0;
        int p2 = 0;
        int startPos = -1;
        while(p1 < haystack.size() && p2 < needle.size())
        {
            if(haystack[p1] == needle[p2])
            {
                if(startPos == -1)
                    startPos = p1;
                p1++;
                p2++;
            }
            else
            {
                if(startPos > -1)
                {
                    p1 = startPos;
                    startPos = -1;
                }
                p1++;
                p2 = 0;
            }
        }

        if(p2 == needle.size() && startPos > -1)
        {
            return startPos;
        }
        else{
            return -1;
        }
    }
};
```
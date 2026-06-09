### 解题思路
求字串问题，双指针大法

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        while(haystack[i]!='\0'&&needle[j]!='\0')
        {
            if(needle[j]==haystack[i])//判断是否相等
            {
                j++;
                i++;
            }
            else//不相等退回开始的位置，i+1，j=0;
            {
                i = i - j + 1;
                j = 0;
            }

        }
        if(j == needle.length())//j为步长
        return  i-j;
        return -1;
    }
};
```
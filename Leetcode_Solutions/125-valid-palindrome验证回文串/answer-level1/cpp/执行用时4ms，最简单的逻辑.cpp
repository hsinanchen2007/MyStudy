### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/8e446375df07d93830ce5e519663ce1a6be5ce7b6ea68baf965df8b423c513f5-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;  //从前向后
        int j = s.size() - 1;  //从后向前
        while (i < j)
        {
            bool IisDorA = isdigit(s[i]) || isalpha(s[i]);  //s[i]是否为字母或数字
            bool JisDorA = isdigit(s[j]) || isalpha(s[j]);  //s[j]是否为字母或数字
            if (IisDorA && JisDorA)
            {
                //前后都是字母或者数字
                //不是对应关系则返回false，否则i继续向后查找，j继续向前查找
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
                ++i; 
                --j;
            }
            else if (IisDorA)
            {
                //s[i]是数字或字母，s[j]不是
                --j;
            }
            else if (JisDorA)
            {
                //s[j]是数字或字母，s[i]不是
                ++i;
            }
            else
            {
                //s[i]和s[j]都不是数字和字母
                ++i;
                --j;
            }
        }
        return true;
    }
};
```
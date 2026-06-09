### 解题思路
方法一：暴力求解
用两个叠加for循环，拿这个字符和后面的字符比较，时间复杂度是O[N]
方法二：字符哈希
设置一个数组char[128],用两个分开的for循环，时间复杂度是O[N],空间复杂度O[1]

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        //边界条件
        if(s.empty())
        {
            return ' ';
        }
        //设置一个字符哈希:字符哈希可以统计字符出现的频率
        int char_set[128]={0};
        char temp=129;
        
        for(int i=0;i<s.size();i++)
        {
            char_set[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(char_set[s[i]]==1)
            {
                return s[i];
            }
        }
        return ' ';
    }
};
```
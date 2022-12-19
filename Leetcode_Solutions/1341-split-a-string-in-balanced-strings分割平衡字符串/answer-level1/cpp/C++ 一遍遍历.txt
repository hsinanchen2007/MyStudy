### 解题思路
注意题目的意思是分割，并不丢弃任何一个字符！！！
一遍遍历，当两字符的计数器相等时，平衡字符串的计数器加一。

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int c1=0;
        int c2=0;
        int c=0;
        for(int i=0;i!=s.size();i++)
        {
            if(s[i]=='L')
            {
                c1++;
                if(c1==c2)
                {c++;c1=0;c2=0;}
            }
            else
            {
                c2++;
                if(c1==c2)
                {c++;c1=0;c2=0;}
            }
        }
        return(c);
    }
};
```
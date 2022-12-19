### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        int count=0;
        bool flag=false;
        for(int i=s.size() - 1;i>=0;i--)
        {
           if(flag &&s[i] == ' ') break;
           if(s[i] != ' ')
           {
               flag = true;
               count++;
           }
        }
        return count;
    }
};
```
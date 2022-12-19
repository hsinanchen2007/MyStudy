### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prelen = 0;
        int curlen = 1;
        int count=0;
        for(int i = 1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                curlen++;
            }
            else
            {
                prelen = curlen;
                curlen = 1;
            }
            if(prelen>=curlen)
            {
                count++;
            }
        }
        return count;
    }
};
```
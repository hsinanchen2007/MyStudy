### 解题思路
不要复杂化
### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0)
            return 0;
        if(haystack.length()==0)
            return -1;
        if(needle.length()>haystack.length())
            return -1;
        int j=0;
        for(int i=0;i<=haystack.length()-needle.length();i++)
        {
            for(j=0;j<needle.length();j++)
            {
                if(needle[j]!=haystack[i+j])
                {
                     break;
                } 
                else
                {
                    continue;
                }
            }
            if((j==needle.length()&&(needle[j-1]==haystack[i+j-1])))
                return i;
        }
        return -1;
    }
};
```
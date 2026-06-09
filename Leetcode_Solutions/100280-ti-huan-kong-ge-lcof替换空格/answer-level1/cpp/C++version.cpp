### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
    int i,j=0;
    string res;
    for(i=0 ; i<s.length() ; i++)
    {
        if(s[i] != ' ')
            res += s[i];
        else
            res += "%20";
    }
    return res;
    }
};
```
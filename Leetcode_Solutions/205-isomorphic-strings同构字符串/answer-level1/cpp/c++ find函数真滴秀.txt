### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s.find(s[i])!=t.find(t[i]))
            {
                return false;
            }
        }
        return true;
    }
};
```
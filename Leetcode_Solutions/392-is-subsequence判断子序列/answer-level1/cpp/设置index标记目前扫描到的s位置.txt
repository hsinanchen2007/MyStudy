### 解题思路
没啥说的，思路明确

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for(int i = 0 ; i < t.length() ; ++i)
        {
            if(t[i] == s[index])
            {
                index++;
            }
        }
        if(index == s.length())
        return true;
        else
        return false;
    }
};
```
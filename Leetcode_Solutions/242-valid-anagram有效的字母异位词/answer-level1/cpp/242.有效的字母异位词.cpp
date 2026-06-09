### 解题思路
**前提**：字符串只包含26个字符

所以，利用一个长度为26的数组，字符串s中的字符对应位置加1，t中的字符对应的位置减1，最后判断数组是否为全0即可

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int counts[26]{};
        
        for(int i=0;i<s.size();i++)
        {
            counts[(int)s[i]-int('a')] ++;
            counts[(int)t[i]-int('a')] --;
        }
        for(int i=0;i<26;i++)
        {
            if (counts[i])
                return false;
        }
        return true;
    }
};
```
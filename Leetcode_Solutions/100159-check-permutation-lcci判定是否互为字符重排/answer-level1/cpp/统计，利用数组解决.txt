### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        int chs1[26] = {0};
        int chs2[26] = {0};
        for(char c : s1)
        {
            chs1[c - 'a']++;
        }
         for(char c : s2)
        {
            chs2[c - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(chs1[i] != chs2[i])
                return false;
        }
        return true;
    }
};
```
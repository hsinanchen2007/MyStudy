### 解题思路
s的计数用+，t的计数用-，结束计数时如果计数表里有残存数字，则返回false。计数表清零则返回true。
当扩展到unicode（或者别的任何类型），直接用unordered_map来进行计数即可

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> n(26);
        for(int i = 0; i < s.size(); i++)
        {
            n[s[i] - 'a']++;
            n[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++)
            if(n[i])
                return false;
        return true;
    }
};
```
### 解题思路

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, bool> hash;
        for(int i = 0 ; i < s.length() ; ++i)
        {
            if(mp.find(s[i]) == mp.end())
            {
                if(hash[t[i]])
                    return false;
                mp[s[i]] = t[i];
                hash[t[i]] = true;
            }
            else if(mp[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
```
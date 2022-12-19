### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash_s[26]={0};
        int hash_t[26]={0};
        if(s.size()!=t.size())
        {
            return false;
        }
        for(int i=0;i<s.size();i++)
        {
            hash_s[s[i]-'a']++;
            hash_t[t[i]-'a']++;
        }
        for(int j=0;j<26;j++)
        {
            if(hash_s[j]!=hash_t[j])
            {
                return false;
            }
        }
        return true;
    }
};
```
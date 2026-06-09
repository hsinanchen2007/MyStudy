```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp;
        for(auto n:magazine)
        {
            mp[n]++;
        }
        for(auto n:ransomNote)
        {
            if(mp[n]-- <= 0)
            {
                return false;
            }
        }
        return true;
    }
};
```

```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for(auto letter:magazine)
            hash[letter-'a']++;
        for(auto letter:ransomNote)
        {
            if (hash[letter-'a'] == 0)
                return false;
            else
                hash[letter-'a']--;
        }
        return true;
    }
};
```

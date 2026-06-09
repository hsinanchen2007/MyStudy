```
class Solution {
public:
    bool isAnagram(string s, string t) {
        int sn[26];
        int tn[26];
        memset(sn, 0, sizeof(sn));
        memset(tn, 0, sizeof(tn));
        for(auto c:s)
        {
            sn[c-'a']++;
        }
        for(auto c:t)
        {
            tn[c-'a']++;
        }
        return memcmp(sn, tn, sizeof(sn)) == 0;
    }
};
```

```
class Solution {
public:
    string reverseVowels(string s) {
        int mp[128] = {0};
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        mp['A'] = 1;
        mp['E'] = 1;
        mp['I'] = 1;
        mp['O'] = 1;
        mp['U'] = 1;
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            if(mp[s[i]] == 1 && mp[s[j]] == 1)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else
            {
                if(mp[s[i]] == 0)
                {
                    i++;
                }
                if(mp[s[j]] == 0)
                {
                    j--;
                }
            }
        }
        return s;
    }
};
```

```
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        int i=0;
        for(i=0; i<order.size(); i++)
        {
            mp[order[i]] = i;
        }
        for(i=0; i<words.size()-1; i++)
        {
            if(!cmp(words[i], words[i+1], mp))
            {
                return false;
            }
        }
        return true;
    }
    bool cmp(string s1, string s2, map<char, int>& mp)
    {
        int i=0;
        int len = min(s1.size(), s2.size());
        for(i=0; i<len; i++)
        {
            if(s1[i] != s2[i])
            {
                return mp[s1[i]] < mp[s2[i]];
            }
        }
        return s1.size()<s2.size();
    }
};
```

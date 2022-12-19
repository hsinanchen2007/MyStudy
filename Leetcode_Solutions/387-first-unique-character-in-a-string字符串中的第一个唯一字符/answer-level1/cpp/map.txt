```
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp;
        int m;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]+=1;
        }
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]==1)
                return i;
        }
        return -1;
    }
};
```

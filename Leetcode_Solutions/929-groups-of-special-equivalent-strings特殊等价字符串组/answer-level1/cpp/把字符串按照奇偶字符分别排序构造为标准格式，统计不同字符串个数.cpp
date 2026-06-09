```
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        map<string, int> mp;
        string us;
        for(string s:A)
        {
            us = uniform(s);
            mp[us]++;
        }
        return mp.size();
    }
    string uniform(string s)
    {
        string s1;
        string s2;
        for(int i=0; i<s.size(); i++)
        {
            if(i%2 == 0)
            {
                s1 += s[i];
            }
            else
            {
                s2 += s[i];
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        s1 += '-';
        return s1+s2;
    }
};
```

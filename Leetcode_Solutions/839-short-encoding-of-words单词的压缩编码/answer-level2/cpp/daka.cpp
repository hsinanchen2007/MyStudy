```
class Solution {
public:
    static bool cmp(string a, string b)
    {
        return a.size() > b.size();
    }

    int minimumLengthEncoding(vector<string>& words)
    {
        sort(words.begin(), words.end(), cmp);
        string s = words[0] + "#";
        for(int i = 1; i < words.size(); i++)
        {
            int pos = s.find(words[i]);
            if(pos == s.npos || s[pos+words[i].size()] != '#')
                s += words[i] + "#";
        }
        return s.size();
    }
};
```

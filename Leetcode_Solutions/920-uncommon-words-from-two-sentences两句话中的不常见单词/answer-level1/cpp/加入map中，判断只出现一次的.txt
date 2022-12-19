```
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> mapa;
        vector<string> res;
        for(string s:split(A))
        {
            mapa[s]++;
        }
        for(string s:split(B))
        {
            mapa[s]++;
        }
        for(auto s:mapa)
        {
            if(s.second == 1)
                res.push_back(s.first);
        }
        return res;
    }
    vector<string> split(string s)
    {
        vector<string>res;
        int i = 0;
        int j = 0;
        while(i<s.size())
        {
            while(j<s.size() && isalpha(s[j]))
                j++;
            res.push_back(s.substr(i, j-i));
            i = ++j;
        }
        return res;
    }
};
```

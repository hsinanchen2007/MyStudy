```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        string k;
        vector<vector<string>> ret;
        for(auto s:strs)
        {
            k = s;
            sort(k.begin(), k.end());
            mp[k].push_back(s);
        }
        for(auto m:mp)
        {
            ret.push_back(m.second);
        }
        return ret;
    }
};
```

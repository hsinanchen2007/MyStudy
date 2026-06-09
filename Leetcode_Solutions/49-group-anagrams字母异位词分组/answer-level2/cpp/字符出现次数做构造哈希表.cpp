```C++ []
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ret;
        int n = strs.size();
        unordered_map<string, vector<string> >mp;
        unordered_map<string, vector<string> > ::iterator it;
        mp.clear();
        ostringstream oss;
        for (int i = 0; i < n; i++) {
            int cnt[30] = {0};
            oss.str("");
            for (int j = 0; j < strs[i].size(); j++) {
                cnt[strs[i][j] - 'a'] ++;
            }
            for (int i = 0; i < 26; i++) {
                oss << cnt[i] << ":";
            }
            string key = oss.str();
            it = mp.find(key);
            if (it == mp.end()) {
                mp[key] = vector<string> {strs[i]};
            }
            else {
                it->second.push_back(strs[i]);
            }
        }
        for (it = mp.begin(); it != mp.end(); it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
};
```

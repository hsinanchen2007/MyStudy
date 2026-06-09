效率一般，将就看吧
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<map<char, int>> v;
        map<map<char, int>, vector<string>> m;
        vector<vector<string>> res;
        for (const auto &str : strs)
        {
            map<char, int> tmp = get_map(str);
            if (find(v.cbegin(), v.cend(), tmp) == v.cend()) {
                v.push_back(tmp);
            }
                m[tmp].push_back(str);
        }
        for (auto it = m.cbegin(); it != m.cend(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
    
    map<char, int> get_map(const string &str) const
    {
        map<char, int> m;
        for (const auto &i :str) {
            ++m[i];
        }
        return m;
    }
};
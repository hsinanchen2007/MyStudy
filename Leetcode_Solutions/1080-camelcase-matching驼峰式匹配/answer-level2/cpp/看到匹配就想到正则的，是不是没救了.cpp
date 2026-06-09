```
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern)
    {
        if (pattern.empty()) {
            return{};
        }
        string regPat;
        for (int i = 0; i < pattern.length(); i++) {
            regPat += "[a-z]*";
            regPat.push_back(pattern[i]);
        }
        regPat += "[a-z]*";
        regex reg(regPat);
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            if (regex_match(queries[i], reg)) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
```

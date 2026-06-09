```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> h;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            h[temp].push_back(strs[i]);
        }
        for(auto i : h)
            res.push_back(i.second);
        return res;
    }
};
```

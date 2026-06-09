```
class Solution {
    vector<vector<int>> res;
public:
    void helper(unordered_map<int, int>& cnt, vector<int>& t, int j) {
        int k = 0;
        for(auto it = cnt.begin(); it != cnt.end(); it++, k++) {
            if(j-- > 0) continue;
            if(it->second > 0) {
                it->second--;
                t.push_back(it->first);
                res.push_back(t);
                helper(cnt, t, k);
                t.pop_back();
                it->second++;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        res.push_back(vector<int>());
        unordered_map<int, int> maps;
        for(int i:nums) maps[i]++;
        vector<int> t;
        helper(maps, t, 0);
        return res;
    }
};
```

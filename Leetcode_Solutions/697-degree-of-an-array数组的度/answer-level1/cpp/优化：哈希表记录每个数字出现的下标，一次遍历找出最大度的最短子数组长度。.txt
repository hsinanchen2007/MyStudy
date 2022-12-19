```
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        for (int i = 0; i< nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        
        int deg = 1;
        int res = INT_MAX;
        for (auto & i : m) {
            if (i.second.size() > deg) {
                deg = i.second.size();
                res = i.second.back() - i.second[0] + 1;
            } else if (i.second.size() == deg) {
                res = min(res, i.second.back() - i.second[0] + 1);
            }
        }
        
        return res;
    }
};
```

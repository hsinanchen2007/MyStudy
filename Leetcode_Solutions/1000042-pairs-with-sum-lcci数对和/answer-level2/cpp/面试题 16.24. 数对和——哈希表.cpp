```
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(auto& num : nums) {
            m[num]++;
        }
        vector<vector<int>> res;
        for(auto& num : nums) {
            int num2 = target - num;
            if((num2 == num && m[num] >= 2) || (num2 != num && m[num] && m[num2])) {
                res.emplace_back(vector<int>({num,num2}));
                m[num]--;
                m[num2]--;
            }
        }
        return res;
    }
};
```

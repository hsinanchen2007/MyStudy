```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s;
        for(int num:nums) {
            if(s.count(target-num)) return {num, target-num};
            else s.insert(num) ;
        }
        return {};
    }
};
```

Time 8ms, 95%
```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int> dict(nums.begin(),nums.end());
        return dict.count(target);
    }
};
```

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> tmp;
        for (int i = 0; i < n; ++i) {
            if (tmp.find(nums[i])!=tmp.end()) return true;
            tmp.insert(nums[i]);
            if (tmp.size() > k) {
                tmp.erase(nums[i - k]);
            }
        }
        return false;
    }
};
```

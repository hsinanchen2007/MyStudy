```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> hash;
        for (int i = 0; i < n; i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                return {target - nums[i],nums[i]};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
```
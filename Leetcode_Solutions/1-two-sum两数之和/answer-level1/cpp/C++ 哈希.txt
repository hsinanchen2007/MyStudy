```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int len = nums.size();
        for (int i=0;i<len;i++) {
            if (mp.count(nums[i]) != 0)
                return {mp[nums[i]],i};
            mp[target-nums[i]] = i;
        }
        return {-1,-1};
    }
};
```

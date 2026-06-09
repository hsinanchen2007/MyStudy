```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        first=first==nums.size()||nums[first]!=target?-1:first;
        int second=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        second=first==-1?-1:second-1;
        return {first,second};
        
        
    }
};
```

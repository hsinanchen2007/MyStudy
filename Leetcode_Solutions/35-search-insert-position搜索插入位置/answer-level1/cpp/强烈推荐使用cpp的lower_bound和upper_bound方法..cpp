```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto left=lower_bound(nums.begin(),nums.end(),target);
        auto right=upper_bound(nums.begin(),nums.end(),target);
        if(left==right)
        {
            return (right-nums.begin());
        }
        return (left-nums.begin());
    }
};
```

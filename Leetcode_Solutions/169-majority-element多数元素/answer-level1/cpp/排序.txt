```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums.size();
        return nums[l/2];


    }
};
```

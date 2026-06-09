```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>()); 
        nums.erase(unique(nums.begin(),nums.end()),nums.end());  
        int n = nums.size();
        if (n==0) return {};
        else if (n<3) return nums[0];
        else return nums[2];
    }
};
```

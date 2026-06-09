```
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = nums.size()-1;
        int mx1 = nums[0]*nums[1]*nums[i];
        int mx2 = nums[i]*nums[i-1]*nums[i-2];
        return max(mx1, mx2);
    }
};
```

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size(), left = 0, mid = 1, right = len - 1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        while (left < len-2) {
            if (mid >= right) {
                left++;
                while (left < len-2 && nums[left] == nums[left-1])
                    left++;
                mid = left + 1;
                right = len - 1;
            } else if (nums[left] + nums[mid] + nums[right] > 0) {
                    right--;
            } else if (nums[left] + nums[mid] + nums[right] < 0) {
                    mid++;
            } else {
                res.push_back({nums[left],nums[mid],nums[right]});
                while (right > 0 && nums[--right] == nums[right+1]);
                while (mid < right && nums[++mid] == nums[mid-1]);
            }
       }
        return res;
    }
};
```

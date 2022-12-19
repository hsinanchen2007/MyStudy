```C++
class Solution {
public:
    int helper(vector<int>& nums, vector<int>& ans, int pos, int leftProd) {
        if (pos == nums.size()) return 1;
        ans[pos] *= leftProd; // multiply Left product
        int rightProd = helper(nums, ans, pos + 1, leftProd*nums[pos]);
        ans[pos] *= rightProd; // multiply right product
        return rightProd*nums[pos];
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        helper(nums, ans, 0, 1);
        return ans;
    }
};
```
